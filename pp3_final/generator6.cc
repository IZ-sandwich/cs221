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
	
	for (unsigned int i = 1; i < n/3; i++) {
		cout << "I " << i*10001 << endl;
	}
	
	for (unsigned int i=1; i<n/3; i++) {
		cout << "F " << i*10001 << endl;
		cout << "R " << i*10001 << endl;
	}
	return 0;
}
