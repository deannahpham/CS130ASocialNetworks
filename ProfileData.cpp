#include <iostream>
#include <stdio.h>
#include <fstream>

using namespace std; 

int main(int argc, char const *argv[])
{
	ofstream myfile;
	myfile.open("ProfileData.txt");
	myfile.write("Sam", 53);
	myfile << "hi" << endl;
	myfile.close();
	
	return 0;
}