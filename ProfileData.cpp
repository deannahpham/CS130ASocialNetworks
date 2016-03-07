#include "ProfileData.h"
#include <iostream>
#include <fstream>
#include "AdjList.h"
#include "HashTable.h"
//#include <cstring>

using namespace std;

ProfileData::ProfileData(HashTable *table) {
	
	profileDataFile = "ProfileData.txt";

	outFile.open(profileDataFile, ios::app);
	this->table = table;
	position = 0; 

	importFromFile("input.txt");
}

string ProfileData::extractData(string line, int *i){
	//string line = myLine;
	int j = *i;
	string result = ""; 
	for(j = j + 0; line.at(j) != ','; j++ ){
		result = result + line.at(j);
		if(j >= (int)line.length()-1)
			break;
	}
	*i = j;
	return result;
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

	//outFile.seekp(pos);
	//outFile<< name << " ";
	//outFile.seekp(pos + 20 - name.length());
	//string agestr = to_string(age);
	//outFile << age << " ";
	//outFile.seekp(pos + 3 - agestr.length());
	//outFile << endl;
	//outfile.close();
}

void ProfileData::importFromFile(string fileName){
	ifstream file (fileName, ios::in);

	while(!file.eof()){
		string line;
		if(file.is_open()){
			//cout<< file.tellg() <<endl;
			//file.seekg(0);
			getline(file,line);
			cout << line;
		}
		else {
			cout <<"error" <<endl;
		}
		int i = 0;

		string name = extractData(line, &i);
		cout << name << endl;
		i++;
		int age = stoi(extractData(line, &i));
		cout << age << endl;
		i++;
		string occupation = extractData(line,&i);
		cout << occupation << endl;
		i++;

		addToProfileData(name, age, occupation);

		AdjList* friends = new AdjList();
		while(i < (int)line.length()){
			string frnd = extractData(line, &i);
			i++;
			friends->insert(frnd);
		}
		friends->print();

		table->insert(name, friends, position);
		position++;
	}

	cout << endl;
	table -> print();
}

void ProfileData::insert(string name, int age, string occupation){

	if(table->isExist(name) == -1){
		cout << "adding " << name << endl;
		addToProfileData(name, age, occupation);
		position++;
	}
	else {
		std::cout << "person already present " << name << std::endl;
		return;
	}


}







