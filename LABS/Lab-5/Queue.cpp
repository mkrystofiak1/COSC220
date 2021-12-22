//Program: Queue.cpp
//Author: Mitchell Krystofiak
//Description: Implementation for the Queue class.
//Date: October 27, 2020

#include"Queue.h"
#include<iostream>

using namespace std;

template <class DataType>
Queue<DataType>::Queue(int size)
{
	front = NULL; //initialize queue front and back to NULL
	back = NULL;
	queueSize = 10; //set the size of the queue equal to 10
}

template <class DataType>
Queue<DataType>::~Queue()
{
	QueueNode<DataType>* tempPtr;
	while (front != NULL)
	{
		tempPtr = front;
		front = front->next;
		delete tempPtr;
	}
	back = NULL;
}

template <class DataType>
void Queue<DataType>::enQueue(const DataType temp )
{
	if (isFull())
	{
		cerr << "Queue is full!" << endl;
	}
	else
	{
		QueueNode<DataType> * newNode = new QueueNode<DataType>;
		newNode->data = temp;
		newNode->next = NULL;
		if (isEmpty())
		{
			front = newNode;
			back = newNode;
		}
		else 
		{
			back->next = newNode;
			back = newNode;
		}
		queueCnt++;
	}
}

template <class DataType>
DataType Queue<DataType>::deQueue()
{
	if (isEmpty())
	{
		cerr << "Queue is empty!" << endl;
		return NULL;
	}
	else
	{
		QueueNode<DataType>* tempPtr;
		
		DataType tempData = front->data;

		tempPtr = front;
		front = front->next;
		if(front == NULL)
			back = NULL;
		delete tempPtr;
		queueCnt--;
		return tempData;
	}
}

template <class DataType>
DataType Queue<DataType>::topQueue() const 
{
	if(isEmpty())
		return NULL;
	return front->data;
}

template <class DataType>
bool Queue<DataType>::isEmpty() const
{
	return (queueCnt == 0);
}

template <class DataType>
bool Queue<DataType>::isFull() const
{
	return (queueCnt == queueSize);
}

