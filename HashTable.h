#ifndef HASHTABLE_H
#define HASHTABLE_H
//#include "Person.h"
#include "AdjList.h"

using namespace std;

struct DataNode {
	AdjList* friends;
	int position;
	string name;

};

class HashTable{
public:
	HashTable();
	void insert (string name, AdjList *friends, int position);
	DataNode lookup(string name);
	void print();

private:
	DataNode* table;
	int size;
	int numItems;
	int hash(string name, int seed);
	int isExist(string name);
};

#endif