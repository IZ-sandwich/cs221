#include <iostream>
#include "LQueue.h"


using namespace std;

int main() {
	
	// Construct the landing queue and takeoff queue
	Queue landing = new Queue();
	Queue takeoff = new Queue();
	
	// Initialize input parameters
	int landTime;
	int takeOffTime;
	int landRate;
	int takeOffRate;
	int sim_length;
	int random_seed;
	
	int planeNum = 1000;
	bool runwayIsFree = true;
	bool isLanding; // True if the plane using the runway
	// is a landing plane, False if it is taking off
	int planeNumUsingRunway; 
	int timeLeft;
	
	// Ask user for input parameters
	cout << "runway" << endl;
	cout << "Enter: " << endl;
	cout << "Time for a plane to land (in minutes): " ;
	cin >> landTime;
	cout << "Got value: " << landTime << endl;
	cout << "Time for a plane to takeOff (in minutes): " ;
	cin >> takeOffTime;
	cout << "Landing rate (planes/hour): " ;
	cin >> landRate;
	cout << "TakeOff rate (planes/hour): " ;
	cin >> takeOffRate;
	cout << "How long to run the simulation (in minutes): ";
	cin >> sim_length; 
	cout << "Random seed value: ";
	cin >> random_seed;
	
	srand(random_seed);
	
	// Sim
	cout << "---Starting Simuration---" << endl;
	for (int i = 0; i < sim_length; i++) {
		cout << "Time is: " << i << endl;
		
		int landRand = rand() % 60;
		int takeOffRand = rand() % 60;
		
		if (landRand < landRate) {
			// Plane is landing, generate it and add it to queue
			cout << "Plane # " << planeNum << " wants to land" << endl;
			landing.enqueue(planeNum);
			planeNum++;
			cout << "Plane added to landing queue; " << landing.getSize() << " in queue" << endl;
		}
		if (takeOffRand < takeOffRate) {
			// Plane is taking off, generate it and add it to queue
			cout << "Plane # " << planeNum << " wants to take off" << endl;
			takeoff.enqueue(planeNum);
			planeNum++;
			cout << "Plane added to takeoff queue; " << takeoff.getSize() << " in queue" << endl;
		}
		
		if (runwayIsFree) {
			// Prioratize landing or allow to take off:
			if (!landing.empty()) {
				planeNumUsingRunway = landing.front();
				cout << "Plane # " << planeNumUsingRunway << " is taking off" << endl;
				landing.dequeue();
				runwayIsFree = false;
				timeLeft = landTime;
				isLanding = true;
			} else if (!takeoff.empty()) {
				runwayIsFree = false;
				isLanding = false;
			}
		} else {
			// Time passes:
			timeLeft--;
			if (timeLeft == 0) {
				cout << "Plane # " << planeNumUsingRunway;
				if (isLanding)
					cout << " has landed; " << landing.getSize() << " in landing queue" << endl;" << endl;
				else
					cout << " has taken off; " << takeoff.getSize() << " in takeoff queue" << endl;" << endl;
				runwayIsFree = true;
			}
		}
	}
	
	
	
}