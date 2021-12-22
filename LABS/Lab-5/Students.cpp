//Program: Students.cpp
//Author: Mitchell Krystofiak
//Description: Implementation for the student class.
//Date: October 27, 2020

#include "Students.h"
#include <iostream>

using namespace std;

Students::Students()
{
	cout << "What is the student's first name?: ";
	cin >> firstName;
	cout << "What is the student's last name?: ";
	cin >> lastName;
	cout << "What is the student's id number?: ";
	cin >> idNumber;
}

void Students::printStudent()
{
	cout << "ID# " << idNumber << " - " << lastName << ", " << firstName << endl;
}

