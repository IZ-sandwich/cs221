#include <iostream>
#include "LQueue.h"
#include "runway.h"


using namespace std;

int main() {
	
	planeNum = 1000;
	
	// Initialize input parameters
	int landTime;
	int takeOffTime;
	int landRate;
	int takeOffRate;
	int sim_length;
	int random_seed;
	
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
	
	Runway r1("RUNWAY1", NULL);
	
	r1.landTime = landTime;
	r1.takeOffTime = takeOffTime;
	r1.landRate = landRate;
	r1.takeOffRate = takeOffRate;
	
	// Sim
	cout << "---Starting Simuration---" << endl;
	for (int i = 0; i < sim_length; i++) {
			cout << "Time is: " << i << endl;
			r1.simStep();
	}
}
	
Runway::Runway(string name, Runway* backupRunway) :
	name(name),
	isActive(true),
	isFree(true),
	backupRunway(backupRunway)
{
}

Runway::~Runway()
{
}

void Runway::simStep() {
	cout << "*" << name << "*" << endl;
	int landRand = rand() % 60;
	int takeOffRand = rand() % 60;

	if (landRand < landRate) {
		// Plane is landing, generate it and add it to queue
		cout << "    Plane # " << planeNum << " wants to land" << endl;
		landing.enqueue(planeNum);
		planeNum++;
		cout << "    Plane added to landing queue; " << landing.getSize()
			<< " in queue" << endl;
	}
	if (takeOffRand < takeOffRate) {
		// Plane is taking off, generate it and add it to queue
		cout << "    Plane # " << planeNum << " wants to take off" << endl;
		takeoff.enqueue(planeNum);
		planeNum++;
		cout << "    Plane added to takeoff queue; " << takeoff.getSize()
			<< " in queue" << endl;
	}
	
	if (isFree) {
		// Prioratize landing or allow to take off:
		if (!landing.empty()) {
			planeNumUsingRunway = landing.front();
			cout << "    Plane # " << planeNumUsingRunway << " is landing" << endl;
			landing.dequeue();
			isFree = false;
			timeLeft = landTime;
			isLanding = true;
		} else if (!takeoff.empty()) {
			planeNumUsingRunway = takeoff.front();
			cout << "    Plane # " << planeNumUsingRunway << " is taking off" << endl;
			takeoff.dequeue();
			isFree = false;
			timeLeft = takeOffTime;
			isLanding = false;
		}
	} else {
		// Time passes:
		timeLeft--;
		if (timeLeft == 0) {
			cout << "    Plane # " << planeNumUsingRunway;
			if (isLanding)
				cout << " has landed; " << landing.getSize() << " in landing queue"
					<< endl;
			else
				cout << " has taken off; " << takeoff.getSize() << " in takeoff queue"
					<< endl;
			isFree = true;
		}
	}
}
