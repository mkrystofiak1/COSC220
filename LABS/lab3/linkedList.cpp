//Program: linkedList.cpp
//Author: Mitchell Krystofiak
//Description: Menu options for the linked list structure.
//Date: 09/29/2020

#include <iostream>
#include "link.h"

using namespace std;

int main()
{
    int option = 0;
    int number;
    node *head = nullptr;
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
        while (option < 1 || option > 5)
        {
            cout << "Option is invalid. Please select between option 1 and 5: ";
            cin >>option;
        }

        if (option == 1)
        {
            head = insertNode(head);
        }
        else if (option == 2)
        {

            cout << "What is the student ID of the node you would like to delete?: ";
            cin >> number;
            head = deleteNode(head,number);
        }
        else if (option == 3)
        {
            printList(head);
        }
        else if (option == 4)
        {
            cout << "What is the student ID of the node you would like to search for?: ";
            cin >> number;
            head = searchNode(head, number);
        }
        else if (option ==5)
            exit(1);

    }

    return 0;
} 
