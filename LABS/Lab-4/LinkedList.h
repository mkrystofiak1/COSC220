//Program: LinkedList.h
//Author: Mitchell Krystofiak
//Description: Header file for LinkedList class.
//Date: 10/05/2020

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"
#include<iostream>

using namespace std;

class LinkedList 
{
private:
	Node * list;
//prototypes
	Node * createNode();
	Node * searchLocation(int idNumber);

public:
//constructor
	LinkedList();
//deconstructor
	~LinkedList();
//prototypes
	void insertNode();
	void deleteNode(int idNumber);
	void printList();
	void searchNode();
};
#endif
