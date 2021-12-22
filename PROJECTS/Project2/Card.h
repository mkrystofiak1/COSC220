//Program: Card.h
//Author: Mitchell Krystofiak
//Description: Header file for the Card class.
//Date: 10/24/2020

#ifndef CARD_H
#define CARD_H

#include<iostream>

class Card
{
private:
	struct ACard //Makes a particular card have two values, it's number (1-13) or its picture(1-4)
	{
		int Num;
		char Pic[4];
	};

	ACard Cards[52]; //make array of the cards
	
	int NextCard; //points to the index of the next card

public:
//constructor
	Card();
//prototypes
	void ShuffleCard(); //shuffles array of cards
	ACard GetCard();
       	void PrintCard(ACard [], int); //special poker function
	int blackjackConditions(ACard [], int); //special blackjack function
	void CardAce(const char Pic[], int);
	void CardTwo(const char Pic[], int);
	void CardThree(const char Pic[], int);
	void CardFour(const char Pic[], int);
	void CardFive(const char Pic[], int);
	void CardSix(const char Pic[], int);
	void CardSeven(const char Pic[], int);
	void CardEight(const char Pic[], int);
	void CardNine(const char Pic[], int);
	void CardTen(const char Pic[], int);
	void CardJack(const char Pic[], int);
	void CardQueen(const char Pic[], int);
	void CardKing(const char Pic[], int);
	
	void printMultiple(ACard [], int);
	friend class Poker;	
	friend class Blackjack;
};

#endif
