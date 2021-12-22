//Program: linkfun.cpp
//Author: Mitchell Krystofiak
//Description: Implementation for node structure.
//Date: 09/29/2020

#include<iostream>
#include"link.h"

using namespace std;

node* createNode()
{
	node * newNode;
	cout << "Enter the last name: ";
	cin >> newNode->lastName;
	cout << "Enter the first name: ";
	cin >> newNode->firstName;
	cout << "Enter the ID number: ";
	cin >> newNode->idNumber;
	newNode->next=NULL;
	return newNode;
}

node* insertNode(node * head)
{
	node newNode = createNode();
	if (!head) //case for if list is empty
		return newNode;
	node * temp = head;
	else if (newNode->idNumber < head->idNumber)
	{
		newNode->next = head;
		return newNode;
	}
	while  (temp->next && newNode->idNumber >= temp->next->idNumber ) //case for if new Node idNumber is greater than the heads idNumber
	{
		temp = temp->next;
	}
	newNode->next = temp->next;
	temp->next  = newNode;
	return head;

}

node* searchNode()
{
	
}

node* deleteNode()
{
	
}

void printList(node * head)
{
	while(head)
	{
		cout << head->lastName << " " << head->firstName << " " << head->idNumber << endl;
		head = head->next;
	}
}

