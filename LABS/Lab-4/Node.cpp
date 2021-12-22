//Program: Node.cpp
//Author: Mitchell Krystofiak
//Description: Implementation file for Node class.
//Date: 10/05/2020

#include "Node.h"
#include <iostream>
using namespace std;

Node::Node()
{
	cout << "What is the student's first name?: ";
	cin >> firstName;
	cout << "what is the student's last name?: ";
	cin >> lastName;
	cout << "What is the student's ID number?: ";
	cin >> idNumber;
	next = NULL;
}

void Node::printNode()
{
	cout << firstName << " " << lastName << " " << idNumber << endl;
}
