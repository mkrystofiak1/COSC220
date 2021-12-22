//Program: link.h
//Author: Mitchell Krystofiak
//Description: Create node structure.
//Date: 09/29/2020

#include<iostream>
struct node 
{
	char lastName[20];
	char firstName[20];
	int idNumber;
	node *next;
};

//function prototypes

node* createNode();
node* insertNode(node *);
node* searchNode(node *);
node* deleteNode(node *, int);
void printList(node *);
