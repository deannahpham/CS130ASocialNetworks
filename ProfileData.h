#ifndef PROFILE_DATA
#define PROFILE_DATA
#include "HashTable.h"
//#include "BTree.h"

#include <iostream>
#include <fstream>

using namespace std;

class ProfileData{

public:
	ProfileData();
	void insert(string name, int age, string occupation);
	void addToProfileData(string name, int age, string occupation);
	int getPosition(){return position;};

	int getAge(int pos);
	string getOccupation(int origPos);


private:
	fstream outFile;
	int position;
	string profileDataFile;

};



#endif