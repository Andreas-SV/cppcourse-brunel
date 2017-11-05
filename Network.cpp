#include "Neuron.h"
#include "Network.h"


Network::Network(int nb_neuron):neurons(nb_neuron),nb_neurons(nb_neuron),file_spike("Spikes.gdf",ios::out)
{}

Network::Network(vector<Neuron> new_neurons):neurons(new_neurons),nb_neurons(new_neurons.size()),file_spike("Spikes.gdf",ios::out)
{}



vector<Neuron> Network::get_neurons() const
{
	return neurons;
}

unsigned int Network::get_nb_neurons() const
{
	return nb_neurons;
}

vector<unsigned int> Network::get_neurons_id() const
{
	return neurons_id;
}



void Network::connection_for_12500_neurons()
{
	assert(nb_neurons == 12500);			//the network must have 12500 neurons to work
	
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> exci_id(0,9999);
	uniform_int_distribution<> inhi_id(10000,12499);
	//the first 10000 neurons are excitatory and the others are inhibitory
	
	for(unsigned int target_id(0);target_id<neurons.size();++target_id)
	{
		for(size_t n(0);n<C_E;++n)
		{
			neurons[exci_id(gen)].connect(target_id,J_E);// 1000 randoms excitatory neurons with weight J connect to the target
		}
		
		for(size_t n(0);n<C_I;++n)
		{
			neurons[inhi_id(gen)].connect(target_id,-g*J);// 250 randoms inhibiitory neurons with weight -g*J connect to the target       
		}
	}
}

void Network::connect(const unsigned int& source_id,const unsigned int& target_id,const double& w)
{
	assert(source_id < nb_neurons and source_id >= 0);
	assert(target_id < nb_neurons and target_id >= 0);
	
	neurons[source_id].connect(target_id,w);
}


void Network::update_network(const double& dt)
{
	for(double t=net_clock;t<net_clock+dt;t+=h)
	{	
		for(unsigned int i=0;i<neurons.size();++i)
		{	
		
			bool spike(false);								
			spike = neurons[i].update_neuron(1);		//for each step, it update the neuron by 1 step
														//and tells us if the neuron has spiked 
			if(spike)							
			{
				cout<<"Spike from neuron "<<i+1<<endl;					
				cout<<"at "<<neurons[i].get_t_spikes().back()<<" ms"<<endl;
				file_spike<<neurons[i].get_t_spikes().back()<<" "<<i+1<<"\n"; //t_spike and neuron index is stored in file_spike
				
				for(size_t j(0);j<neurons[i].get_targets().size();++j)
				{	
					assert(neurons[i].get_targets()[j]<12500 and neurons[i].get_targets()[j]>=0);
					neurons[neurons[i].get_targets()[j]].receive_spike(t,neurons[i].get_weight());
					//we make sure that the target index is between 0 and 12500-1 (it is only helpful if the network contains 12500 neurons
				}					
			}
		}
	}	
	net_clock += dt;
	//net_clock is updated
}

