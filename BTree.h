#ifndef BTREE
#define BTREE

#include <iostream>
#include <string>

#include "BTreeNode.h"
#include "LeafNode.h"
#include "InnerNode.h"
#include "ProfileData.h"


using namespace std;

class BTree {
public:
	BTree(ProfileData* profileData);
	void insert(string name, int position);
	BTreeNode* percolate(string name, int position, BTreeNode* current);
	void insertIntoLeafNode(LeafNode* leaf, string name, int position);
	LeafNode* splitLeaf(LeafNode* childNode);
	InnerNode* splitInnerNode(BTreeNode* node);
	void printLeaf(LeafNode* leaf);
	void print();
	void recPrint(BTreeNode* current, string str);
	void printRange(string name1, string name2);
	void printRangeRec(string name1, string name2, BTreeNode* current, bool* found1, bool* found2);


private:
	int M = 5;
	int L = 3;
	BTreeNode* head; 
	ProfileData* profileData; 
};



#endif