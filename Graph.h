#ifndef GRAPH_H
#define GRAPH_H

using namespace std;


class Graph{

public:

	struct Node {
		string name;
		struct Node *next = NULL; 
	};

	int location;
	Graph();
	Graph(string name); 

	void addToGraph(string name); 

};

#endif