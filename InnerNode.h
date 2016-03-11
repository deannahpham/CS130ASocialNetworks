#ifndef INNERNODE 
#define INNERNODE

#include <iostream>
#include <string>
#include "BTreeNode.h"


using namespace std;

class InnerNode:public BTreeNode{
public:
	//string *keys; (is in BTreeNode.h)
	//BTreeNode **next; (is in BTreeNode.h)
	//bool isLeaf;

	InnerNode();

private:


};

#endif