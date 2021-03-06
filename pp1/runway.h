
/*-- runway.h -------------------------------------------------------------

  This header file defines a Runway data type.
  
  Basic operations:
    constructor:  Constructs a Runway with default settings (active, unoccupied,
				    empty queues, allows landing/take-off requests)
	simStep:      Updates a runway by 1 time step
    printStats:   Print runway statistics (planes landed/taken off, average wait
					time, etc.)
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
	
	    // Landing queue and takeoff queue
		Queue landing;
		Queue takeoff;
		
		string name;
		bool isActive;
		bool isFree;
		bool isLanding; // True if the plane using the runway
	                    // is a landing plane, False if it is taking off. 
						// This value is only relevant
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
		
		// A backup runway for planes in queue to land if runway fails
		Runway* backupRunway;

		
		// Runs a single step of the simulation
		void simStep();
		
		// Print interesting statistics about runway's usage
		void printStats();
		
		// Default constructor
		Runway(string name, Runway* backupRunway);
		~Runway();
	
	private:
		int timeLeft;
	
}; // end of class declaration
#endif
