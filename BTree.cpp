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
		return;
	}

	percolate(name, position,head);

}

void BTree::printLeaf(LeafNode* leaf){
	for(int i =0; i< L+1; i++){
		cout << leaf->data[i].name << leaf->data[i].position <<endl;
	}
	cout<<endl;
}

void BTree::print(){
	for(int i = 0; i< M; i++){
		cout<< head->keys[i] << endl;
	}
	cout << head->next << endl;
	printLeaf((LeafNode*)(head->next[0]));
	printLeaf((LeafNode*)(head->next[1]));

}

void BTree::percolate(string name, int position, BTreeNode* current){

	if(current->isLeaf){
		insertIntoLeafNode((LeafNode*)current,name,position);
		if(current->numItems > L){
			LeafNode* newLeaf = splitLeaf((LeafNode*)current);
			InnerNode* newInnerNode = new InnerNode();
			newInnerNode->keys[0] = newLeaf->data[0].name;
			newInnerNode->next[0] = current;
			//printLeaf((LeafNode*)newInnerNode->next[0]);
			newInnerNode->next[1] = newLeaf;
			head = (BTreeNode*)newInnerNode;
			print(); 
			//printLeaf((LeafNode*)head->next[1]);
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
		insertIntoLeafNode((LeafNode*)childNode, name, position);
		if(current->numItems > L){
			LeafNode* newLeaf = splitLeaf((LeafNode*)childNode);

			for(int j = M; j >i ; j--){
				current->next[j] = current->next[j-1];
			}

			for(int j = M-1; j>i; j--){
				current->keys[j] = current->keys[j-1];
			}

			current->next[i+1] = newLeaf;
			current->keys[i+1] = newLeaf->data[0].name;
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
		if(leaf->data[i].name == "")
			break;
	}
	
	for(int j = L; j >i; j--)
		leaf->data[j] = leaf->data[j-1];

	Node newNode = Node();
	newNode.name = name;
	newNode.position = position;
	leaf->data[i] = newNode; 
	leaf->numItems++;

	//print();

}

LeafNode* BTree::splitLeaf(LeafNode* childNode){

	LeafNode* newNode = new LeafNode();

	int half = childNode->numItems/2;
	for(int i = half; i < childNode->numItems; i++){
		newNode->data[i-half] = childNode->data[i];
		Node filler = Node();
		childNode->data[i] = filler; 
	}

	childNode->numItems = half;
	newNode->numItems = half;

	return newNode;


}

InnerNode* BTree::splitInnerNode(BTreeNode* node){
	InnerNode* newNode = new InnerNode();

	int half = node->numItems/2;
	for(int i = half; i < node->numItems; i++) {
		newNode->next[i-half] = node->next[i];
	}

	node->numItems= half;
	newNode->numItems= half; 

	return newNode; 

}




