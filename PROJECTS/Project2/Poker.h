//Program: Poker.h
//Author: Mitchell Krystofiak
//Description: Definition of the Poker class.
//Date: December 8, 2020

#ifndef POKER_H
#define POKER_H

#include"Card.h"
#include<iostream>

class Poker: public Card
{
	private:
		ACard player[5]; //create array of cards for player
		
	public:
		Poker();
		void changeCards(); //switch out or keep cards
		void printValue(); //print out only the suit and number
		void printHand(); //print out the final hands of the player
		void determineHandValue(int&, int&); //print out type of hand and the bet * multiplier
};

#endif
