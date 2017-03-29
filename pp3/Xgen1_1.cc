#include <iostream>
#include <cstdlib> // for atoi
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[])
{
if (argc != 2) // remember, argv[0] is the program name
	{
		cerr << "Wrong number of arguments!" << endl;
		return 1;
	}
	srand(10);
	unsigned int n = atoi(argv[1]);
	
	for(unsigned int i = 1; i < n/2; i++) {
		cout << "I " << i << endl;
	}

	for (unsigned int i = 1; i < n/2; i++) {
		unsigned int k = rand() % (n/2 - 1) + 1; 	//search for a random value
		cout << "F " << k << endl;
	}
	return 0;
}
