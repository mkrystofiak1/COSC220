//Program: TNode.h
//Author: Mitchell Krystofiak
//Description: Tree Node class structure.
//Date: Novemeber 10, 2020

#ifndef TNODE_H
#define TNODE_H

#include<iostream>

using namespace std;

class TNode
{
	private:
		TNode * parent;
		TNode * left;
		TNode * right;
		int data;
		
		//Make BST a friend of TNode
		friend class BST;
	public:
		TNode();
		void printNode();
};

#endif
