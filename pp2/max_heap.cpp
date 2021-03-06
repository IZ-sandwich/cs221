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
		data[0] = data[size()-1];
		numItems--;	
	
		if (size()==0) return text_item{"",0};
		swap_down(0);
		return top();
	}
}

void max_heap::swap_down(int i) {
	// ADD CODE HERE
	if (i>=size()-1) return;
	int left_child = 2*i+1;
	int right_child = 2*i+2;
	if (left_child >= size()) return;
	if (right_child >= size() && left_child == size()) {
		 text_item temp = data[i];
		 data[i] = data[left_child];
		 data[left_child] = data[i];
		 return;
	}
	if ((data[i].freq < data[left_child].freq) && (data[left_child].freq > data[right_child].freq)) {
		text_item temp = data[i];
		data[i] = data[left_child];
		data[left_child] = temp;
		swap_down(left_child);
	}
	else if (data[i].freq < data[right_child].freq) {
		text_item temp = data[i];
		data[i] = data[right_child];
		data[right_child] = temp;
		swap_down(right_child);
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
		int current = numItems-1;
		while (current != 0 && data[(current-1)/2].freq < data[current].freq) {
			swap_up(current);
			current = (current-1)/2;
		}
	}
}

void max_heap::swap_up(int i) {
	// ADD CODE HERE
	int parent = (i-1) / 2;
	text_item temp = data[i];
	data[i] = data[parent];
	data[parent] = temp;
}
