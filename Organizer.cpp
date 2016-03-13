//STUB
#include <iostream>
#include <fstream>


#include "Organizer.h"
#include "BTree.h"
#include "ProfileData.h"
#include "HashTable.h"
#include "AdjList.h"

using namespace std;

Organizer::Organizer(BTree *bTree,	ProfileData *profileData, HashTable *table){
	this->bTree = bTree;
	this->profileData = profileData;
	this->table = table;
}

void Organizer::importFromFile(string fileName){
	ifstream file (fileName, ios::in);

	while(!file.eof()){
		string line;
		if(file.is_open()){
			//cout<< file.tellg() <<endl;
			//file.seekg(0);
			getline(file,line);
			//cout << line;
		}
		else {
			cout <<"error" <<endl;
		}
		int i = 0;

		string name = extractData(line, &i);
		//cout << name << endl;
		i++;
		int age = stoi(extractData(line, &i));
		//cout << age << endl;
		i++;
		string occupation = extractData(line,&i);
		//cout << occupation << endl;
		i++;

		profileData->insert(name, age, occupation);

		AdjList* friends = new AdjList();
		while(i < (int)line.length()){
			string frnd = extractData(line, &i);
			i++;
			friends->insert(frnd);
		}
		//friends->print();

		bTree->insert(name, profileData->getPosition()-1);
		table->insert(name, friends, profileData->getPosition()-1);
		//position++;
	}

	cout << endl;
	//table -> print();
	//position--;
}

string Organizer::extractData(string line, int *i){
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

int Organizer::getAge(string name){
	return profileData->getAge(table->lookup(name).position);
}

string Organizer::getOccupation(string name){
	return profileData->getOccupation(table->lookup(name).position);
}

void Organizer::insert(string name, int age, string occupation, AdjList* friends){
	//Insert into ALL DataStructures 
	if(table->isExist(name) == -1){
		profileData->insert(name, age, occupation);
		bTree->insert(name, profileData->getPosition()-1);
		table->insert(name, friends, profileData->getPosition()-1);
	}
	else{
		cout << name << " already exists in the table" << endl;
	}
}

void Organizer::addFriend(string name1, string name2){
	if(table->isExist(name1) == -1 || table->isExist(name2) == -1){
		cout << "Person does not exists, cannot add friend" << endl;
		return;
	}
	//FIX LATER ifname2 is already a friend of name1
	table->lookup(name1).friends->insert(name2);
	table->lookup(name2).friends->insert(name1);

}

void Organizer::listFriendInfo(string name){
	if(table->isExist(name) == -1)
		return;

	FriendNode* head = table->lookup(name).friends->head;

	cout << name << "'s friend's information: ";

	for(FriendNode* i = head; i != NULL; i = i->next){
		string name = i->name;
		int age = getAge(name);
		string occupation = getOccupation(name);
		cout << name << ": " << age << " " << occupation;
	}	
	cout << endl;
}

void Organizer::printAll(){
	DataNode* hashTable = table->getTable();
	for(int i = 0; i < 211; i++){
		if(hashTable[i].name != ""){
			string name = hashTable[i].name;
			cout << name << ": " << getAge(name) << ", " << getOccupation(name) << ", ";
			hashTable[i].friends->print(); 
			cout << endl;
		}
	}

}













