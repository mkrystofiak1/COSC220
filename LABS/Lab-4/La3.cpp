//Program: La3.cpp
//Author: Mitchell Krystofiak
//Description: Main file for the node Linked List class.
//Date: 10/05/2020

#include "LinkedList.h"
#include<iostream>

using namespace std;

int main()
{
	int option = 0;
	int number;

	LinkedList * list1 = new LinkedList;
	
	cout << "Please select an option." << endl;
	cout << endl;
	
	while(true)
	{
		cout << "1. Insert a node" << endl;
        	cout << "2. Delete a node" << endl;
        	cout << "3. Print list" << endl;
        	cout << "4. Search a node" << endl;
        	cout << "5. Quit the program" << endl;
        	cin >> option;
        	while (option < 1 || option > 5) //invalid input
        	{
            		cout << "Option is invalid. Please select between option 1 and 5: ";
            		cin >>option;
        	}
		
		if (option == 1) //insert node option
		{
			list1->insertNode();
		}
		
		else if (option == 2) //delete node option
		{
			cout << "What is the student ID of the node you would like to delete?: ";
			cin >> number;
			list1->deleteNode(number);
		}

		else if (option == 3) //print list option
		{
			list1->printList();
		}

		else if (option == 4) //search node option
		{
			list1->searchNode();
		}

		else if (option == 5) //quit option
			exit(1);

	}
	return 0;

}
