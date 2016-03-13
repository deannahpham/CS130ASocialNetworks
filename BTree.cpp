#include "BTree.h"
#include "BTreeNode.h"
#include "LeafNode.h"
#include "InnerNode.h"
#include "ProfileData.h"

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

	BTreeNode* newNode = percolate(name, position,head);
	if(newNode == NULL)
		return;

	InnerNode* newInnerNode = new InnerNode();
	newInnerNode->keys[0] = head->keys[M/2];
	head->keys[M/2] = "";
	newInnerNode->next[0] = head;
	//printLeaf((LeafNode*)newInnerNode->next[0]);
	newInnerNode->next[1] = newNode;
	newInnerNode->numItems = 2;
	head = (BTreeNode*)newInnerNode;

}

void BTree::printLeaf(LeafNode* leaf){
	if(leaf == NULL)
		return;
	cout << leaf->numItems << endl;
	for(int i =0; i< L+1; i++){
		cout << leaf->data[i].name << leaf->data[i].position <<endl;
	}
	cout<<endl;
}

void BTree::print(){
	recPrint(head, "");
	cout << endl << endl << endl;

	/*for(int i = 0; i< M; i++){
		cout<< head->keys[i] << "At position" << i << endl;
		//cout << i << endl;
	}
	///cout << head->next<< endl;
	printLeaf((LeafNode*)(head->next[0]));
	printLeaf((LeafNode*)(head->next[1]));
	printLeaf((LeafNode*)(head->next[2]));
	printLeaf((LeafNode*)(head->next[3]));
	printLeaf((LeafNode*)(head->next[4]));
	printLeaf((LeafNode*)(head->next[5]));*/

}

void BTree::recPrint(BTreeNode* current, string str){
	if(current->isLeaf){
		printLeaf((LeafNode*)current);
		return;
	}
	for(int i = 0; i < current->numItems; i++){
		cout << "KEY: " << current->keys[i] << " at pos " << i << "|||";
		//recPrint(current->next[i], str + " ");
	}
	cout << endl;
	for(int i = 0; i < current->numItems; i++){
		recPrint(current->next[i], str+ " ");
	}

}


BTreeNode* BTree::percolate(string name, int position, BTreeNode* current){

	if(current->isLeaf){
		insertIntoLeafNode((LeafNode*)current,name,position);
		if(current->numItems > L){
			LeafNode* newLeaf = splitLeaf((LeafNode*)current);
			InnerNode* newInnerNode = new InnerNode();
			newInnerNode->keys[0] = newLeaf->data[0].name;
			newInnerNode->next[0] = current;
			//printLeaf((LeafNode*)newInnerNode->next[0]);
			newInnerNode->next[1] = newLeaf;
			newInnerNode->numItems = 2;
			head = (BTreeNode*)newInnerNode;
			//print(); 
			//printLeaf((LeafNode*)head->next[1]);
		}
		return NULL;
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
		//cout << current->numItems
		if(childNode->numItems > L){
			LeafNode* newLeaf = splitLeaf((LeafNode*)childNode);

			for(int j = M; j > i ; j--){
				current->next[j] = current->next[j-1];
			}

			for(int j = M-1; j>i; j--){
				current->keys[j] = current->keys[j-1];
			}

			current->next[i+1] = newLeaf;
			current->keys[i] = newLeaf->data[0].name;
			//cout << "Current numItems " << current->numItems << endl;
			current->numItems++;
		}

		if(current->numItems > M){
			//cout << "Need to split InnerNode";
			return splitInnerNode(current);
		}
		else
			return NULL;

	}
	else{
		BTreeNode* newNode = percolate(name, position, childNode);
		//cout<< "Call percolate?"<<endl;
		if(newNode == NULL)
			return NULL;

		for(int j = M; j > i ; j--){
			current->next[j] = current->next[j-1];
		}
		for(int j = M-1; j>i; j--){
			current->keys[j] = current->keys[j-1];
		}
		current->next[i+1] = newNode;
		current->keys[i] = childNode->keys[M/2];
		childNode->keys[M/2] = "";
		current->numItems++;
		if(current->numItems > M){
			return splitInnerNode(current);
		}
		else
			return NULL;

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
		node->next[i] = NULL;
		if(i < M){
			newNode->keys[i-half] = node->keys[i];
			node->keys[i] = "";
		}
	}
	//for( int i = 0; i < node->numItems - 1; i++){
		//cout << newNode->keys[i] << " TTT" << endl; 
		//cout << node->keys[i] << " TTTT" << endl;
	//}

	node->numItems= half;
	newNode->numItems= half; 

	return newNode; 

}

void BTree::printRange(string name1, string name2) {
	bool found1 = false;
	bool found2 = false;
	printRangeRec(name1, name2, head, &found1, &found2);
}

void BTree::printRangeRec(string name1, string name2, BTreeNode* current, bool* found1, bool* found2){

	if(current == NULL)
		return;
	if(current->isLeaf){
		for(int i =0; i< current->numItems; i++){
			if(current->data[i].name >= name1 && !*found1){
				*found1 = true;
				cout << current->data[i].name << " ";
				//printFunction(current->data[i].name);
			}
			else if(current->data[i].name >= name2 && !*found2){
				*found2 = true;
				if(current->data[i].name == name2){
					cout << current->data[i].name << " ";
					//printFunction(current->data[i].name);
				}
			}
			else if(*found1 && !*found2){
				cout << current->data[i].name << " ";
				//printFunction(current->data[i].name);
			}
		}
		cout<<endl;
		return;

	}

	int i = 0;
	while(current->keys[i] <= name1){
		i++;
		cout << "The val of i is " << i << endl;
		if(current->keys[i] == "")
			break;
	}
		printRangeRec(name1, name2, current->next[i], found1, found2);

	while(!*found2){
		i++;
		if(i > M)
			break;
		printRangeRec(name1, name2, current->next[i], found1, found2);
	}

}









