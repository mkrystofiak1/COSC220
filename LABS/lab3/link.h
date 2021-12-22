//Program: link.h
//Author: Mitchell Krystofiak
//Description: Create node structure.
//Date: 09/29/2020

#ifndef LINK_H
#define LINK_H

#include<iostream>

struct node
{
    char lastName[20];
    char firstName[20];
    int idNumber;
    node *next;
};

//Prototypes

node* createNode();
node* insertNode(node*);
node* searchNode(node*, int number);
node* deleteNode(node*, int number);
void printList(node*);

#endif


