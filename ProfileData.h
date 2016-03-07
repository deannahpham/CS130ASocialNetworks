#ifndef PROFILE_DATA
#define PROFILE_DATA
#include "HashTable.h"

#include <iostream>
#include <fstream>

using namespace std;

class ProfileData{

public:
	ProfileData(HashTable *table);
	void importFromFile(string fileName);
	void insert(string name, int age, string occupation);
	string extractData(string line, int *i);
	void addToProfileData(string name, int age, string occupation);
	int getPosition(){return position;};

private:
	fstream outFile;
	HashTable *table;
	int position;
	string profileDataFile;

};



#endif