//Program: linkedList.cpp
//Author: Mitchell Krystofiak
//Description: Main file with menu options for creating a linked list.
//Date: 09/29/2020

#include<iostream>
#include"link.h"

using namespace std;

int main()
{
	cout << "Please select an option." << endl;
	cout << endl;
	cout << "1. Insert a node" << endl;
	cout << "2. Delete a node" << endl;
	cout << "3. Print List" << endl;
	cout << "4. Search a node" << endl;
	cout << "5. Quit the program" << endl;
	node * head = createNode();
	head = insertNode(head);
	return 0;
}
