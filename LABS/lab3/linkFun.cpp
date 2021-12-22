//Program: linkFun.cpp
//Author: Mitchell Krystofiak
//Description: Program file for functions for linked list.
//Date: 09/29/2020

#include<iostream>
#include"link.h"

using namespace std;

node* createNode()
{
    cout << "\n";
    node* newNode = new node;
    cout << "Enter the first name: ";
    cin >> newNode->firstName;
    cout << "Enter the last name: ";
    cin >> newNode->lastName;
    cout << "Enter the student ID number: ";
    cin >> newNode->idNumber;
    newNode->next=nullptr;
    cout << "\n";
    return newNode;
}

node* insertNode(node * head)
{
    node* newNode = createNode();
    node* temp = head;
    if(!head) //case for if list is empty
        return newNode;
    if(newNode->idNumber < head->idNumber) //case for if new node is smaller than head
    {
        newNode->next = head;
        return newNode;
    }

    while(temp->next && newNode->idNumber >= temp->next->idNumber) //case for if new node is larger than head
        temp = temp->next;
    newNode->next = temp->next;
    temp->next = newNode;
    return head;

    cout << "\n";
}

node* searchNode(node* head, int number)
{
    cout << "\n";
    node* nodePtr;
    node* previous;
    int counter = 1;
    if(!head)//checking if list is empty
    {
        cout << "List is empty." << endl;
        cout << "\n";
        return head;
    }
    if(head->idNumber == number)//if first node is the searching node
    {
        cout << "ID number " << number << " belongs to " << head->firstName << " " << head->lastName << " at position " << counter << "." << endl;
        cout << "\n";
        return head;
    }
    else
    {

        nodePtr = head;
        while (nodePtr != nullptr && nodePtr->idNumber != number)
        {
            counter++;
            previous = nodePtr;
            nodePtr = nodePtr->next;
        }
        if (nodePtr)
        {
            cout << "ID number " << number << " belongs to " << nodePtr->firstName << " " << nodePtr->lastName << " at position " << counter << "." << endl;
            cout << "\n";
            return head;
        }
        else
        {
            cout << "No node holds student ID " << number << ". Returning to menu." << endl;
            cout << "\n";
            return head;
        }
    }

}

node* deleteNode(node* head, int number)
{
    node* nodePtr;
    node* previous;
    if (!head) //checking if list is empty
    {
        cout << "List is empty." << endl;
        cout << "\n";
        return head;
    }
    if(head->idNumber == number) //if first node is equal to the one wanted to be deleted
    {
        nodePtr = head->next;
        delete head;
        head = nodePtr;
        cout << "\n";
        return head;
    }
    else
    {
        nodePtr = head;
        while (nodePtr != nullptr && nodePtr->idNumber != number)
        {
            previous = nodePtr;
            nodePtr = nodePtr->next;
        }
        if (nodePtr)
        {
            previous->next = nodePtr->next;
            delete nodePtr;
            cout << "\n";
            return previous;
        }
        else
        {
            cout << "No node holds student ID " << number << ". Returning to menu." << endl;
            cout << "\n";
            return head;
        }
    }
}
void printList(node *head)
{
    int counter = 0;
    cout << "\n";
    if (!head)
    {
        cout << "List is empty." << endl;
    }
    while(head)
    {
        counter++;
        cout << counter << "- " << head->firstName << " " << head->lastName << " " << head->idNumber << endl;
        head = head->next;
    }
    cout << "\n";
}
