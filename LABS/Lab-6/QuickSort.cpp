//Program: QuickSort.cpp
//Author: Mitchell Krystofiak
//Description: Implementation of the QuickSort class <templated>.
//Date: November 3, 2020

#include "QuickSort.h"
#include<iostream>
#include<algorithm>

using namespace std;

template<class DataType>
DataType QuickSort<DataType>::quickSort(DataType arr[], int start, int end)
{
	if (start < end)
	{
		int p = partition(arr, start, end);
		quickSort(arr,start,p-1);
		quickSort(arr, p+1, end);
	}
	return 0;
}

template<class DataType>
DataType QuickSort<DataType>::partition(DataType arr[], int start, int end)
{
	int pivotValue = arr[start];
	int pivotPosition = start;

	for (int pos = start+1; pos <=end; pos++)
	{
		if(arr[pos] < pivotValue)
		{
			swap(arr[pivotPosition + 1], arr[pos]);
			swap(arr[pivotPosition], arr[pivotPosition + 1]);
			pivotPosition++;
		}
	}
	return pivotPosition;
}
