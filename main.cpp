#include "Neuron.h"
#include "Network.h"

int main()
{
	Network net(12500);
	
	cout<<"Simulation of the network :"<<endl<<endl;	

	net.connection_for_12500_neurons();	
	net.update_network(12.0);
	
	cout<<"End of the simulation."<<endl;
		
	return 0;
}
