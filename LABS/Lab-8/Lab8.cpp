//Program: Lab8.cpp
//Author: Mitchell Krystofiak
//Description: Test file for the heap class.
//Date: November 24, 2020

#include"Heap.h"
#include<iostream>
/*
 * 
    Insert element into the heap.
    Maximum Value
    Extract maximum element from the heap
    Print heap
    Heap Sort, Print sorted results and exit.
 */

using namespace std;

int main()
{
	Heap Test;
	int input;

	while(true)
	{
		int choice = 0;
		while(choice < 1 || choice > 6)
		{
			cout << "Select an option." << endl;
			cout << endl;
			cout << "1. Insert element" << endl;
			cout << "2. Maximum value" << endl;
			cout << "3. Extract maximum" << endl;
			cout << "4. Print heap" << endl;
			cout << "5. Sort heap" << endl;
			cout << "6. Quit" << endl;
			cin >> choice;
		}
		if (choice == 1)
		{
			cout << endl;
			cout << "Enter number to insert: ";
			cin >> input;
			Test.insert(input);
			cout << endl;
		}
		else if (choice == 2)
		{
			cout << endl;
			cout << "The maximum element is " << Test.maximum() << "." << endl;
			cout << endl;
		}
		else if (choice == 3)
		{
			cout << endl;
			cout << "The maximum element is " << Test.maximum() << "." << endl;
			Test.extractMax();
			cout << "The new maximum element is " << Test.maximum() << "." << endl;
			cout << endl;
		}
		else if (choice == 4)
		{
			cout << endl;
			cout << "The heap in Array format: ";
		       	Test.printHeap();
			cout << endl;
		}
		else if (choice == 5)
		{
			cout << endl;
			cout << "The heap in Array format before sort: ";
		       	Test.printHeap();
			Test.heapSort();
			cout << "The heap in Array format after sort: ";
			Test.printHeap();
			cout << endl;
		}
		else if (choice == 6)
		{
			exit(1);
		}	
			
	}	
	return 0;
}
