//Program: Blackjack.cpp
//Author: Mitchell Krystofiak
//Description: Definition of the Blackjack class.
//Date: December 8, 2020

#ifndef BLACKJACK_H
#define BLACKJACK_H

#include"Card.h"
#include<iostream>

class Blackjack: public Card
{
        private:
                ACard player[10]; //create array of cards for player
		ACard dealer[10]; //create array of cards for the dealer
		int Pcounter;
		int Dcounter;
        public:
                Blackjack();
		void playGame(int&, int&, int&); //handles the hitting and standing of the player, as well as dealer ace condiition
		int determineWinner(int, int&, int&, int&);
		void printHand(int);
};

#endif
