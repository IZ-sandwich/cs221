/*--- max_heap.cpp -----------------------------------------------
  This file implements hax_heap.hpp member functions.
-------------------------------------------------------------------------*/

#include "max_heap.hpp"
#include <stdexcept>

max_heap::max_heap(int n){
	data = new text_item[n];
	numItems = 0;
	max_capacity = n;
}

max_heap::~max_heap()
{ 
	delete [] data;
}

bool max_heap::empty() const {
	return (numItems == 0);
}
bool max_heap::full() const {
	return (numItems == max_capacity);
}

int max_heap::size() const {
	return numItems;
}	

text_item& max_heap::top() {
	if (empty()) {
		throw std::logic_error("Heap is empty, can't access top!");
	}
	return data[0];
}


//--- You must comple the following functions: 


text_item max_heap::delete_max() {
	if (empty()) {
		throw std::logic_error("Cannot delete, heap is empty!");
	} else {
		text_item temp = data[0];
		data[0] = data[size()-1];
		data[size()-1] = temp;
		top();
		int left = 1;
		int right = 2;
		int i=0;
		while ((data[left]>data[i]) | (data[right]>data[i])) { 
			swap_down(i);
			i = i+1;
			left = 2*i+1;
			right = 2*i+2;
		}
	}
}

void max_heap::swap_down(int i) {
	// ADD CODE HERE
	int left_child = 2*i+1;
	int right_child = 2*i+2;
	if (data[i] <= data[left_child]) {
		text_item temp = data[i];
		data[i] = data[left_child];
		data[left_child] = temp;
	}
	else if (data[i] <= data[right_child]) {
		text_item temp = data[i];
		data[i] = data[right_child];
		data[right_child] = temp;
	}
}

void max_heap::insert(const text_item & item) {
	if (full()) {
		throw std::logic_error("Cannot insert, heap array is full!");
	} else {
		
		// Fix this so it correctly inserts
		// and maintains the heap-order property
		// required for a max-heap
		data[numItems++] = item;
	}
}

void max_heap::swap_up(int i) {
	// ADD CODE HERE
	int parent = (i-1) / 2;
	text_item temp = data[i];
	data[i] = data[parent];
	data[parent] = temp;
}
