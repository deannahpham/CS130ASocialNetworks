#include "HashTable.h"
#include "Person.h"

using namespace std;

HashTable::HashTable() {
	size = 201; 
	numItems = 0; 
	table = new Node[size];
	for(int i = 0; i < size; i++){
		Node n = Node();
		n.person = Person();
		n.name = "";
		table[i]=n;
	}
}

int HashTable::hash(string name, int seed = 0){
	int hash = seed;
	for (int i = 0; i< name.length(); i++){
		hash = hash * 101 + name[i];
	}
	return hash % size;
}

bool HashTable::isExist(string name){
	for(int i = 0; i< 201; i++){
		int pos = hash(name, i);
		if (hash[pos]->name == name){
			return true;
		}
		if(hash[pos]->name == "")
			return false
	}

	return false;
}

void HashTable::insert(string name, Person person) {
	if(isExist(name)){
		cout<< "person already present" << endl;
		return;
	}

	for(int i = 0; i < 201; i++){
		int pos = hash(name, i);
		if (table[pos]->name == ""){
			table[pos]-> = name;
			table[pos]-> person = person;
			break;
		}
	}	

}


Person HashTable::lookup(string name){
	for(int i = 0; i< 201; i++){
		int pos = hash(name, i);
		if (hash[pos]->name == name){
			return hash[pos]->person;
		}
		if(hash[pos]->name == "")
			return NULL;
	}

	return NULL;

}

void HashTable::print(){
	for(int i = 0; i < size; i++) {
		if(table[i]->name == "")
			continue;
		cout<<"(" << table[i].name << "," << table[i].person.getAge() << "," << table[i].person.getOccupation() << ")" << endl;
	}
}
















