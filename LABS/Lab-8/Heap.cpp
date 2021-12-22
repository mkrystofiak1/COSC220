//Program: Heap.cpp
//Author: Mitchell Krystofiak
//Description: Implementation for the Heap class.
//Date: November 24, 2020

#include"Heap.h"
#include<iostream>
#include<algorithm>

using namespace std;

Heap::Heap()
{
	heapSize = 10;
	buildHeap();
}

int Heap::parent(int i)
{
	if (i%2 == 0) // If i is even.
		return ((i-1)/2);
	else
		return (i/2);
}

int Heap::leftChild(int i)
{
	return (2*i + 1);
}

int Heap::rightChild(int i)
{
	return (2*i + 2);
}

void Heap::Heapify(int i, int n)
{	
	int l = leftChild(i);
	int r = rightChild(i);
	int largest = i;
	/*
	 * If left Child is less than root...
	 */
	if (l < n && A[l] > A[largest])
	{
		largest = l;
	}
	/*
	 * If right Child is largest than largest so far..
	 */ 
	if (r < n && A[r] > A[largest])
	{
		largest = r;
	}
	/*
	 * If largest is not root...
	 */
	if (largest != i)
	{
		swap(A[i], A[largest]);
		/*
		 * Recursively call Heapify.
		 */
		Heapify(largest, n);
	}
	
}

void Heap::buildHeap()
{
	for (int i = ((heapSize/2) - 1); i >= 0; i--)
		Heapify(i, heapSize);
}

void Heap::insert(int key)
{
	heapSize = heapSize + 1;
	int i = heapSize - 1;
	while (i > 0 && A[parent(i)] < key)
	{
		A[i] = A[parent(i)];
		i = parent(i);
	}
	A[i] = key;
}

void Heap::heapSort()
{
	buildHeap();
	int j = heapSize;	
	for (int i = heapSize - 1; i>0; i--)
	{
		swap(A[0],A[i]);
		j = j - 1;
		Heapify(0, j);	
	}
}

int Heap::extractMax()
{
	if (heapSize < 1)
		cout << "Error: Heap underflow." << endl;
	else
	{
		int max = A[0];
		A[0] = A[heapSize - 1];
		heapSize = heapSize -1;
		Heapify(0, heapSize);
		return max;
	}
}

int Heap::maximum()
{
	return A[0];
}

void Heap::printHeap()
{
	for (int i = 0; i<heapSize; i++)
		cout << A[i] << " ";
	cout << endl;
	
}

