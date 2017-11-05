#ifndef NETWORK_H
#define NETWORK_H

#include "Neuron.h"

class Network
{
	
  /* class Network:
   *
   * Simulation of a network of neurons.
   * The network can connect neurons between them, update in function of time(ms)
   * and has a special class method for the connection of 12500 neurons, composed of 10000 
   * excitatory and 2500 inhibitory neurons
   * 
   * Be careful:
   * Indexes for neurons in this class begin with 0 and end with the nb of neurons - 1
   */
	private:
	
	vector<Neuron> neurons;				//neurons from the network
	vector<unsigned int> neurons_id;	//indexes of the neurons
	unsigned int nb_neurons;			//number of neurons in the network
	double net_clock;					//clock of the network
	ofstream file_spike;				//file in which each t_spike from each neuron is stored
	
	public:
	
	
	/* Constructor in which we give the number of neurons to create a vector of neurons 
	 * and to implement nb_neurons
	 * 
	 * Neurons are constructed by default (with background noise)
	 */
	Network(int nb_neuron);
	
	
	/* This constructor integrate a vector of neurons
	 * 
	 * Neurons can be customized before integration
	 */
	Network(vector<Neuron> new_neurons);
	
	//Getter for the neurons
	vector<Neuron> get_neurons() const;
	
	//Getter for the indexes of neurons
	vector<unsigned int> get_neurons_id() const;
	
	//Getter for the number of neurons
	unsigned int get_nb_neurons() const;
	
	
	/*  Method to automatically connect the 12500 neurons between them for the simulation
	 * 	Be careful! 
	 *  This method only works if there are exactly 12500 neurons in the network!
	 */
	void connection_for_12500_neurons();
	
	
	/* Method to manually connect neurons between them
	 * 
	 * 3 parameters : source_id for the index of the neuron which will give his spikes
	 * 				  target_id for the index of the new target neuron of source neuron
	 * 				  w for the new weight of the source neuron
	 */
	void connect(const unsigned int& source_id,const unsigned int& target_id,const double& w);
	
	
	/* Method to update the network from net_clock to net_clock+dt
	 * 
	 * This method will call the method to update each neuron from the network (update_neuron)
	 * 
	 * 1 parameter : dt for the duration in which we want to update
	 */
	void update_network(const double& dt);

};

#endif

