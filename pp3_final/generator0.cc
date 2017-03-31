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
	unsigned int n = atoi(argv[1]);
	
	for(unsigned int i = 1; i < n/2; i++) {
		cout << "I " << 10000*i << endl;
	}
	
	for(unsigned int i = 1; i < n/2; i++) {
		cout << "F " << 1 << endl; //find a value that will never be found
	}
		
	return 0;
}
