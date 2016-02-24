#ifndef PERSON_H
#define PERSON_H

#include <string>

using namespace std;

class Person {
public:
	Person();
	Person(string name, int age, string occupation);
	string getName();
	int getAge();
	string getOccupation();

private:
	string name;
	int age;
	string occupation;
};

#endif