#include "HashTable.h"
//#include "Person.h"
#include "AdjList.h"
#include <iostream>

using namespace std;


int main(int argc, char const *argv[])
{

	HashTable *table = new HashTable();

	AdjList *friends = new AdjList();
	friends->insert("Deanna"); friends->insert("Shreyas"); 
	friends->insert("Alex"); friends->insert("Angela");

	table->insert("Deanna", friends, 1);
	table->insert("Shreyas", friends, 2);
	table->insert("Alex", friends, 3);
	table->insert("Angela", friends, 4);
	table->print();


	/* 
	HashTable *table = new HashTable();

	FriendNode *deannaFriends = new FriendNode();
	//deannaFriends.head = NU

	FriendNode *deannaFriend1 = new FriendNode();

	table -> insert("Deanna", *(new Person("Deanna", 21, "SWE")));
	table -> insert("Shreyas", *(new Person("Shreyas", 19, "Student")));
	table -> insert("Alex",  *(new Person("Alex", 19, "Student")));
	table -> print();

	table -> lookup("Alex").print();*/
}