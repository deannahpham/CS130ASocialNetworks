#include "InnerNode.h"

#include <iostream>
#include <string>

using namespace std;

InnerNode::InnerNode() {
	isLeaf = false;
	keys =  new string[M];
	for(int i = 0; i < M; i++){
		keys[i] = "";
	}

	next = new BTreeNode*[M+1];
	for(int i = 0; i < M+1; i++){
		next[i] = NULL;
	}
}
