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
	
	cout << "I " << 10 << endl;
	
	for(unsigned int i = 1; i < n/3; i++) {
		unsigned int a = (rand() % (n - 1)) + 1;
		cout << "I " << a << endl;		
		cout << "F " << a << endl;
		cout << "R " << a << endl;
	}

	return 0;
}
