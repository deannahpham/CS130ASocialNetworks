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

	bTree.insert("deanna", 0);
	//bTree.print();
	bTree.insert("shreyas", 1);
	//bTree.print();
	bTree.insert("alex",2);
	//bTree.print();
	bTree.insert("angela",3);
	//bTree.print();
	bTree.insert("carl",4);
	bTree.insert("erin",5);
	bTree.insert("frank",6);
	bTree.print();
	bTree.insert("aaron", 7);
	bTree.print();
	bTree.insert("zack",5);
	bTree.insert("zebra",6);
	bTree.print();
	bTree.insert("yeezus", 6);
	bTree.insert("yolanda", 5);
	bTree.print();
	bTree.insert("wilson",4);
	bTree.insert("tommy",5);
	bTree.insert("amr",6);
	bTree.insert("victor",4);
	bTree.insert("omid",5);
	bTree.insert("franklin",6);
	bTree.insert("sara",4);
	bTree.insert("karl",5);
	bTree.insert("erika",6);
	bTree.insert("awesome",4);
	bTree.insert("austin",5);
	bTree.insert("brenda",6);
	bTree.insert("brianna",4);
	bTree.insert("charles",5);
	bTree.insert("charmander",6);
	bTree.insert("bulvasaur",4);
	bTree.insert("charzard",5);
	bTree.insert("brock",6);
	bTree.print();
	bTree.printRange("amr", "carl");



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