#include "HashTable.h"
//#include "Person.h"
#include "AdjList.h"
#include <iostream>
#include "ProfileData.h"
#include "BTree.h"

using namespace std;


int main(int argc, char const *argv[])
{

	
	BTree bTree = BTree();

	bTree.insert("Deanna", 0);
	//bTree.print();
	bTree.insert("Shreyas", 1);
	//bTree.print();
	bTree.insert("Alex",2);
	//bTree.print();
	bTree.insert("Angela",3);
	//bTree.print();
	bTree.insert("Carl",4);
	bTree.insert("Erin",5);
	bTree.insert("Frank",6);
	bTree.print();
	bTree.insert("Aaron", 7);
	bTree.print();
	bTree.insert("Zack",5);
	bTree.insert("Zebra",6);
	bTree.print();
	bTree.insert("Yeezus", 6);
	bTree.insert("Yolanda", 5);
	bTree.print();
	bTree.insert("Wilson",4);
	bTree.insert("Tommy",5);
	bTree.insert("Amr",6);
	bTree.insert("Victor",4);
	bTree.insert("Omid",5);
	bTree.insert("Franklin",6);
	bTree.insert("Sara",4);
	bTree.insert("Karl",5);
	bTree.insert("Erika",6);
	bTree.insert("Awesome",4);
	bTree.insert("Austin",5);
	bTree.insert("Brenda",6);
	bTree.insert("Brianna",4);
	bTree.insert("Charles",5);
	bTree.insert("Charmander",6);
	bTree.insert("Bulvasaur",4);
	bTree.insert("Charzard",5);
	bTree.insert("Brock",6);
	bTree.print();



	/*HashTable *table = new HashTable();
	ProfileData *profileData = new ProfileData(table); 

	AdjList *friends = new AdjList();
	friends->insert("Deanna"); friends->insert("Shreyas"); 
	friends->insert("Alex"); friends->insert("Angela");

	profileData->insert("Deanna", 21, "Student");
	table->insert("Deanna", friends, profileData->getPosition());
	
	profileData->insert("Shreyas", 19, "Student at UCSB");
	table->insert("Shreyas", friends, profileData->getPosition());
	
	profileData->insert("Alex", 19, "Another Student");
	table->insert("Alex", friends, profileData->getPosition());

	profileData->insert("Angela", 20, "Microsoft Intern");
	table->insert("Angela", friends, profileData->getPosition());

	table->print();


	profileData->getAge("Angela");
	profileData->getOccupation("Deanna");*/



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