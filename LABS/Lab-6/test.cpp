//Program: test.cpp
//Author: Mitchell Krystofiak
//Description: Test file for the QuickSort class.
//Date: November 3, 2020

#include "QuickSort.h"
#include<iostream>

using namespace std;

int main()
{
	QuickSort<int> List1;
	QuickSort<double> List2;
	QuickSort<char> List3;

	int size;
	cout << "Enter an array size between 0 and 10: ";
	cin >> size;
	while (size < 1 || size > 10)
	{
		cout << "Invalid size." << endl;
		cout << "Enter an array size between 0 and 10: ";
		cin >> size;
	}

	/*
	 * DataType == Int
	 */
	int arr[10];
	cout << "Fill the array with integers." << endl;
	for (int i = 0 ; i<size ; i++)
	{
		cout << i << ": ";
		cin >> arr[i];
	}
	cout << "Array you entered: ";
	for (int i = 0; i<size ; i++)
		cout << arr[i] << " ";
	cout << endl;
	List1.quickSort(arr, 0, size-1);
	cout << "Sorted array: ";
	for (int i = 0; i<size ; i++)
		cout << arr[i] << " ";
	cout << endl;
	cout << endl;
	/*
	 * DataType == Double
	 */
	double Darr[10];
        cout << "Fill the array with doubles." << endl;
        for (int i = 0 ; i<size ; i++)
        {
                cout << i << ": ";
                cin >> Darr[i];
        }
        cout << "Array you entered: ";
        for (int i = 0; i<size ; i++)
                cout << Darr[i] << " ";
        cout << endl;
        List2.quickSort(Darr, 0, size-1);
        cout << "Sorted array: ";
        for (int i = 0; i<size ; i++)
                cout << Darr[i] << " ";
        cout << endl;
	cout << endl;
	/*
	 * DataType == char
	 */
	char Carr[10];
        cout << "Fill the array with characters." << endl;
        for (int i = 0 ; i<size ; i++)
        {
                cout << i << ": ";
                cin >> Carr[i];
        }
        cout << "Array you entered: ";
        for (int i = 0; i<size ; i++)
                cout << Carr[i] << " ";
        cout << endl;
        List3.quickSort(Carr, 0, size-1);
        cout << "Sorted array: ";
        for (int i = 0; i<size ; i++)
                cout << Carr[i] << " ";
        cout << endl;

}
