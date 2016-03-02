#include "HashTable.h"
#include "Person.h"

int main(int argc, char const *argv[])
{
	/* code */
	HashTable *table = new HashTable();
	table -> insert("Deanna", *(new Person("Deanna", 21, "SWE")));
	table -> insert("Shreyas", *(new Person("Shreyas", 19, "Student")));
	table -> insert("Alex",  *(new Person("Alex", 19, "Student")));
	table -> print();

	table -> lookup("Alex").print();
}