#ifndef BTREE
#define BTREE

#include <iostream>
#include <string>

#include "BTreeNode.h"
#include "LeafNode.h"
#include "InnerNode.h"


using namespace std;

class BTree {
public:
	BTree();
	void insert(string name, int position);
	LeafNode* percolate(string name, int position, BTreeNode* current);
	void insertIntoLeafNode(LeafNode* leaf, string name, int position);
	void print();


private:
	int M = 5;
	int L = 3;
	BTreeNode* head; 

};



#endif