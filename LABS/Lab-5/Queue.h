//Program: Queue.h
//Author: Mitchell Krystofiak
//Description: Header file for the queue class.
//Date: October 27, 2020

#ifndef QUEUE_H
#define QUEUE_H

#include<iostream>

using namespace std;

template<class DataType>

struct QueueNode
{
	DataType data;
	QueueNode<DataType> *next;
};

template<class DataType>

class Queue
{

private:
	QueueNode<DataType> *front;
	QueueNode<DataType> *back;
	int queueSize; //size of a Queue
	int queueCnt; //element count in a Queue
public:
	Queue(int = 10); //class constructor - initialize variables
	~Queue(); //class deconstructor - remove all memory spaces used by queue elements
	void enQueue(const DataType); //add an item to the back of the queue
	DataType deQueue(); //remove the first item from the queue and return it's value
	DataType topQueue() const; //return the value of the first item in the queue
	bool isEmpty() const; //returns true if there are no elements in the queue
	bool isFull() const; //returns true if there is no system memory for a new queue node
};

#endif
