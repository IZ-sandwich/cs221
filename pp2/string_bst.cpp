/*--- string_bst.C -----------------------------------------------
  This file implements string_bst.hpp member functions.
-------------------------------------------------------------------------*/

#include "string_bst.hpp"

string_bst::string_bst(){
	root = NULL;
	num_nodes = 0;
}

string_bst::~string_bst()
{ 
	remove(root);
}

void string_bst::remove(node_t *& n) {
	if (n != NULL) {
		remove(n->left);
		remove(n->right);
		delete n;
		n = NULL;
	}
}

bool string_bst::empty() const
{ 
   	return (root == 0); 
}

void string_bst::insert(const tree_key & key)
{
   	insert_helper(root, key);
}

void string_bst::insert_helper(node_t *& n, tree_key const & key) {
	if( n == NULL ) {
	  	n = new node_t{text_item{key, 1}, NULL, NULL};
	  	num_nodes++;
  	} else if (n->data.word == key) {
	  	n->data.freq++;
  	} else if (key < n->data.word) {
		insert_helper(n->left, key);
  	} else {
	  	insert_helper(n->right, key);
  	}
}

void string_bst::display() const {
   print_in_order(root);
   std::cout << std::endl;
}

void string_bst::print_in_order(node_t *n) const {
	if (n == NULL) {
		return;
	}
	print_in_order( n->left );
	std::cout << n->data.word << ":" << n->data.freq << ", ";
	print_in_order( n->right );
}

int string_bst::size() const {
	return num_nodes;	
}

string_bst::node_t* string_bst::get_root() const {
	return root;
}

int string_bst::word_frequency(const tree_key &key) const {
	
	// ADD CODE HERE
	std::cout << "word freq, looking for: " << key << std::endl;
	node_t * current = get_root();
	while (current != nullptr) {
	/*// Debuging code
	if (current != nullptr) {
		std::cout << "key: " << current->data.word;
		if (current->left != nullptr)
			std::cout << " left: " << current->left->data.word;
		else
			std::cout << " NO LEFT";
		if (current->right != nullptr)
			std::cout << " right: " << current->right->data.word << std::endl;
		else
			std::cout << " NO RIGHT!" << std::endl;
	}
	else
		std::cout << "got to a null!" << std::endl;
		*/
	// Logic code
	if (current->data.word == key)
		break;
	if (current->left == nullptr)
		current = current->right;
	else if (current->right == nullptr)
		current = current->left;
	else {
		int result = key.compare(current->data.word);
		if (result > 0)
			current = current->right;
		else
			current = current->left;
		}
	}
	if (current == nullptr)
		return 0;
	else
		return current->data.freq;
}

