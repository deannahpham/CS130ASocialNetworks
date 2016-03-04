#ifndef ADJLIST_H
#define ADJLIST_H

struct FriendNode {
	FriendNode *next;
	string name;
};


class AdjList {
public:
	AdjList();


private:
	FriendNode *head;

}