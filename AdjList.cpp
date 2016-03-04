#include "AdjList.h"
#include <iostream>
#include <string>

using namespace std;

AdjList::AdjList(){
	head = NULL;
}

void AdjList::insert(string name){
	FriendNode *newFriend = new FriendNode();
	newFriend->name = name;

	if(head == NULL){
		newFriend->next = NULL;
		head = newFriend;
	}
	else {
		newFriend->next = head;
		head = newFriend;
	}
}

void AdjList::print(){
	for(FriendNode* current = head; current != NULL; current = current->next){
		cout << current->name << ", ";
	}
}