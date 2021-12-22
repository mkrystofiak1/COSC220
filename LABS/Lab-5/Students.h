//Program: Students.h
//Author: Mitchell Krystofiak
//Description: Header file for the Student class.
//Date: October 27, 2020

#ifndef STUDENTS_H
#define STUDENTS_H

#include<iostream>


//definition of the Struct Type Students

struct Students 
{
	char lastName[20]; //student lastname
	char firstName[20]; //student firstname
	int idNumber;       //student id number
	Students();         //constructor
	void printStudent(); //print a students information
};

#endif
