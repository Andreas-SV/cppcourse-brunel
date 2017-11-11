#ifndef NEURON_H
#define NEURON_H

#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <string>
#include <random>
#include <cassert>

using namespace std;

/* Because Neuron.h is the pillar of the project, all the following constants are stored in this file
 */

const double V_thr= 20.0;				//potential threshold at which a neuron produce a spike (in mV)
const double V_res= 0.0;				//membrane potential after exceeding the threshold (in mV)

const double I_ext = 0.0;				//external current (in pA)
const double tau = 20.0;				//time constant (in ms)
const double R = 20.0;					//resistance of (in GΩ)
const double C = 1.0;					//capacitance (in pF)		
const double t_refr = 2.0;				//duration in which the neuron is refractory (in ms)
const double h = 0.1;					//time step (1 step equals to 0.1ms)

const int N_E = 10000;					//number of excitatory neurons for the simulation								
const int N_I = 2500;					//number of inhibitory neurons
const double C_E = 0.1*N_E;				//number of excitatory connections for the simulation
const double C_I = 0.1*N_I;				//number of inhibitory connections
const double J = 0.1;					//spike response amplitude (in mV)
const double J_E = J;					//amplitude for excitatory neurons (in mV)
const double g = 5.0;					//ratio of J_I/J_E with J_I = amplitude for inhibitory neurons
const double D = 1.5;					//time delay in which a spike from a neuron is transmitted to another neuron (in ms)
const double eta = 2;					//ratio of nu_ext/nu_thr with nu_thr = number of spikes per second needed to reach threshold
const double nu_ext = eta*V_thr/(J*tau);//rate of external fire for a neuron (in /ms)


class Neuron
{
		
   /* class Neuron:
	*
	* Simulate a neuron.
	* The neuron can be updated in time steps, can connect to another neuron, 
	* and receive a spike from another neuron.
	*/	
	private:
	
	double V_mem;				//membrane potential of the neuron	
	vector<double> V_mem_step;	//membrane potential at each time step from 0 to t_now
	int nb_spikes;				//number of spikes produced by the neuron
	vector<double> t_spikes;	//times in which a spike is produced
	double t_now;				//clock of the neuron
	int is_refr;				//indicates time_step in which the neuron is refractory
	vector<double> buffer;		//spike ring-buffer in which the spike received is stored and absorbed with a delay D
	double weight;				//weight of the connexion AND neuron state (we>0->neuron_exci, we<0->neuron_inhi)
	vector<int> targets;		//neurons id at which the neuron send his spikes
	bool has_background;		//indicates if neuron receives random spikes from background noise
	
	public:
	
	//Constructor by default
	Neuron();
									
	//Constructor in which we give a potential and can apply the background noise
	Neuron(double v,bool background);
	
	//Getter for membrane potential
	double get_V_mem() const;
	
	//Getter for all membrane potential from 0 to t_now (in steps)
	vector<double> get_V_Mem_step() const;
	
	//Getter for the number of spikes 
	int get_nb_spikes() const;
	
	//Getter for the times when neuron spikes
	vector<double> get_t_spikes() const;
	
	//Getter for the clock
	double get_t_now() const;
	
	//Getter for the ring-buffer
	vector<double> get_buffer() const;
	
	//Getter for the weight
	double get_weight() const;
	
	//Getter for the targets indexes
	vector<int> get_targets() const;
	
	
	/* Method to update the neuron from t_now to t_now + n*h 
	 * 
	 * 2 parameters : n for the number of steps after which we want update
	 * 				  I for the external current to apply in the neuron
	 * 
	 * I is parametrised to I_ext by default, but the user can specify another external current
	 * 
	 * Returns a boolean : true if neuron has spiked during the update, false if not
	 */
	bool update_neuron(const unsigned int& n, const double& I = I_ext);																		
	
	
	/* Method to receive a spike from another neuron, the donor neuron
	 * 
	 * 2 parameters : t_spike for the time in which the donor neuron has spiked
	 * 				  weight_donor for weight of the donor neuron
	 */
	void receive_spike(const double& t_spike, const double& weight_donor);
	
	
	/* Method to connect the neuron to another neuron which will become a target neuron
	 * 
	 * 2 parameters : target_id for the index of the becoming target neuron
	 * 				  w for the weight the neuron will have
	 * 
	 * In this method, the neuron will receive a weight that will caracterize it
	 * If the weight is below 0, neuron become inhibitory
	 * If the weight is above 0, neuron become excitatory 
	 */
	void connect(const int& target_id, const double& w);
};

#endif
