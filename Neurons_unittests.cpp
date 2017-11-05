#include "Neuron.h"
#include "Network.h"
#include <gtest/gtest.h>


TEST(neuron,potential_under_thresold)	
/*test to be sure that with an imput current of 1pA and no background noise, 
 *the membrane potential will never reach the thresold, but only approach it
 */ 
{
	Neuron n(V_res,false);
	double I_ext = 1.0;
	
	
	double v = V_thr;
	for(int i(0);i<1000;++i)
	{
		n.update_neuron(1,I_ext);
		EXPECT_GT(v,n.get_V_mem()); 	
		//we use a loop to make sure that for each step, it will never reach the thresold
	}
}


TEST(neuron,spike_at_right_moment)
/*test to make sure that with an imput current of 1.01pA and no bg noise, 
 *the potential will reach V_thr and spike for the first time at t = 92.4ms
 */
{
	Neuron n(V_res,false);
	
	double t_spike = 92.4;//ms
	int t_step = static_cast<unsigned long>(ceil(100/h));//update between [0;100[
	double I_ext = 1.01;
	
	n.update_neuron(t_step,I_ext);
	
	EXPECT_EQ(t_spike,n.get_t_spikes()[0]);//if there is no spike, segfault because get_t_spikes is empty
}	

TEST(neurons,spike_received_with_delay_D)
/* test to make sure that a neuron connected to another one receive a spike with a delay = D
 */
{
	Neuron n1(V_thr,true),n2(V_res,false);		
	//we make sure that 2nd neuron will not gain potential not allowing him to receive background noise
	
	vector<Neuron> neurons{n1,n2};
	
	Network net(neurons);	
	net.connect(0,1,J);
	
	double v_before_D(0.0);
	double v_after_D(J);
	
	for(int i(0);i<D/h;++i)
	{
		net.update_network(h);
		
		EXPECT_EQ(v_before_D,net.get_neurons()[1].get_V_mem());
		//we expect to have the potential of 2nd neuron unchanged between 0 and D-h
	}
	
	net.update_network(h);
	EXPECT_EQ(v_after_D,net.get_neurons()[1].get_V_mem());
	//at t = D, the 2nd neuron receives J mV from 1st neuron	
}


int main(int argc, char** argv)
{
	testing::InitGoogleTest(&argc,argv);


	return RUN_ALL_TESTS();
}
/*****************************************
******************************************/
