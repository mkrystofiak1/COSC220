//Program: Lab5.cpp
//Author: Mitchell Krystofiak
//Description: Test program for the Queue class using the Student structure.
//Date: October 27, 2020

#include "Students.h"
#include "Queue.h"
#include<iostream>

using namespace std;

int main()
{
	Queue<Students*> squeue; //a queue with Student Data Type
	Queue<int> iqueue;	 //a queue with integer Data Type
	
	int option;
	int whichQueue;
	cout << "Which queue do you want to work with?" << endl;
        cout << endl;
        cout << "1. Integer" << endl;
        cout << "2. Student*" << endl;
        cin >> whichQueue;
        while (whichQueue < 1 || whichQueue > 2)
        {
                cout << "Invalid option." << endl;
                cout << endl;
                cout << "Which queue do you want to work with?" << endl;
                cout << endl;
                cout << "1. Integer" << endl;
                cout << "2. Student*" << endl;
                cin >> whichQueue;
        }

	while (true)//loop for options
	{
		cout << endl;
		cout << "Please select an option." << endl;
		cout << endl;
		cout << "1. enQueue" << endl;
		cout << "2. deQueue" << endl;
		cout << "3. topQueue" << endl;
		cout << "4. Switch Queue" << endl;
		cout << "5. quit" << endl;
		cin >> option;
		while (option < 1 || option > 5)
                {
			cout << "Invalid option." << endl;
                        cout << endl;
                        cout << "Please select an option." << endl;
                        cout << endl;
                        cout << "1. enQueue" << endl;
                        cout << "2. deQueue" << endl;
                        cout << "3. topQueue" << endl;
			cout << "3. Switch Queue" << endl;
                        cout << "5. quit" << endl;
                        cin >> option;
                }

		if (whichQueue == 2)
		{
			if (option == 1)
			{
				Students * newStudent = new Students;
				squeue.enQueue(newStudent);
			}
			else if (option == 2)
			{
				squeue.deQueue();
			}
			else if (option == 3)
			{
				cout << endl;
				if (squeue.topQueue() == NULL)
					cout << "Queue is empty!" << endl;
				else 
					squeue.topQueue()->printStudent();
				cout << endl;
			}
			else if (option == 4)
			{
				cout << "Switching from Student* queue to int queue." << endl;
				whichQueue = 1;
			}
			else if (option == 5)
			{
				exit(0);
			}
		}
		else if (whichQueue == 1)
		{
			if (option == 1)
			{
				int integer;
				cout << "Enter an integer: ";
				cin >> integer;
				iqueue.enQueue(integer);
			}
			else if (option == 2)
			{
				iqueue.deQueue();
			}
			else if (option == 3)
			{
				cout << endl;
				if (iqueue.topQueue() == NULL)
					cout << "Queue is empty!" << endl;
				else
					cout << iqueue.topQueue();
				cout << endl;
			}
			else if (option == 4)
			{
				cout << "Switching from int queue to Student* queue." << endl;
				whichQueue = 2;
			}
			else if (option == 5)
			{
				exit(0);
			}
		}	
	}

}
