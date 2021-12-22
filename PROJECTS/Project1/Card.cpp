//Program: Card.cpp
//Author: Mitchell Krystofiak
//Description: Implementation file for the Card class.
//Date: 10/24/2020

#include"Card.h"
#include<iostream>
#include<ctime>
#include<cstdlib>
#include<iomanip>
using namespace std;

//Constant character arrays defined to print the images of a spade, club, heart or diamond.
const char spade[4] = "\xe2\x99\xa0";
const char club[4] = "\xe2\x99\xa3";
const char heart[4] = "\xe2\x99\xa5";
const char diamond[4] = "\xe2\x99\xa6";

//Card Constructor: Initializes the card deck.
Card::Card()
{
	NextCard = 0;

	for (int i = 0; i < 52; i++) //load deck struct ACard { int Num;, char Pic[4].....
	{
		Cards[NextCard].Num = ((i%13)+1);
		if (i < 13)
		{
			for (int j = 0; j<4; j++)
			{
				Cards[NextCard].Pic[j] = spade[j];
			}
		}
		else if (i < 26)
		{
			for (int j = 0; j<4; j++)
                        {
                                Cards[NextCard].Pic[j] = club[j];
                        } 
		}
		else if (i < 39)
		{
			for (int j = 0; j<4; j++)
                        {
                                Cards[NextCard].Pic[j] = heart[j];
                        } 
		}
		else
		{
			for (int j = 0; j<4; j++)
                        {
                                Cards[NextCard].Pic[j] = diamond[j];
                        } 
		}
		NextCard++;
	}
}
//Randomly mixes up the deck of cards created in the constructor.
void Card::ShuffleCard()
{
	int rnum;
	srand(time(0));
	for (int i = 0; i<52 ; i++)
	{
		int r = i + (rand() % (52 - i));
		swap(Cards[i], Cards[r]);
	}
	NextCard = 0;
}
//Returns the card value on the top of the deck. Think of it as drawing a card.
Card::ACard Card::GetCard()
{
	NextCard++;
	if (NextCard == 52)
	{
		cout << "There are no more cards to draw." << endl;
		return Cards[NextCard-1];
	}

	if (Cards[NextCard-1].Num == 1)
	{
		CardAce(Cards[NextCard-1].Pic);
		return Cards[NextCard-1];
	}
	else if (Cards[NextCard-1].Num == 2)
	{
		CardTwo(Cards[NextCard-1].Pic);
		return Cards[NextCard-1];
	}
	else if (Cards[NextCard-1].Num == 3)
	{
		CardThree(Cards[NextCard-1].Pic);
		return Cards[NextCard-1];
	}
	else if (Cards[NextCard-1].Num == 4)
	{
		CardFour(Cards[NextCard-1].Pic);
		return Cards[NextCard-1];
	}
	else if (Cards[NextCard-1].Num == 5)
	{
		CardFive(Cards[NextCard-1].Pic);
		return Cards[NextCard-1];
	}
	else if (Cards[NextCard-1].Num == 6)
	{
		CardSix(Cards[NextCard-1].Pic);
		return Cards[NextCard-1];
	}
	else if (Cards[NextCard-1].Num == 7)
	{
		CardSeven(Cards[NextCard-1].Pic);
		return Cards[NextCard-1];
	}
	else if (Cards[NextCard-1].Num == 8)
	{
		CardEight(Cards[NextCard-1].Pic);
		return Cards[NextCard-1];
	}
	else if (Cards[NextCard-1].Num == 9)
	{
		CardNine(Cards[NextCard-1].Pic);
		return Cards[NextCard-1];
	}
	else if (Cards[NextCard-1].Num == 10)
	{
		CardTen(Cards[NextCard-1].Pic);
		return Cards[NextCard-1];
	}
	else if (Cards[NextCard-1].Num == 11)
	{
		CardJack(Cards[NextCard-1].Pic);
		return Cards[NextCard-1];
	}
	else if (Cards[NextCard-1].Num == 12)
	{
		CardQueen(Cards[NextCard-1].Pic);
		return Cards[NextCard-1];
	}
	else 
	{
		CardKing(Cards[NextCard-1].Pic);
		return Cards[NextCard-1];
	}
}
void Card::CardAce(const char Pic[])
{
	cout << "---------" << endl;
        cout <<"|"<<"A"<<setw(7)<<"|"<<endl;
        cout <<"|"<<setw(8)<<"|"<<endl;
        cout <<"|"<<setw(8)<<"|"<<endl;
        cout <<"|"<<setw(8)<<"|"<<endl;
        cout <<"|"<<setw(6)<<Pic<<setw(4)<<"|"<<endl;
        cout <<"|"<<setw(8)<<"|"<<endl;
        cout <<"|"<<setw(8)<<"|"<<endl;
        cout <<"|"<<setw(8)<<"|"<<endl;
	cout <<"|"<<setw(7)<<"A"<<"|"<<endl;
        cout << "---------" << endl;
}

void Card::CardTwo(const char Pic[])
{
	cout << "---------" << endl;
	cout <<"|"<<"2"<<setw(7)<<"|"<<endl;
	cout <<"|"<<setw(8)<<"|"<<endl;
	cout <<"|"<<setw(6)<<Pic<<setw(4)<<"|"<<endl;
	cout <<"|"<<setw(8)<<"|"<<endl;
	cout <<"|"<<setw(8)<<"|"<<endl;
	cout <<"|"<<setw(8)<<"|"<<endl;
	cout <<"|"<<setw(6)<<Pic<<setw(4)<<"|"<<endl;
	cout <<"|"<<setw(8)<<"|"<<endl;
	cout <<"|"<<setw(7)<<"2"<<"|"<<endl;
	cout << "---------" << endl;
}

void Card::CardThree(const char Pic[])
{
	cout << "---------" << endl;
        cout <<"|"<<"3"<<setw(7)<<"|"<<endl;
        cout <<"|"<<setw(6)<<Pic<<setw(4)<<"|"<<endl;
        cout <<"|"<<setw(8)<<"|"<<endl;
        cout <<"|"<<setw(8)<<"|"<<endl;
        cout <<"|"<<setw(6)<<Pic<<setw(4)<<"|"<<endl;
        cout <<"|"<<setw(8)<<"|"<<endl;
        cout <<"|"<<setw(8)<<"|"<<endl;
        cout <<"|"<<setw(6)<<Pic<<setw(4)<<"|"<<endl;
        cout <<"|"<<setw(7)<<"3"<<"|"<<endl;
        cout << "---------" << endl;
}

void Card::CardFour(const char Pic[])
{
	cout << "---------" << endl;
        cout <<"|"<<"4"<<setw(7)<<"|"<<endl;
        cout <<"|"<<Pic<<setw(8)<<Pic<<"|"<<endl;
        cout <<"|"<<setw(8)<<"|"<<endl;
        cout <<"|"<<setw(8)<<"|"<<endl;
        cout <<"|"<<setw(8)<<"|"<<endl;
        cout <<"|"<<setw(8)<<"|"<<endl;
        cout <<"|"<<setw(8)<<"|"<<endl;
        cout <<"|"<<Pic<<setw(8)<<Pic<<"|"<<endl;
        cout <<"|"<<setw(7)<<"4"<<"|"<<endl;
        cout << "---------" << endl;
}

void Card::CardFive(const char Pic[])
{
	cout << "---------" << endl;
        cout <<"|"<<"5"<<setw(7)<<"|"<<endl;
        cout <<"|"<<Pic<<setw(8)<<Pic<<"|"<<endl;
        cout <<"|"<<setw(8)<<"|"<<endl;
        cout <<"|"<<setw(8)<<"|"<<endl;
        cout <<"|"<<setw(6)<<Pic<<setw(4)<<"|"<<endl;
        cout <<"|"<<setw(8)<<"|"<<endl;
        cout <<"|"<<setw(8)<<"|"<<endl;
        cout <<"|"<<Pic<<setw(8)<<Pic<<"|"<<endl;
        cout <<"|"<<setw(7)<<"5"<<"|"<<endl;
        cout << "---------" << endl;
}

void Card::CardSix(const char Pic[])
{
	cout << "---------" << endl;
        cout <<"|"<<"6"<<setw(7)<<"|"<<endl;
        cout <<"|"<<Pic<<setw(8)<<Pic<<"|"<<endl;
        cout <<"|"<<setw(8)<<"|"<<endl;
        cout <<"|"<<setw(8)<<"|"<<endl;
        cout <<"|"<<Pic<<setw(8)<<Pic<<"|"<<endl;
        cout <<"|"<<setw(8)<<"|"<<endl;
        cout <<"|"<<setw(8)<<"|"<<endl;
        cout <<"|"<<Pic<<setw(8)<<Pic<<"|"<<endl;
        cout <<"|"<<setw(7)<<"6"<<"|"<<endl;
        cout << "---------" << endl;
}

void Card::CardSeven(const char Pic[])
{
	cout << "---------" << endl;
        cout <<"|"<<"7"<<setw(7)<<"|"<<endl;
        cout <<"|"<<Pic<<setw(8)<<Pic<<"|"<<endl;
        cout <<"|"<<setw(6)<<Pic<<setw(4)<<"|"<<endl;
        cout <<"|"<<setw(8)<<"|"<<endl;
        cout <<"|"<<Pic<<setw(8)<<Pic<<"|"<<endl;
        cout <<"|"<<setw(8)<<"|"<<endl;
        cout <<"|"<<setw(8)<<"|"<<endl;
        cout <<"|"<<Pic<<setw(8)<<Pic<<"|"<<endl;
        cout <<"|"<<setw(7)<<"7"<<"|"<<endl;
        cout << "---------" << endl;
}

void Card::CardEight(const char Pic[])
{
	cout << "---------" << endl;
        cout <<"|"<<"8"<<setw(7)<<"|"<<endl;
        cout <<"|"<<Pic<<setw(8)<<Pic<<"|"<<endl;
        cout <<"|"<<setw(6)<<Pic<<setw(4)<<"|"<<endl;
        cout <<"|"<<setw(8)<<"|"<<endl;
        cout <<"|"<<Pic<<setw(8)<<Pic<<"|"<<endl;
        cout <<"|"<<setw(8)<<"|"<<endl;
        cout <<"|"<<setw(6)<<Pic<<setw(4)<<"|"<<endl;
        cout <<"|"<<Pic<<setw(8)<<Pic<<"|"<<endl;
        cout <<"|"<<setw(7)<<"8"<<"|"<<endl;
        cout << "---------" << endl;
}

void Card::CardNine(const char Pic[])
{
	cout << "---------" << endl;
        cout <<"|"<<"9"<<setw(7)<<"|"<<endl;
        cout <<"|"<<Pic<<setw(8)<<Pic<<"|"<<endl;
        cout <<"|"<<setw(6)<<Pic<<setw(4)<<"|"<<endl;
        cout <<"|"<<Pic<<setw(8)<<Pic<<"|"<<endl;
        cout <<"|"<<setw(8)<<"|"<<endl;
        cout <<"|"<<Pic<<setw(8)<<Pic<<"|"<<endl;
        cout <<"|"<<setw(8)<<"|"<<endl;
        cout <<"|"<<Pic<<setw(8)<<Pic<<"|"<<endl;
        cout <<"|"<<setw(7)<<"9"<<"|"<<endl;
        cout << "---------" << endl;
}

void Card::CardTen(const char Pic[])
{
	cout << "---------" << endl;
	cout <<"|"<<"10"<<setw(6)<<"|"<<endl;
	cout <<"|"<<Pic<<setw(8)<<Pic<<"|"<<endl;
        cout <<"|"<<setw(6)<<Pic<<setw(4)<<"|"<<endl;
        cout <<"|"<<Pic<<setw(8)<<Pic<<"|"<<endl;
        cout <<"|"<<setw(8)<<"|"<<endl;
        cout <<"|"<<Pic<<setw(8)<<Pic<<"|"<<endl;
        cout <<"|"<<setw(6)<<Pic<<setw(4)<<"|"<<endl;
        cout <<"|"<<Pic<<setw(8)<<Pic<<"|"<<endl;
        cout <<"|"<<setw(7)<<"10"<<"|"<<endl;
        cout << "---------" << endl;
}

void Card::CardJack(const char Pic[])
{
	cout << "---------" << endl;
        cout <<"|"<<Pic<<setw(2)<<"J"<<setw(5)<<"|"<<endl;
        cout <<"|"<<setw(8)<<"|"<<endl;
        cout <<"|"<<setw(8)<<"|"<<endl;
        cout <<"|"<<setw(8)<<"|"<<endl;
        cout <<"|"<<setw(8)<<"|"<<endl;
        cout <<"|"<<setw(8)<<"|"<<endl;
        cout <<"|"<<setw(8)<<"|"<<endl;
        cout <<"|"<<setw(8)<<"|"<<endl;
        cout <<"|"<<setw(7)<<Pic<<setw(2)<<"J"<<"|"<<endl;
        cout << "---------" << endl;

}

void Card::CardQueen(const char Pic[])
{
	cout << "---------" << endl;
        cout <<"|"<<Pic<<setw(2)<<"Q"<<setw(5)<<"|"<<endl;
        cout <<"|"<<setw(8)<<"|"<<endl;
        cout <<"|"<<setw(8)<<"|"<<endl;
        cout <<"|"<<setw(8)<<"|"<<endl;
        cout <<"|"<<setw(8)<<"|"<<endl;
        cout <<"|"<<setw(8)<<"|"<<endl;
        cout <<"|"<<setw(8)<<"|"<<endl;
        cout <<"|"<<setw(8)<<"|"<<endl;
        cout <<"|"<<setw(7)<<Pic<<setw(2)<<"Q"<<"|"<<endl;
        cout << "---------" << endl;

}

void Card::CardKing(const char Pic[])
{
	cout << "---------" << endl;
        cout <<"|"<<Pic<<setw(2)<<"K"<<setw(5)<<"|"<<endl;
        cout <<"|"<<setw(8)<<"|"<<endl;
        cout <<"|"<<setw(8)<<"|"<<endl;
        cout <<"|"<<setw(8)<<"|"<<endl;
        cout <<"|"<<setw(8)<<"|"<<endl;
        cout <<"|"<<setw(8)<<"|"<<endl;
        cout <<"|"<<setw(8)<<"|"<<endl;
        cout <<"|"<<setw(8)<<"|"<<endl;
        cout <<"|"<<setw(7)<<Pic<<setw(2)<<"K"<<"|"<<endl;
        cout << "---------" << endl;
}

