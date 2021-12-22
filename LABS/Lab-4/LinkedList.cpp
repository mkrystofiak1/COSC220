//Program: LinkedList.cpp
//Author: Mitchell Krystofiak
//Description: Implementation file for LinkedList class.
//Date: 10/05/2020

#include "LinkedList.h"
#include<iostream>

using namespace std;

LinkedList::LinkedList()
{
	list = NULL;
}

LinkedList::~LinkedList()
{
	Node * nodePtr;
	Node * nextNode;

	nodePtr = list;
	while (nodePtr != NULL)
	{
		nextNode = nodePtr->next;
		delete nodePtr;
		nodePtr = nextNode;
	}	
}

Node * LinkedList::createNode()
{
	Node * newNode = new Node;
	return newNode;
}

Node * LinkedList::searchLocation(int number)
{
	Node * nodePtr;
	Node * previous = NULL;

	if (!list) //return NULL if list is empty
	{
		return NULL;
	}
	else
	{
		nodePtr = list;
		while (nodePtr != NULL && nodePtr->idNumber < number)
		{
			previous = nodePtr;
			nodePtr = nodePtr->next;
		}
		if (nodePtr != NULL && nodePtr->idNumber == number)
		{
			return nodePtr;
		}
		return previous;

	}
}		

void LinkedList::insertNode()
{
	Node * newNode = createNode();
	Node * location = searchLocation(newNode->idNumber);
	Node * nodePtr;
	if (!list) //if list is empty
	{
		list = newNode;
		newNode->next = NULL;
		cout << endl;
	}
	else 
	{	
		if (location == NULL)
		{
			newNode->next = list;
			list = newNode;
		}
		else if (location->idNumber == newNode->idNumber)
		{
			cout << "Node with student ID already exists, quiting insertion. " << endl;
                        cout << endl;
		}
		else
		{
			newNode->next = location->next;
			location->next = newNode;
			cout << endl;
		}
	}
	//need to check for same number
}

void LinkedList::deleteNode(int number)
{
	Node * location = searchLocation(number);
	Node * nodePtr;
	Node * previous;
	cout << endl;

	if (!list) 
	{
		cout << "List is empty." << endl;
		cout << endl;
	}
	else if (location == NULL || location->idNumber != number)
	{
		cout << "Node with Student ID " << number << " does not exist." << endl;
		cout << endl;
	}
	else
	{
		if (location->idNumber == list->idNumber) //case for if ==list
		{
			nodePtr = list->next;
			delete list;
			list = nodePtr;
		}
		else 
		{
			nodePtr = list;
			while (nodePtr != NULL && nodePtr->idNumber != number)
			{
				previous = nodePtr;
				nodePtr = nodePtr->next;
			}
			if (nodePtr)
			{
				previous->next = nodePtr->next;
				delete nodePtr;
			}
		}

	}
}

void LinkedList::printList()
{
	int counter = 0;
	Node * temp = list;
	cout << endl;
	if(!temp) //if list is null, list is empty
	{
		cout<< "List is empty." << endl;
	}
	while(temp)//if list is not null, use printNode() function until null
	{
		
		counter++;
		cout << counter << ". ";
		temp->printNode();
		temp = temp->next;
	}
	cout << endl;
}

void LinkedList::searchNode()
{
	int number;
	cout << "What is the student ID of the node you would like to search for?: ";
	cin >> number;
	Node * location = searchLocation(number);
	cout << endl;

	if (!list)
	{
		cout << "List is empty." << endl;
		cout << endl;
	}
	else if (location == NULL || location->idNumber != number)
	{
		cout << "Node with Student ID " << number << " does not exist." << endl;
		cout << endl;
	}
	else
	{
		cout << "Student ID " << number << " belongs to " << location->firstName << " " << location->lastName << endl;
		cout << endl;
	}
	
}
