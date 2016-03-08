#ifndef LEAFNODE
#define LEAFNODE

#include <iostream>
#include <string>
#include "BTreeNode.h"

using namespace std;

struct Node{
	string name;
	int position;

};

class LeafNode:public BTreeNode{
public: 
	Node *names; 

	LeafNode(){
		names = new Node[L];
		for(int i = 0; i < L; i++){
			names[i].name = "";
			names[i].position = -1; 
		}
	}


};


#endif