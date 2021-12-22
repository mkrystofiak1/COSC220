//Program: Node.h
//Author: Mitchell Krystofiak
//Description: Header file for Node class.
//Date: 10/05/2020

#ifndef NODE_H
#define NODE_H
#include<iostream>

using namespace std;

class Node {

public:
	char lastName[20];
	char firstName[20];
	int idNumber;
	Node * next;

// constructor
	Node();

	void printNode();

};
#endif
