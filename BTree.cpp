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
		insertIntoLeafNode(current,name,position);
		if(current->numItems > L){
			LeafNode* newLeaf = splitLeaf(current);
			InnerNode* newInnerNode = new InnerNode();
			newInnerNode->keys[0] = newLeaf->data[0].name;
			newInnerNode->next[0] = current;
			newInnerNode->next[1] = newLeaf; 
			head = newInnerNode; 
		}
		return;
	}

	int i = 0;
	while(current->keys[i] < name){
		i++;
		if(current->keys[i] == "")
			break;
	}

	BTreeNode* childNode = current->next[i];

	if(childNode->isLeaf){
		//return (LeafNode*)current;
		insertIntoLeafNode(current, name, position);
		if(current->numItems > L){

		}

	}
	else{
		percolate(name, position, childNode);
		if(childNode->numItems >= M){

		}

	}
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

LeafNode* BTree::splitLeaf(LeafNode* childNode){

	LeafNode* newNode = new LeafNode[L+1];

	int half = childNode->numItems/2;
	for(int i = half; i < childNode->numItems; i++){
		newNode[i-half] = childNode[i];
		LeafNode filler = LeafNode();
		childNode[i] = filler; 
	}

	childNode->numItems = half;
	newNode->numItems = half;

	return newNode;


}




