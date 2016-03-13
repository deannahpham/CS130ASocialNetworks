#ifndef ADJLIST_H
#define ADJLIST_H

#include <string>

using namespace std;

struct FriendNode {
	FriendNode *next;
	string name;
};


class AdjList {
public:
	AdjList();
	void insert(string name);
	void print();
	FriendNode *head;

};

#endif