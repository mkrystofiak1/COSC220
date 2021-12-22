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
       	
	void CardAce(const char Pic[]);
	void CardTwo(const char Pic[]);
	void CardThree(const char Pic[]);
	void CardFour(const char Pic[]);
	void CardFive(const char Pic[]);
	void CardSix(const char Pic[]);
	void CardSeven(const char Pic[]);
	void CardEight(const char Pic[]);
	void CardNine(const char Pic[]);
	void CardTen(const char Pic[]);
	void CardJack(const char Pic[]);
	void CardQueen(const char Pic[]);
	void CardKing(const char Pic[]);
	
};

#endif
