/*---------------------------------------------------------------------
                  Driver program to test the Queue class.
  ----------------------------------------------------------------------*/

#include <iostream>
#include "LQueue.h"
using namespace std;
	

void print(Queue q)
{ q.display(cout); }

int main(void)
{
	Queue q1;
	for (int i = 1; i <= 5; i++) 
		q1.enqueue(100*i);
	print(q1);
	std::cout << "Moving 100 to front" << endl;
	q1.move_to_front(100);
	std::cout << "Moved 100 to front" << endl;
	print(q1);
	std::cout << "Moving 300 to front" << endl;
	q1.move_to_front(300);
	std::cout << "Moved 300 to front" << endl;
	print(q1);
	std::cout << "Moving 500 to front" << endl;
	q1.move_to_front(500);
	std::cout << "Moved 500 to front" << endl;
	print(q1);
	
	/*
	Queue q1;
	cout << "Queue created.  Empty? " << boolalpha << q1.empty() << endl;

	cout << "How many elements to add to the queue? ";
	int numItems;
	cin >> numItems;
	for (int i = 1; i <= numItems; i++) 
		q1.enqueue(100*i);

	cout << "Contents of queue q1 (via  print):\n";
	print(q1); 
	cout << endl;

	Queue q2;
	q2 = q1;
	cout << "Contents of queue q2 after q2 = q1 (via  print):\n";
	print(q2); 
	cout << endl;

	cout << "Queue q2 empty? " << q2.empty() << endl;

	cout << "Front value in q2: " << q2.front() << endl;

	while (!q2.empty())
	{
	 cout << "Remove front -- Queue contents: ";
	 q2.dequeue();
	 q2.display(cout);
	}
	cout << "Queue q2 empty? " << q2.empty() << endl;
	cout << "Front value in q2?" << endl << q2.front() << endl;
	cout << "Trying to remove front of q2: " << endl;
	q2.dequeue();
	//system("PAUSE");

	*/
	return 0;
}
