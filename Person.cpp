#include "Person.h"

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