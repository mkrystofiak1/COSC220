//Program: test.cpp
//Author: Mitchell Krystofiak
//Description: Test program for the Card class.
//Date: 10/24/2020

#include"Card.h"
#include<iostream>

using namespace std;

int main()
{
	//test program needs to:
	//	1) create a card object
	//	2) shuffle cards
	//	3) Display 2, 3, 4, 5 cards
	
	Card * hello = new Card;
	hello->ShuffleCard();
	for (int i=1; i<=5; i++)
	{
		cout <<"Number of cards printed: " << i << endl;
		for (int j = 0; j<i; j++)
			hello->GetCard();
	}


}
