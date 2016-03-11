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
		data = new Node[L+1];
		for(int i = 0; i < L+1; i++){
			data[i].name = "";
			data[i].position = -1; 
		}
	}


};


#endif