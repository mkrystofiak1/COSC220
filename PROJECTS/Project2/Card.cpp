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
	return(Cards[NextCard-1]);
}

	

void Card::PrintCard(ACard arr[], int i) //extra function for just displaying the number and symbol
{
        if (NextCard == 52)
        {
                cout << "There are no more cards to draw." << endl;
        }

        if (arr[i].Num == 1)
        {
               	cout << "A" << arr[i].Pic;
        }
        else if (arr[i].Num == 2)
        {
            	cout << arr[i].Num << arr[i].Pic;
        }
        else if (arr[i].Num == 3)
        {
                cout << arr[i].Num << arr[i].Pic;
        }
        else if (arr[i].Num == 4)
        {
                cout << arr[i].Num << arr[i].Pic;
        }
	else if (arr[i].Num == 5)
        {
                cout << arr[i].Num << arr[i].Pic;
        }
        else if (arr[i].Num == 6)
        {
                cout << arr[i].Num << arr[i].Pic;
        }
        else if (arr[i].Num == 7)
        {
                cout << arr[i].Num << arr[i].Pic;
        }
        else if (arr[i].Num == 8)
        {
                cout << arr[i].Num << arr[i].Pic;
        }
        else if (arr[i].Num == 9)
        {
                cout << arr[i].Num << arr[i].Pic;
        }
        else if (arr[i].Num == 10)
        {
                cout << arr[i].Num << arr[i].Pic;
        }
        else if (arr[i].Num == 11)
        {
                cout << "J" << arr[i].Pic;
        }
        else if (arr[i].Num == 12)
        {
                cout << "Q" << arr[i].Pic;
        }
        else
        {
                cout << "K" << arr[i].Pic;
        }
}

int Card::blackjackConditions(ACard arr[], int i)
{
	if (arr[i].Num == 10)
		return 10;
	else if (arr[i].Num == 11)
		return 10;
	else if (arr[i].Num == 12)
		return 10;
	else if (arr[i].Num == 13)
		return 10;
	else if (arr[i].Num == 1)
		return 11;
	else
		return arr[i].Num;
}

void Card::CardAce(const char Pic[], int line)
{
	switch(line)
	{
		case 1:
			cout << "---------";
			break;
		case 2:
			cout <<"|"<<"A"<<setw(7)<<"|";
			break;
		case 3:
			cout <<"|"<<setw(8)<<"|";
			break;
		case 4:
			cout <<"|"<<setw(8)<<"|";
			break;
		case 5:
			cout <<"|"<<setw(8)<<"|";
			break;
		case 6:
			cout <<"|"<<setw(6)<<Pic<<setw(4)<<"|";
			break;
		case 7:
			cout <<"|"<<setw(8)<<"|";
			break;
		case 8:
			cout <<"|"<<setw(8)<<"|";
			break;
		case 9:
			cout <<"|"<<setw(8)<<"|";
			break;
		case 10:
			cout <<"|"<<setw(7)<<"A"<<"|";
			break;
		case 11:
			cout << "---------";
			break;
	}
}

void Card::CardTwo(const char Pic[], int line)
{
	switch(line)
	{
		case 1:
			cout << "---------";
			break;
		case 2:
			cout <<"|"<<"2"<<setw(7)<<"|";
			break;
		case 3:
			cout <<"|"<<setw(8)<<"|";
			break;
		case 4:
			cout <<"|"<<setw(6)<<Pic<<setw(4)<<"|";
			break;
		case 5:
			cout <<"|"<<setw(8)<<"|";
			break;
		case 6:
			cout <<"|"<<setw(8)<<"|";
			break;
		case 7:
			cout <<"|"<<setw(8)<<"|";
			break;
		case 8:
			cout <<"|"<<setw(6)<<Pic<<setw(4)<<"|";
			break;
		case 9:
			cout <<"|"<<setw(8)<<"|";
			break;
		case 10:
			cout <<"|"<<setw(7)<<"2"<<"|";
			break;
		case 11:
			cout << "---------";
			break;
	}
}

void Card::CardThree(const char Pic[], int line)
{
	switch(line)
	{
		case 1:
			cout << "---------";
			break;
		case 2:
			cout <<"|"<<"3"<<setw(7)<<"|";
			break;
		case 3:
			cout <<"|"<<setw(6)<<Pic<<setw(4)<<"|";
			break;
		case 4:
			cout <<"|"<<setw(8)<<"|";
			break;
		case 5:
			cout <<"|"<<setw(8)<<"|";
			break;
		case 6:
			cout <<"|"<<setw(6)<<Pic<<setw(4)<<"|";
			break;
		case 7:
			cout <<"|"<<setw(8)<<"|";
			break;
		case 8:
			cout <<"|"<<setw(8)<<"|";
			break;
		case 9:
			cout <<"|"<<setw(6)<<Pic<<setw(4)<<"|";
			break;
		case 10:
			cout <<"|"<<setw(7)<<"3"<<"|";
			break;
		case 11:
			cout << "---------";
			break;
	}
}

void Card::CardFour(const char Pic[], int line)
{
	switch(line)
	{
		case 1:
			cout << "---------";
			break;
        	case 2:
			cout <<"|"<<"4"<<setw(7)<<"|";
			break;
		case 3:
			cout <<"|"<<Pic<<setw(8)<<Pic<<"|";
			break;
		case 4:
			cout <<"|"<<setw(8)<<"|";
			break;
		case 5:
			cout <<"|"<<setw(8)<<"|";
			break;
		case 6:
			cout <<"|"<<setw(8)<<"|";
			break;
		case 7:
			cout <<"|"<<setw(8)<<"|";
			break;
		case 8:
			cout <<"|"<<setw(8)<<"|";
			break;
		case 9:
			cout <<"|"<<Pic<<setw(8)<<Pic<<"|";
			break;
		case 10:
			cout <<"|"<<setw(7)<<"4"<<"|";
			break;
		case 11:
			cout << "---------";
			break;
	}
}

void Card::CardFive(const char Pic[], int line)
{
	switch(line)
	{
		case 1:
			cout << "---------";
			break;
		case 2:
			cout <<"|"<<"5"<<setw(7)<<"|";
			break;
        	case 3:
			cout <<"|"<<Pic<<setw(8)<<Pic<<"|";
			break;
		case 4:
			cout <<"|"<<setw(8)<<"|";
			break;
        	case 5:
			cout <<"|"<<setw(8)<<"|";
			break;
		case 6:
			cout <<"|"<<setw(6)<<Pic<<setw(4)<<"|";
			break;
		case 7:
			cout <<"|"<<setw(8)<<"|";
			break;
		case 8:
			cout <<"|"<<setw(8)<<"|";
			break;
		case 9:
			cout <<"|"<<Pic<<setw(8)<<Pic<<"|";
			break;
		case 10:
			cout <<"|"<<setw(7)<<"5"<<"|";
			break;
		case 11:
			cout << "---------";
			break;
	}
}

void Card::CardSix(const char Pic[], int line)
{
	switch(line)
	{
		case 1:
			cout << "---------";
			break;
		case 2:
			cout <<"|"<<"6"<<setw(7)<<"|";
			break;
		case 3:
			cout <<"|"<<Pic<<setw(8)<<Pic<<"|";
			break;
		case 4:
			cout <<"|"<<setw(8)<<"|";
			break;
		case 5:
			cout <<"|"<<setw(8)<<"|";
			break;
		case 6:
			cout <<"|"<<Pic<<setw(8)<<Pic<<"|";
			break;
		case 7:
			cout <<"|"<<setw(8)<<"|";
			break;
		case 8:
			cout <<"|"<<setw(8)<<"|";
			break;
        	case 9:
			cout <<"|"<<Pic<<setw(8)<<Pic<<"|";
			break;
        	case 10:
			cout <<"|"<<setw(7)<<"6"<<"|";
			break;
		case 11:
			cout << "---------";
			break;
	}
}

void Card::CardSeven(const char Pic[], int line)
{
	switch(line)
	{
		case 1:
			cout << "---------";
			break;
		case 2:
			cout <<"|"<<"7"<<setw(7)<<"|";
			break;
		case 3:
			cout <<"|"<<Pic<<setw(8)<<Pic<<"|";
			break;
		case 4:
			cout <<"|"<<setw(6)<<Pic<<setw(4)<<"|";
			break;
		case 5:
			cout <<"|"<<setw(8)<<"|";
			break;
		case 6:
			cout <<"|"<<Pic<<setw(8)<<Pic<<"|";
			break;
		case 7:
			cout <<"|"<<setw(8)<<"|";
			break;
		case 8:
			cout <<"|"<<setw(8)<<"|";
			break;
		case 9:
			cout <<"|"<<Pic<<setw(8)<<Pic<<"|";
			break;
		case 10:
			cout <<"|"<<setw(7)<<"7"<<"|";
			break;
		case 11:
			cout << "---------";
			break;
	}
}

void Card::CardEight(const char Pic[], int line)
{
	switch(line)
	{
		case 1:
			cout << "---------";
			break;
		case 2:
			cout <<"|"<<"8"<<setw(7)<<"|";
			break;
		case 3:
			cout <<"|"<<Pic<<setw(8)<<Pic<<"|";
			break;
		case 4:
			cout <<"|"<<setw(6)<<Pic<<setw(4)<<"|";
			break;
		case 5:
			cout <<"|"<<setw(8)<<"|";
			break;
		case 6:
			cout <<"|"<<Pic<<setw(8)<<Pic<<"|";
			break;
		case 7:
			cout <<"|"<<setw(8)<<"|";
			break;
		case 8:
			cout <<"|"<<setw(6)<<Pic<<setw(4)<<"|";
			break;
		case 9:
			cout <<"|"<<Pic<<setw(8)<<Pic<<"|";
			break;
		case 10:
			cout <<"|"<<setw(7)<<"8"<<"|";
			break;
		case 11:
			cout << "---------";
			break;
	}
}

void Card::CardNine(const char Pic[], int line)
{
	switch(line)
	{
		case 1:
			cout << "---------";
			break;
       		case 2:
			cout <<"|"<<"9"<<setw(7)<<"|";
			break;
		case 3:
			cout <<"|"<<Pic<<setw(8)<<Pic<<"|";
			break;
		case 4:
			cout <<"|"<<setw(6)<<Pic<<setw(4)<<"|";
			break;
		case 5:
			cout <<"|"<<Pic<<setw(8)<<Pic<<"|";
			break;
		case 6:
			cout <<"|"<<setw(8)<<"|";
			break;
		case 7:
			cout <<"|"<<Pic<<setw(8)<<Pic<<"|";
			break;
		case 8:
			cout <<"|"<<setw(8)<<"|";
			break;
		case 9:
			cout <<"|"<<Pic<<setw(8)<<Pic<<"|";
			break;
		case 10:
			cout <<"|"<<setw(7)<<"9"<<"|";
			break;
		case 11:
			cout << "---------";
			break;
	}
}

void Card::CardTen(const char Pic[], int line)
{
	switch(line)
	{
		case 1:
			cout << "---------";
			break;
		case 2:
			cout <<"|"<<"10"<<setw(6)<<"|";
			break;
		case 3:
			cout <<"|"<<Pic<<setw(8)<<Pic<<"|";
			break;
		case 4:
			cout <<"|"<<setw(6)<<Pic<<setw(4)<<"|";
			break;
		case 5:
			cout <<"|"<<Pic<<setw(8)<<Pic<<"|";
			break;
		case 6:
			cout <<"|"<<setw(8)<<"|";
			break;
		case 7:
			cout <<"|"<<Pic<<setw(8)<<Pic<<"|";
			break;
		case 8:
			cout <<"|"<<setw(6)<<Pic<<setw(4)<<"|";
			break;
		case 9:
			cout <<"|"<<Pic<<setw(8)<<Pic<<"|";
			break;
		case 10:
			cout <<"|"<<setw(7)<<"10"<<"|";
			break;
		case 11:
			cout << "---------";
			break;
	}
}

void Card::CardJack(const char Pic[], int line)
{
	switch(line)
	{
		case 1:
			cout << "---------";
			break;
		case 2:
			cout <<"|"<<Pic<<setw(2)<<"J"<<setw(5)<<"|";
			break;
		case 3:
			cout <<"|"<<setw(8)<<"|";
			break;
        	case 4:
			cout <<"|"<<setw(8)<<"|";
			break;
		case 5:
			cout <<"|"<<setw(8)<<"|";
			break;
		case 6:
			cout <<"|"<<setw(8)<<"|";
			break;
		case 7:
			cout <<"|"<<setw(8)<<"|";
			break;
		case 8:
			cout <<"|"<<setw(8)<<"|";
			break;
		case 9:
			cout <<"|"<<setw(8)<<"|";
			break;
		case 10:
			cout <<"|"<<setw(7)<<Pic<<setw(2)<<"J"<<"|";
			break;
		case 11:
			cout << "---------";
			break;
	}
}

void Card::CardQueen(const char Pic[], int line)
{
	switch(line)
	{
		case 1:
			cout << "---------";
			break;
		case 2:
			cout <<"|"<<Pic<<setw(2)<<"Q"<<setw(5)<<"|";
			break;
		case 3:
			cout <<"|"<<setw(8)<<"|";
			break;
		case 4: 
			cout <<"|"<<setw(8)<<"|";
			break;
		case 5:
			cout <<"|"<<setw(8)<<"|";
			break;
		case 6:
			cout <<"|"<<setw(8)<<"|";
			break;
		case 7:
			cout <<"|"<<setw(8)<<"|";
			break;
		case 8:
			cout <<"|"<<setw(8)<<"|";
			break;
		case 9:
			cout <<"|"<<setw(8)<<"|";
			break;
		case 10:
			cout <<"|"<<setw(7)<<Pic<<setw(2)<<"Q"<<"|";
			break;
		case 11:
			cout << "---------";
			break;
	}
}

void Card::CardKing(const char Pic[], int line)
{
	switch(line)
	{
		case 1:
			cout << "---------";
			break;
		case 2:
        		cout <<"|"<<Pic<<setw(2)<<"K"<<setw(5)<<"|";
			break;
		case 3:
        		cout <<"|"<<setw(8)<<"|";
			break;
		case 4:
        		cout <<"|"<<setw(8)<<"|";
			break;
        	case 5:
			cout <<"|"<<setw(8)<<"|";
			break;
		case 6:
			cout <<"|"<<setw(8)<<"|";
			break;
        	case 7:
			cout <<"|"<<setw(8)<<"|";
			break;
        	case 8:
			cout <<"|"<<setw(8)<<"|";
			break;
		case 9:
			cout <<"|"<<setw(8)<<"|";
			break;
        	case 10:
			cout <<"|"<<setw(7)<<Pic<<setw(2)<<"K"<<"|";
			break;
        	case 11:
			cout << "---------";
			break;
	}
}

void Card::printMultiple(ACard arr[], int length)
{
	for (int i = 1; i < 12; i++)
	{
		for (int j = 0; j < length; j++)
		{
			switch(arr[j].Num)
			{
				case 1:
					CardAce(arr[j].Pic,i);
					break;
				case 2: 
					CardTwo(arr[j].Pic,i);
					break;
				case 3:
					CardThree(arr[j].Pic,i);
					break;
				case 4:
					CardFour(arr[j].Pic,i);
					break;
				case 5:
					CardFive(arr[j].Pic,i);
					break;
				case 6:
					CardSix(arr[j].Pic,i);
					break;
				case 7:
					CardSeven(arr[j].Pic,i);
					break;
				case 8:
					CardEight(arr[j].Pic,i);
					break;
				case 9:
					CardNine(arr[j].Pic,i);
					break;
				case 10:
					CardTen(arr[j].Pic,i);
					break;
				case 11:
					CardJack(arr[j].Pic,i);
					break;
				case 12:
					CardQueen(arr[j].Pic,i);
					break;
				case 13:
					CardKing(arr[j].Pic,i);
					break;
			}
		}
		cout << endl;
	}	
}
