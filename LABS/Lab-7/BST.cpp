//Program: BST.cpp
//Author: Mitchell Krystofiak
//Description: Implementation of the BST class.
//Date: Novemeber 10, 2020

#include"BST.h"
#include<iostream>

using namespace std;

BST::BST()
{
	root = NULL;
}

BST::~BST()
{
	destroySubTree(root);
}

void BST::insert(TNode * &nodePtr, TNode* &newNode)
{
	if (nodePtr == NULL)
		nodePtr = newNode;
	else if (newNode->data < nodePtr->data)
		insert(nodePtr->left, newNode);
	else
		insert(nodePtr->right,newNode);
}

void BST::destroySubTree(TNode * nodePtr )
{
	if (nodePtr)
	{
		if (nodePtr->left)
			destroySubTree(nodePtr->left);
		if (nodePtr->right)
			destroySubTree(nodePtr->right);
		delete nodePtr;
	}
}

void BST::deleteNode(int num , TNode * &nodePtr)
{
	if (num < nodePtr->data)
		deleteNode(num, nodePtr->left);
	else if (num > nodePtr->data)
		deleteNode(num, nodePtr->right);
	else
		makeDeletion(nodePtr);
}

void BST::makeDeletion(TNode * &nodePtr)
{
	TNode *tempNodePtr = NULL;

	if (nodePtr == NULL)
		cout << "Cannot delete empty node." << endl;
	else if (nodePtr->right == NULL)
	{
		tempNodePtr = nodePtr;
		nodePtr = nodePtr->left;
		delete tempNodePtr;
	}
	else if (nodePtr->left == NULL)
	{
		tempNodePtr = nodePtr;
		nodePtr = nodePtr->right;
		delete tempNodePtr;
	}
	else
	{
		tempNodePtr = nodePtr->right;
		while (tempNodePtr->left)
			tempNodePtr = tempNodePtr->left;
		tempNodePtr->left = nodePtr->left;
		tempNodePtr = nodePtr;
		nodePtr = nodePtr->right;
		delete tempNodePtr;
	}
}

void BST::displayInOrder(TNode * nodePtr) const
{
	if (nodePtr)
	{
		displayInOrder(nodePtr->left);
		cout << nodePtr->data << endl;
		displayInOrder(nodePtr->right);
	}
}

void BST::displayPreOrder(TNode * nodePtr) const
{
	if (nodePtr)
	{
		cout << nodePtr->data << endl;
		displayPreOrder(nodePtr->left);
		displayPreOrder(nodePtr->right);
	}
}

void BST::displayPostOrder(TNode * nodePtr) const
{
	if (nodePtr)
	{
		displayPostOrder(nodePtr->left);
		displayPostOrder(nodePtr->right);
		cout << nodePtr->data << endl;
	}
}

void BST::displayInOrder() const
{
	if (root == NULL)
		cout << "Tree is empty." << endl;
	else
		displayInOrder(root);
}

void BST::displayPostOrder() const
{
	if (root == NULL)
		cout << "Tree is empty." << endl;
	else
		displayPostOrder(root);
}

void BST::displayPreOrder() const
{
	if (root == NULL)
		cout << "Tree is empty." << endl;
	else
		displayPreOrder(root);
}

void BST::bstInsert(int num)
{
	if (bstSearch(num))
	{
		cout << "Already in tree. " << endl;
	}
	else 
	{
		TNode * newNode = NULL;
		newNode = new TNode;
		newNode->data = num;
		newNode->left = newNode->right = NULL;
		insert(root, newNode);	
	}
}

void BST::bstDelete(int num)
{
	if (root == NULL)
		cout << "Tree is empty." << endl;
	else
		deleteNode(num, root);
}

bool BST::bstSearch(int num)
{	
	TNode * nodePtr = root;

	while (nodePtr)
	{
		if (nodePtr->data == num)
			return true;
		else if (num < nodePtr->data)
			nodePtr = nodePtr->left;
		else
			nodePtr = nodePtr->right;
	}
	return false;
}


