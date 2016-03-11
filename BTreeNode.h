#ifndef BTREE_NODE
#define BTREE_NODE

#include <iostream>
#include <string>

using namespace std;


struct Node{
	string name;
	int position;

};

class BTreeNode {
protected:
	int M = 5;
	int L = 3; 



public:

	string *keys; //for inner node
	BTreeNode **next; //for inner node
	Node *data; //for leaf node
	bool isLeaf;
	int numItems = 0; 

};

#endif