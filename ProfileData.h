#ifndef PROFILE_DATA
#define PROFILE_DATA

#include <iostream>
#include <fstream>

using namespace std;

class ProfileData{

public:
	ProfileData();
	void importFromFile(string fileName);
	void insert(string name, int age, string occupation);
	string extractData(string line, int *i);

	void addToProfileData(string name, int age, string occupation, int position);


private:
	fstream outFile;

};



#endif