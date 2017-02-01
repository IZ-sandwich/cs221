
/*-- runway.h -------------------------------------------------------------

  This header file defines a runway
  
  TODO: edit this:
  Basic operations:
    constructor:  Constructs an empty queue
    empty:        Checks if a queue is empty
    enqueue:      Modifies a queue by adding a value at the back
    front:        Accesses the top queue value; leaves queue unchanged
    dequeue:      Modifies queue by removing the value at the front
    display:      Displays all the queue elements
    Note: Execution terminates if memory isn't available for a queue element.
---------------------------------------------------------------------------*/

#include <iostream>
#include <string>
using namespace std;

#ifndef RUNWAY

#define RUNWAY
int planeNum;
int landTime;
int takeOffTime;
int landRate;
int takeOffRate;
int failureRate;

unsigned int max(unsigned int a, unsigned int b);

class Runway
{
	public:
	
	  // Construct the landing queue and takeoff queue
		Queue landing;
		Queue takeoff;
		
		string name;
		bool isActive;
		bool isFree;
		bool isLanding; // True if the plane using the runway
	// is a landing plane, False if it is taking off. This value is only relevant
	// if the runway is not free
		int planeNumUsingRunway;
		bool generatesPlanes;
		
		// Statistics values
		unsigned int maxLanding;
		unsigned int maxTakeoff;
		unsigned int landWaitTime;
		unsigned int takeoffWaitTime;
		int planesLanded;
		int planesTakenoff;
		
		// if runway fails, merge queues with backupRunway
		Runway* backupRunway;
		
		// Runs a single step of the simulation
		void simStep();
		
		void printStats();
		
		// Default constructor
		Runway(string name, Runway* backupRunway);
		~Runway();
	
	private:
		int timeLeft;
	
};
#endif
