#include <iostream>

#include "LQueue.h"
#include "runway.h"

//TODO: clean code, make comments

using namespace std;

void print(Queue q)
{ q.display(cout); }

int main() {
	
	planeNum = 1000;
	
	// Initialize input parameters
	
	int sim_length;
	int random_seed;
	
	// Ask user for input parameters
	cout << "runway" << endl;
	cout << "Enter: " << endl;
	cout << "Time for a plane to land (in minutes): " ;
	cin >> landTime;
	cout << "Time for a plane to takeOff (in minutes): " ;
	cin >> takeOffTime;
	cout << "landing rate (planes/hour): " ;
	cin >> landRate;
	cout << "takeOff rate (planes/hour): " ;
	cin >> takeOffRate;
	cout << "How long to run the simulation (in minutes): ";
	cin >> sim_length; 
	cout << "failure chance of the runways (int value, in tenths of percent): ";
	cin >> failureRate;
	cout << "Got value: " << failureRate << endl;
	cout << "Random seed value: ";
	cin >> random_seed;
	
	srand(random_seed);
	
	Runway r1("RUNWAY1", NULL);
	Runway r2("RUNWAAAAAAY2", &r1);
	r1.backupRunway = &r2;
	
	int simTime;
	
	// Sim
	cout << "---Starting Simuration---" << endl;
	for (simTime = 0; simTime < sim_length; simTime++) {
			cout << "Time is: " << simTime << endl;
			r1.simStep();
			r2.simStep();
	}
	
	r1.generatesPlanes = false;
	r2.generatesPlanes = false;
	cout << "Plane generation stopped" << endl;
	
	// Wait for queues to empty
	while ( !r1.landing.empty() || !r1.takeoff.empty() || !r2.landing.empty() ||
		!r2.takeoff.empty() || !r1.isFree || !r2.isFree ) {
		
		cout << "Time is: " << simTime << endl;
		r1.simStep();
		r2.simStep();
		simTime++;
	}
	
	cout << "***Statistics***" << endl;
	r1.printStats();
	r2.printStats();
	
}
	
Runway::Runway(string name, Runway* backupRunway) :
	name(name),
	isActive(true),
	isFree(true),
	generatesPlanes(true),
	maxLanding(0),
	maxTakeoff(0),
	landWaitTime(0),
	takeoffWaitTime(0),
	planesLanded(0),
	planesTakenoff(0),
	backupRunway(backupRunway)
{
}

Runway::~Runway()
{
}

void Runway::simStep() {
	cout << "*" << name << "*" << endl;
	cout << "Landing queue: ";
	print(landing);
	cout << "Take off queue: ";
	print(takeoff);
	
	if (isActive) {
	
		int landRand = rand() % 60;
		int takeOffRand = rand() % 60;
		int failRand = rand() % 1000;
		
		if (failRand < failureRate && backupRunway != NULL) {
			cout << "RUNWAY FAILURE!!!!!!!!!!!!!!!!!" << endl;
			isActive = false;
			backupRunway->landing.merge_two_queues(landing);
			backupRunway->takeoff.merge_two_queues(takeoff);
			backupRunway->backupRunway = NULL;
			
			// Let time take one more step after deactivation
			if (!isFree) {
				// Time passes:
				timeLeft--;
				if (timeLeft == 0) {
					cout << "    Plane # " << planeNumUsingRunway;
					if (isLanding) {
						cout << " has landed; " << landing.getSize() << " in landing queue"
							<< endl;
						planesLanded++;
					} else {
						cout << " has taken off; " << takeoff.getSize() << " in takeoff queue"
							<< endl;
						planesTakenoff++;
					}
					isFree = true;
				}
			}
			return;
		}
		
		if (generatesPlanes) {
			if (landRand < landRate) {
				// Plane is landing, generate it and add it to queue
				cout << "    Plane # " << planeNum << " wants to land" << endl;
				landing.enqueue(planeNum);
				planeNum++;
				maxLanding = max(landing.getSize(), maxLanding);
				cout << "    Plane added to landing queue; " << landing.getSize()
					<< " in queue" << endl;
			}
			if (takeOffRand < takeOffRate) {
				// Plane is taking off, generate it and add it to queue
				cout << "    Plane # " << planeNum << " wants to take off" << endl;
				takeoff.enqueue(planeNum);
				planeNum++;
				maxTakeoff = max(takeoff.getSize(), maxTakeoff);
				cout << "    Plane added to takeoff queue; " << takeoff.getSize()
					<< " in queue" << endl;
			}
		}
		
		// Process queues
		if (isFree) {
			// Prioritize landing or allow to take off:
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
		}
	} else {
		cout << "Runway inactive" << endl;
	}
	
	if (!isFree) {
		// Time passes:
		timeLeft--;
		if (timeLeft == 0) {
			cout << "    Plane # " << planeNumUsingRunway;
			if (isLanding) {
				cout << " has landed; " << landing.getSize() << " in landing queue"
					<< endl;
				planesLanded++;
			} else {
				cout << " has taken off; " << takeoff.getSize() << " in takeoff queue"
					<< endl;
				planesTakenoff++;
			}
			isFree = true;
		}
	}
	
	landWaitTime += landing.getSize();
	takeoffWaitTime += takeoff.getSize();
}

void Runway::printStats() {
	double averageLandingWait = ((double) landWaitTime) / planesLanded;
	double averageTakeoffWait = ((double) takeoffWaitTime) / planesTakenoff;
	
	cout << name << " landed:   " << planesLanded << " planes" << endl;
	cout << name << " sent off: " << planesTakenoff << " planes" << endl;
	cout << name << " has average landing wait time of " << averageLandingWait
		<< " minutes" << endl;
	cout << name << " has average takeoff wait time of " << averageTakeoffWait
		<< " minutes" << endl;
	cout << name << " had a maximum landing queue of " << maxLanding << " planes"
		<< endl;
	cout << name << " had a maximum takeoff queue of " << maxTakeoff << " planes"
		<< endl;
}


unsigned int max(unsigned int a, unsigned int b) {
	if (a > b)
		return a;
	else
		return b;
}
