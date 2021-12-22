//Program: BST.h
//Author: Mitchell Krystofiak
//Description: Class structure for the Binary Search Tree.
//Date: November 10, 2020

#ifndef BST_H
#define BST_H

#include<iostream>
#include"TNode.h"
using namespace std;

class BST
{
	private:
		TNode * root;
		void insert(TNode *&, TNode *&);
		void destroySubTree(TNode *);
		void deleteNode(int, TNode *&);
		void makeDeletion(TNode *&);
		void displayInOrder(TNode *) const;
		void displayPreOrder(TNode *) const;
		void displayPostOrder(TNode *) const;

	public:
		//constructor
		BST();
		//deconstructor
		~BST();
		//functions
		void displayInOrder() const;
		void displayPostOrder() const;
		void displayPreOrder() const;

		void bstInsert(int);
		void bstDelete(int);
		bool bstSearch(int);
};

#endif
