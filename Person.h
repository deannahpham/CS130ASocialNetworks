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
	void print();
	/*int getLocation(string name); 
	
	struct Node{
		string name;
		struct Node *next = NULL;
	};*/

private:
	string name;
	int age;
	string occupation;
	//int location;

};

#endif