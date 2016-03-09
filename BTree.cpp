#include "BTree.h"
#include "BTreeNode.h"
#include "LeafNode.h"
#include "InnerNode.h"

#include <iostream>
#include <string>

using namespace std;

BTree::BTree(){
	head = NULL;
}

void BTree::insert(string name, int position) {

	if(head == NULL) {
		head = new LeafNode();
		Node data = Node();
		data.name = name;
		data.position = position;

		head->data[0]= data;
		head->numItems++;
	}

	LeafNode* leaf = findLeafToInsert(name, head);
	insertIntoLeafNode(leaf, name, position);





}
void BTree::print(){
	cout << head->data[0].name << head->data[0].position; 
}

void BTree::percolate(string name, int position, BTreeNode* current){


	if(current->isLeaf){
		//return (LeafNode*)current;
		insertIntoLeafNode(current, name, position);
		if(current->numItems >= L)

	}

	int i = 0;
	while(current->keys[i] < name){
		i++;
		if(current->keys[i] == "")
			break;

	}
	findLeafToInsert(name, position, current->next[i]);
}

void BTree::insertIntoLeafNode(LeafNode* leaf, string name, int position) {
	int i = 0;
	while(leaf->data[i].name < name){
		i++;
	}
	for(int j = i+1; j < L+1; j++)
		leaf->data[j] = leaf->data[j-1];

	Node newNode = Node();
	newNode.name = name;
	newNode.position = position;
	leaf->data[i] = newNode; 
	leaf->numItems++;

}
