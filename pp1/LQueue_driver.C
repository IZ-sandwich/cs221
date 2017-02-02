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

	Queue q3;
	for (int i = 1; i <= 5; i++) 
		q3.enqueue(100*i);
	std::cout << "Q3 is:" << endl;
	print(q3);
	std::cout << "Moving 100 to front" << endl;
	q3.move_to_front(100);
	std::cout << "Moved 100 to front" << endl;
	print(q3);
	std::cout << "Moving 300 to front" << endl;
	q3.move_to_front(300);
	std::cout << "Moved 300 to front" << endl;
	print(q3);
	std::cout << "Moving 500 to front" << endl;
	q3.move_to_front(500);
	std::cout << "Moved 500 to front" << endl;
	print(q3);
	Queue q4;
	
	for (int i = 1; i <= 5; i++) 
		q4.enqueue(100*i);
	std::cout << "Q4 is:" << endl;
	print(q4);
	
	Queue q5;
	for (int i = 1; i <= 3; i++) 
		q5.enqueue(90*i);
	std::cout << "Q5 is:" << endl;
	print(q5);
	
	// Merging two nonempty queues of different lengths
	std::cout << "Merging q5 into q4" << endl;
	q4.merge_two_queues(q5);
	std::cout << "Merge complete" << endl;
	std::cout << "q5 is now empty: ";
	print(q5);
	std::cout << "Merged result in q4: ";
	print(q4);
	
	// Merging an empty queue into a nonempty queue
	std::cout << "Merging q5 into q4 again" << endl;
	q4.merge_two_queues(q5);
	std::cout << "Merge complete" << endl;
	std::cout << "q5 is still empty: ";
	print(q5);
	std::cout << "Merged result: ";
	print(q4);
	
	// Merging a nonempty queue into an empty queue
	std::cout << "Merging q4 into q5" << endl;
	q5.merge_two_queues(q4);
	std::cout << "Merge complete" << endl;
	std::cout << "q4 is now empty: ";
	print(q4);
	std::cout << "Merged result: ";
	print(q5);
	
	// Merging 2 empty queues together
  std::cout << "Merging 2 empty queues" << endl;
  q4.merge_two_queues(q4);
	std::cout << "Merge complete" << endl;
  std::cout << "Merged result is an empty queue: " ;
	print(q4);
	
	Queue q6;
	q6.enqueue(0);
	q6.enqueue(1);
	std::cout << "Q6 is" << endl;
	print(q6);
	
	Queue q7;
	q7.enqueue(0);
	q7.enqueue(1);
	std::cout << "Q7 is" << endl;
	print(q7);
	
	// Merging length 1 queues with degenerate entries
	std::cout << "Merging queues with identical members" << endl;
	q6.merge_two_queues(q7);
	std::cout << "Merge complete" << endl;
	std::cout << "One queue is now empty: ";
	print(q7);
	std::cout << "Merged result: ";
	print(q6);
	
	
	return 0;

}
