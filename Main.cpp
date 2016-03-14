#include "HashTable.h"
//#include "Person.h"
#include "AdjList.h"
#include <iostream>
#include "ProfileData.h"
#include "BTree.h"
#include "Organizer.h"

using namespace std;


int main(int argc, char const *argv[])
{

	//What main should do:
	//Initialize the BTree, ProfileData, and HashTable
	//Make sure all these are connected and singleton'd 
	HashTable *table = new HashTable();
	ProfileData *profileData = new ProfileData(); 
	BTree *bTree = new BTree(); 

	Organizer organizer(bTree, profileData, table);

	organizer.importFromFile("Generated1.txt");


	try{
		while(true){
			string str;
			cin >> str;
			if(cin.eof()) break;
			if(str.compare("exit") == 0) break;
			else if(str.compare("insert") == 0){
				string line;
				getline(cin,line);
				organizer.insertFromString(line);
				//cout << "line is " << line << endl;
			}	
			else if(str.compare("printAll") == 0){
				organizer.printAll();
			}
			else if(str.compare("printBTree") == 0){
				bTree->print();
			}
			else if(str.compare("printTable") == 0){
				table->print();
			}
			else if(str.compare("addFriend") == 0){
				string line;
				getline(cin,line);
				//cout << line << endl;

				organizer.friendFromString(line);
			}
			else if(str.compare("listFriendInfo") == 0){
				string name;
				cin >> name;
				organizer.listFriendInfo(name);
			}
			else if(str.compare("listInfo") == 0){
				string line;
				getline(cin,line);
				//cout << line << endl;
				organizer.printRangeFromString(line);
			}
			cout << endl;
		}
	}
	catch(exception& ex){
		cerr << ex.what() << endl;
	}
	//organizer.printAll();
	//bTree->print();
	//table->print();
	//cout << "num Items: " << table->getNumItems() << endl;


	/*AdjList *friends = new AdjList();
	friends->insert("Deanna"); friends->insert("Shreyas"); 
	friends->insert("Alex"); friends->insert("Angela Yung");


	organizer.insert("Deanna Pham", 21, "Student", friends);
	organizer.insert("Alex", 19, "A student", friends);
	organizer.insert("Angela Yung", 20, "Microsoft intern",friends);
	organizer.insert("Shreyas", 19, "unemployed", friends);

	cout << "Deanna Pham's info: " << organizer.getAge("Deanna Pham") << "  " << organizer.getOccupation("Deanna Pham") << endl;
	cout << "Mary's info: " << organizer.getAge("Mary") << "  " << organizer.getOccupation("Mary") << endl;

	cout << "---------PRINTING THE HASHTABLE FROM HERE---------" << endl;
	table->print();
	cout << "---------PRINTING THE BTREE FROM HERE---------" << endl;
	bTree->print();
	organizer.listFriendInfo("Deanna Pham");
	organizer.addFriend("Deanna Pham", "Mary");
	organizer.listFriendInfo("Deanna Pham");
	organizer.printAll();
	organizer.printRange("Alex", "Shreyas"); 
	*/

	/*BTree bTree = BTree();

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
	bTree.printRange("a", "z");*/



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


