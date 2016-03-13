//STUB
#ifndef ORGANIZER
#define ORGANIZER

#include <iostream>
#include <fstream>


#include "Organizer.h"
#include "BTree.h"
#include "ProfileData.h"
#include "HashTable.h"
#include "AdjList.h"

using namespace std;

class Organizer{
public: 
	Organizer(BTree *bTree,	ProfileData *profileData, HashTable *table);
	void importFromFile(string fileName);
	int getAge(string name);
	string getOccupation(string name);
	void insert(string name, int age, string occupation, AdjList* friends);
	void addFriend(string name1, string name2); 
	void listFriendInfo(string name);
	void printAll();
	//void printInfo(string name);
	void printRange(string name1, string name2);
	void printRangeRec(string name1, string name2, BTreeNode* current, bool* found1, bool* found2);

private:
	string extractData(string line, int *i);
	int L = 3;
	int M = 5;

	BTree *bTree;
	ProfileData *profileData;
	HashTable *table;

};


#endif