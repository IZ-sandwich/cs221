/*--- LQueue.cpp ----------------------------------------------------------
  This file implements LQueue member functions.
  From:  "ADTs, Data Structures, and Problem Solving with C++", 2nd edition
         by Larry Nyhoff
-------------------------------------------------------------------------*/
 
#include <iostream>
using namespace std;

#include "LQueue.h"

//--- Definition of Queue constructor
Queue::Queue()
: myFront(0), myBack(0), size(0)
{}

//--- Definition of Queue copy constructor
Queue::Queue(const Queue & original)
{
   myFront = myBack = 0;
   size = 0;
   if (!original.empty())
   {
      // Copy first node
      myFront = myBack = new Queue::Node(original.front());
	  size = original.size;
      // Set pointer to run through original's linked list
      Queue::NodePointer origPtr = original.myFront->next;
      while (origPtr != 0) {
         myBack->next = new Queue::Node(origPtr->data);
         myBack = myBack->next;
         origPtr = origPtr->next;
      }
   }
}

//--- Definition of Queue destructor
Queue::~Queue()
{ 
  // Set pointer to run through the queue
  Queue::NodePointer prev = myFront,
                     ptr;
  while (prev != 0) {
      ptr = prev->next;
      delete prev;
      prev = ptr;
    }
}

//--- Definition of assignment operator
const Queue & Queue::operator=(const Queue & rightHandSide)
{
   if (this != &rightHandSide)         // check that not q = q
   {
      this->~Queue();                  // destroy current linked list
      if (rightHandSide.empty())       // empty queue
         myFront = myBack = 0;
      else {                                // copy rightHandSide's list
         // Copy first node
         myFront = myBack = new Queue::Node(rightHandSide.front());
		 size = rightHandSide.size;
         // Set pointer to run through rightHandSide's linked list
         Queue::NodePointer rhsPtr = rightHandSide.myFront->next;
         while (rhsPtr != 0)
         {
           myBack->next = new Queue::Node(rhsPtr->data);
           myBack = myBack->next;
           rhsPtr = rhsPtr->next;
         }
      }
   }
   return *this;
}

unsigned int Queue::getSize() const {
	return size;
}

//--- Definition of empty()
bool Queue::empty() const
{ 
   return (myFront == 0); 
}

//--- Definition of enqueue()
void Queue::enqueue(const QueueElement & value)
{
   Queue::NodePointer newptr = new Queue::Node(value);
   if (empty())
      myFront = myBack = newptr;
   else {
      myBack->next = newptr;
      myBack = newptr;
   }
   size++;
}

//--- Definition of display()
void Queue::display(ostream & out) const
{
   Queue::NodePointer ptr;
   for (ptr = myFront; ptr != 0; ptr = ptr->next)
     out << ptr->data << "  ";
   out << endl;
}

//--- Definition of front()
QueueElement Queue::front() const
{
   if (!empty())
      return (myFront->data);
   else {
	return 0;
   }
}

//--- Definition of dequeue()
void Queue::dequeue()
{
   if (!empty())
   {
      Queue::NodePointer ptr = myFront;
      myFront = myFront->next;
      delete ptr;
      if (myFront == 0)     // queue is now empty
         myBack = 0;
			size--;
   } else
      cerr << "*** Queue is empty -- can't remove a value ***\n";
}

//--- Definition of move_to_front()
void Queue::move_to_front(QueueElement key) 
{
	if (!empty())
	{
		Node* temp_prev = myFront;
		Node* temp = myFront;
		if (temp->data == key) {
			return;
		}
		while (temp->next != NULL) {
			if (temp->data == key) {
				temp_prev->next = temp->next;
				temp->next = myFront;
				myFront = temp;
				return;
			}
			temp_prev = temp;
			temp = temp->next;
		}
		if (temp->data == key) {
			temp_prev->next = NULL;
			temp->next = myFront;
			myFront = temp;		
		  return;
		}
			
	} else
		cerr << "*** Queue is empty -- can't remove a value ***\n";
}

//--- Definition of merge_two_queues()
void Queue::merge_two_queues(Queue &q2) 
{
  if (!q2.empty()) {
  	Node fakeFront(0,NULL);
  	Node * ptrTemp = myFront;
  	myBack = &fakeFront;

  	while ( ptrTemp != NULL || q2.myFront != NULL) {
  		if ( ptrTemp == NULL) {
  			myBack->next = q2.myFront;
  			myBack = myBack->next;
  			q2.myFront = q2.myFront->next;
  			continue;
  		}
  		if ( q2.myFront == NULL) {
  			myBack->next = ptrTemp;
  			myBack = myBack->next;
  			ptrTemp = ptrTemp->next;
  			continue;
  		}
  		
  		// Compare values and attach
  		if (q2.myFront->data > ptrTemp->data) {
  			myBack->next = ptrTemp;
  			myBack = myBack->next;
  			ptrTemp = ptrTemp->next;
  		} else {
  			myBack->next = q2.myFront;
  			myBack = myBack->next;
  			q2.myFront = q2.myFront->next;
  		}
  	}
  	
  	q2.myFront = NULL;
  	q2.myBack = NULL;
  	size += q2.size;
  	q2.size = 0;
  	myFront = fakeFront.next;
  } else
  	return;
}   

