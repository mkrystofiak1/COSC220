//Program: Lab7.cpp
//Author: Mitchell Krystofiak
//Description: Testing program of the binary search.
//Date: Novemeber 10, 2020

#include "BST.h"
#include <iostream>

using namespace std;

int main()
{
	BST newTree;
	int input, printOption, choice;
	while (true)
	{
		cout << "Select an option." << endl;
		cout << endl;
		cout << "1. Insert an element" << endl;
		cout << "2. Delete an element" << endl;
		cout << "3. Print the tree" << endl;
		cout << "4. Quit the program" << endl;
		cin >> input;
		while (input < 1 || input > 4)
		{
			cout << "Invalid input." << endl;
			cout << endl;
			cout << "Select an option." << endl;
                	cout << endl;
                	cout << "1. Insert an element" << endl;
                	cout << "2. Delete an element" << endl;
                	cout << "3. Print the tree" << endl;
                	cout << "4. Quit the program" << endl;
                	cin >> input;
		}
		if (input == 1)
		{
			cout << "What number would you like to insert?: ";
			cin >> choice;
			newTree.bstInsert(choice);
			cout << endl;
		}
		else if (input == 2)
		{
			cout << "What number would you like to delete?: ";
			cin >> choice;
			newTree.bstDelete(choice);
			cout << endl;
		}
		else if (input == 3)
		{
			cout << endl;
			cout << "Select a print order." << endl;
			cout << "1. InOrder" << endl;
			cout << "2. PostOrder" << endl;
			cout << "3. PreOrder" << endl;
			cin >> printOption;
			while (input < 1 || input > 3)
			{
				cout << "Invalid input." << endl;
				cout << endl;
				cout << "Select a print order." << endl;
				cout << "1. InOrder" << endl;
				cout << "2. PostOrder" << endl;
				cout << "3. PreOrder" << endl;
				cin >> printOption;
			}
			if (printOption == 1)
			{
				cout << endl;
				newTree.displayInOrder();
				cout << endl;
			}
			else if (printOption == 2)
			{
				cout << endl;
				newTree.displayPostOrder();
				cout << endl;
			}
			else if (printOption == 3)
			{
				cout << endl;
				newTree.displayPreOrder();
				cout << endl;
			}
		}
		else if (input == 4)
		{
			exit(0);
		}
	}

}
