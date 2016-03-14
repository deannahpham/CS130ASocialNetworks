#include "ProfileData.h"
#include <iostream>
#include <fstream>
#include "AdjList.h"
#include "HashTable.h"
//#include "BTree.h"
//#include <cstring>

using namespace std;

ProfileData::ProfileData() {

	
	profileDataFile = "ProfileData.txt";
	outFile.open(profileDataFile);
	outFile.clear();

	//this->table = table;
	position = 0; 
}


void ProfileData::addToProfileData(string name, int age, string occupation){

	//ofstream myfile;
	//int pos = position*53;
	outFile << name;
	for(int i = name.length(); i < 20; i++) {
		outFile << " ";
	}
	outFile << age;
	for(int i = to_string(age).length(); i < 3; i++){
		outFile << " ";
	}
	outFile << occupation;
	for (int i = occupation.length(); i < 30; i++) {
		outFile << " ";
	}
	outFile << endl;
}

void ProfileData::insert(string name, int age, string occupation){

	//cout << "adding " << name << endl;
	addToProfileData(name, age, occupation);
	position++;

}

int ProfileData::getAge(int pos){
	pos = pos*54+20;

	int age;
	outFile.seekg(pos);
	outFile >> age;
	//cout << age << endl;
	return age;
}

string ProfileData::getOccupation(int origPos){
	//int origPos = table->lookup(name).position;
	//cout << "Alex pos " << origPos << endl;
	int pos = origPos*54+23;
	outFile.seekg(pos);


	string occupation = "";

	getline(outFile,occupation);


	/*string part;

	while(outFile.tellg() < pos+30){
		cout << outFile.tellg() << endl;
		outFile >> part;
		cout << outFile.tellg() << endl;
		occupation = occupation + part + " ";
		//cout << occupation;
	}*/

	//cout<< occupation<< endl;
	return occupation;
}
















