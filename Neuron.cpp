#include "Neuron.h"


Neuron::Neuron():V_mem(0),nb_spikes(0),t_now(0),is_refr(0),buffer(static_cast<unsigned long>(ceil(D/h))+1,0.0),has_background(true)
{}
//neuron is initialized with the background noise
//for both constructor, buffer is initialized with a size of D+1 and each case initialized to 0

Neuron::Neuron(double v,bool background):V_mem(v),nb_spikes(0),t_now(0),is_refr(0),buffer(static_cast<unsigned long>(ceil(D/h))+1,0.0),
										 has_background(background)
{}


double Neuron::get_V_mem() const
{
	return V_mem;
}

vector<double> Neuron::get_V_Mem_step() const
{
	return V_mem_step;
}

int Neuron::get_nb_spikes() const
{
	return nb_spikes;
}

vector<double> Neuron::get_t_spikes() const
{
	return t_spikes;
}

double Neuron::get_t_now() const
{
	return t_now;
}

vector<double> Neuron::get_buffer() const
{
	return buffer;
}

double Neuron::get_weight() const
{
	return weight;
}

vector<int> Neuron::get_targets() const
{
	return targets;
}



bool Neuron::update_neuron(const unsigned int&n, const double& I)
{	
	bool has_spike(false);					
	
	int t_now_step = t_now/h;							//we work in time steps, so we convert the time in time steps
	
	random_device rd;
	mt19937 gen(rd());
	poisson_distribution<> rand_spikes(nu_ext*h);		//here to, we convert firing rate per ms into f.rate per step
														//firing rate per step is distributed in poisson's law
														
	for(unsigned int t_step=t_now_step;t_step<t_now_step+n;++t_step)
	{		
		V_mem_step.push_back(V_mem);					//at each step, V_mem is stored in V_mem_step
		
		if(V_mem >= V_thr)								//if potential exceed threshold, neuron becomes refractory
		{												//and the function returns true (it has spiked)
			++nb_spikes;
			t_spikes.push_back(t_step*h);
			is_refr = t_refr/h;						
			has_spike = true;
			V_mem = V_res;
		}
		
		if(is_refr > 0)									//during his refractory period, neuron's potential = 0
		{
			V_mem = V_res;				
			buffer[t_step%buffer.size()] = 0;
			--is_refr;
		}
		else	
		{
			if(has_background)						
			{	
				//we add potential given by random spikes	
				V_mem = V_mem*exp(-h/tau)+I*R*(1-exp(-h/tau))+buffer[t_step%buffer.size()]+rand_spikes(gen)*J_E; 
				//weight of rand spikes is J_E (excitatory)
				buffer[t_step%buffer.size()] = 0;
			}										
			else
			{
				V_mem = V_mem*exp(-h/tau)+I*R*(1-exp(-h/tau))+buffer[t_step%buffer.size()];
				buffer[t_step%buffer.size()] = 0;
			}								
		}						
	}
	t_now += n*h;		
	//t_now is updated	
	
	return has_spike;
}

void Neuron::receive_spike(const double& t_spike, const double& weight_donor)
{
	buffer[static_cast<unsigned long>(ceil((t_spike+D)/h))%buffer.size()] += weight_donor;
	//the spike is written with weight=weight_donor at t_spike+D so the neuron read it at t_spike+D 
}

void Neuron::connect(const int& target_id, const double& w)
{	
	targets.push_back(target_id);
	weight = w;
	//add a new target neuron and give weight of our neuron
}
	
