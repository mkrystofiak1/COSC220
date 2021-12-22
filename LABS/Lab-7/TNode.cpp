//Program: TNode.cpp
//Author: Mitchell Krystofiak
//Description: Implementation for  the TNode class.
//Date: Novemeber 10, 2020

#include "TNode.h"
#include<iostream>

using namespace std;

TNode::TNode()
{
	parent = NULL;
	left = NULL;
	right = NULL;
	data = 0;
}

void TNode::printNode()
{
	cout << endl;
}

