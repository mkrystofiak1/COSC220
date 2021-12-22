//Program: QuickSort.h
//Author: Mitchell Krystofiak
//Description: Header file for quicksort class <templated>.
//Date: November 3, 2020

#include<iostream>
#include<algorithm>

#ifndef QUICKSORT_H
#define QUICKSORT_H
template<class DataType>

class QuickSort
{
	public:
		DataType quickSort(DataType [], int, int);
		DataType partition(DataType [], int, int);
};

#endif
