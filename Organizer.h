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

private:
	string extractData(string line, int *i);


	BTree *bTree;
	ProfileData *profileData;
	HashTable *table;

};


#endif