#ifndef PROFILE_DATA
#define PROFILE_DATA

#include <iostream>
#include <fstream>

class ProfileData{

public:
	ProfileData();
	importFromFile(string fileName);
	insert(string name, int age, string occupation);

private:


};



#endif