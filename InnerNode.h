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

	InnerNode() {
		isLeaf = false;
		keys =  new string[M-1];
		for(int i = 0; i < M-1; i++){
			keys[i] = "";
		}

		next = new BTreeNode*[M];
		for(int i = 0; i < M; i++){
			next[i] = NULL;
		}
	}

private:


};

#endif