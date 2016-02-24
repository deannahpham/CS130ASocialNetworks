#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "Person.h"

using namespace std;

struct Node {
	Person person;
	string name;
};

class HashTable{
public:
	HashTable();
	void insert (string name, Person person);
	Person lookup(string name);
	void print();

private:
	Node* table;
	int size;
	int numItems;
	int hash(string name, int seed);
	bool isExist(string name);
};

#endif