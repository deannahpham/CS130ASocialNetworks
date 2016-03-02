#include "Person.h"
#include "HashTable.h"
#include <iostream>

using namespace std;

Person::Person() {
	this->name = "";
	this->age = -1;
	this->occupation = "";
}

Person::Person(string name, int age, string occupation) {
	this->name = name; 
	this->age = age;
	this->occupation = occupation;
}

string Person::getName() {
	return this->name;
}

int Person::getAge(){
	return this->age;
}

string Person::getOccupation() {
	return this->occupation;
}

void Person::print(){
	cout << "Name: " << name << " Age: " << age << " Occupation: " << occupation << endl;
}

int Person::getLocation(string name) {
	return location = hash(name);
}