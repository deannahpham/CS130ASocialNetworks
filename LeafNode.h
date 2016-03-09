#ifndef LEAFNODE
#define LEAFNODE

#include <iostream>
#include <string>
#include "BTreeNode.h"

using namespace std;


class LeafNode:public BTreeNode{
public: 
	//Node *data; (is in BTreeNode.h)
	//bool isLeaf;

	LeafNode(){
		isLeaf = true; 
		data = new Node[L];
		for(int i = 0; i < L; i++){
			data[i].name = "";
			data[i].position = -1; 
		}
	}


};


#endif