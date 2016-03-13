#include "HashTable.h"
#include "Person.h"
#include <iostream>

using namespace std;

HashTable::HashTable() {
	size = 211; 
	numItems = 0; 
	table = new DataNode[size];
	for(int i = 0; i < size; i++){
		DataNode n = DataNode();
		n.position = -1;
		n.name = "";
		n.friends = NULL;
		table[i]=n;
	}
}

int HashTable::hash(string name, int seed = 0){
	int hash = seed;
	for (int i = 0; i< (int)name.length(); i++){
		hash = (hash * 101 + name[i])%size;
	}
	return hash;
}

int HashTable::isExist(string name){
	int pos = hash(name);
	for(int i = pos; i< 211; i++){
		if (table[pos].name == name)
			return pos;
		if(table[pos].name == "")
			return -1;
	}

	for(int i = 0; i < pos; i++){
		if (table[pos].name == name)
			return pos;
		if(table[pos].name == "")
			return -1;
	}

	return -1;
}

void HashTable::insert(string name, AdjList *friends, int position) {
	if(isExist(name) != -1){
		std::cout << "person already present" << std::endl;
		return;
	}

	int pos = hash(name);
	for(int i = pos; i < 211; i++){
		//int pos = hash(name, i);
		if (table[pos].name == ""){
			table[pos].name = name;
			table[pos].position = position;
			table[pos].friends = friends;
			return;
		}
	}	

	for(int i = 0; i < pos; i++){
		if (table[pos].name == ""){
			table[pos].name = name;
			table[pos].position = position;
			table[pos].friends = friends;
			return;
		}
	}

}


DataNode HashTable::lookup(string name){
	int pos = isExist(name);

	if(pos != -1)
		return table[pos];
	else{
		cout << "Cannot find " << name;
		return DataNode();
	}

	/*for(int i = 0; i< 211; i++){
		int pos = hash(name, i);
		if (table[pos].name == name){
			return table[pos].person;
		}
		if(table[pos].name == "")
			return Person();
	}

	return Person();*/

}

void HashTable::print(){
	for(int i = 0; i < size; i++) {
		if(table[i].name == "")
			continue;
		cout<<"(" << table[i].name << "," << table[i].position << ", [";
		
		table[i].friends->print();

		cout << "])" << endl;
	}
}

DataNode* HashTable::getTable(){
	return table;
}
















