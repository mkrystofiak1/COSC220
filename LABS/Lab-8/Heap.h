//Program: Heap.h
//Author: Mitchell Krystofiak
//Description: Definition of the Heap class.
//Date: November 24, 2020

#ifndef HEAP_H
#define HEAP_H

#include<iostream>

using namespace std;

class Heap
{
	private:
		/*
		 * Implement an array with a maximum size of 100 for the heap.
		 */
		int A[100] = {4,12,3,19,23,5,32,11,2,24};
		/*
		 * An integer to keep track of the size of the array (maximum size = 100).
		 */
		int heapSize; 
		/*
		 * The parent of a node i.
		 */
		int parent(int i);
		/*
		 * The left child of a node i.
		 */
		int leftChild(int i);
		/*
		 * The right child of a node i.
		 */
		int rightChild(int i);
		/*
		 *The heapify function takes in an array A and an index i. This function then checks to make sure that the 
		 *root of a particular node is larger then its children. If it is smaller, this violates the heap property.
		 */
		void Heapify(int i, int n);
		
		void buildHeap();
	public:
		Heap();
		void insert(int i);
		void heapSort();
		int extractMax();
		int maximum();
		void printHeap();
};

#endif
