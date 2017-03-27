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

	vector<unsigned long long> s;
	for (unsigned int i=0; i< n/3; i++) {
		s.push_back(i);
	}
	random_shuffle(s.begin(),s.end());

	for(unsigned int i = 0; i < n/3; i++) {
		cout << "I " << s[i] << endl;
	}
	random_shuffle(s.begin(),s.end());
	
	for (unsigned int i=0; i< n/3; i++) {
		int k = s[1];  //search for the same value over and over again
		//int k = 9000000; //search for a value not in the dict
		cout << "F " << k << endl;
	}

	for (unsigned int i=0; i<n/3; i++) {
		unsigned int k = s[i]; 	//search for a random value
		cout << "F " << k << endl;
	}
	return 0;
}
