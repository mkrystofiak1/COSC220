//Program: Poker.cpp
//Author: Mitchell Krystofiak
//Description: Implementation for the poker class.
//Date: December 8, 2020

#include "Poker.h"
#include "Card.h"
#include<iostream>
#include<algorithm>
using namespace std;

Poker::Poker()
{
	ShuffleCard();
	for (int i = 0; i<5; i++)
	{
		player[i] = GetCard();
	}
}

void Poker::changeCards()
{
	int input = 0;
	int change1 = -1;
	int change2 = -1;
	int change3 = -1;
        int change4 = -1;
	int change5 = -1;

	for (int i = 0; i<5; i++)
	{
		PrintCard(player, i);
		cout << " Hold(1) or Redraw(0)?: ";
	       	cin >> input;
		while (input != 1 && input != 0)
		{
			cout << "Invalid choice." << endl;
			cout << "Hold(1) or Redraw(0)?: ";
			cin >> input;
		}
		if (input == 0)
		{
			if (i == 0)
				change1 = i;
			else if (i == 1)
				change2 = i;
			else if (i == 2)
				change3 = i;
			else if (i == 3)
				change4 = i;
			else if (i == 4)
				change5 = i;
		}
	}
	if (change1 != -1)
		player[change1] = GetCard();
	if (change2 != -1)
		player[change2] = GetCard();
	if (change3 != -1)
		player[change3] = GetCard();
	if (change4 != -1)
		player[change4] = GetCard();
	if (change5 != -1)
		player[change5] = GetCard();

}

void Poker::printValue()
{
	for (int i = 0; i<5; i++)
	{
		PrintCard(player, i);
		cout << " ";
	}
	cout << endl;
}

void Poker::printHand()
{
	printMultiple(player, 5);
}

void Poker::determineHandValue(int& startingFunds, int& bet)
{
	bool flush = false;
	bool straight = false;
	bool royalStraight = false;
	bool straightFlush = false;
	bool royalStraightFlush = false;
	bool fourCard = false;
	bool threeCard = false;
	bool twoPair = false;
	bool fullHouse = false;
	bool highCard = false;
	int count = 0;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j<5-1-i;j++)
		{
			if (player[j].Num > player[j+1].Num)
				swap(player[j],player[j+1]);
		}
	}
	//pair
	if (player[0].Num == player[1].Num)
		count++;
	if (player[1].Num == player[2].Num)
		count++;
	if (player[2].Num == player[3].Num)
		count++;
	if (player[3].Num == player[4].Num)
		count++;
	//two pair x2
	if (count == 2)
		twoPair = true;

	//threesome x4
	if (player[0].Num == player[1].Num)
		if (player[1].Num == player[2].Num)
			threeCard = true;
	else if (player[1].Num == player[2].Num)
		if (player[2].Num == player[3].Num)
			threeCard = true;
	else if (player[2].Num == player[3].Num)
		if (player[3].Num == player[4].Num)
			threeCard = true;
	//four cardx20
	if (player[0].Num == player[1].Num)
	       if (player[1].Num == player[2].Num)
			if(player[2].Num == player[3].Num)
				fourCard = true;
	else if (player[1].Num == player[2].Num)
		if (player[2].Num == player[3].Num)
			if (player[3].Num == player[4].Num)
				fourCard = true;	
	//full housex10
	if (threeCard == true && count == 1)
		fullHouse = true;

	//flushx8
	if (player[0].Pic == player[1].Pic)
		if (player[1].Pic == player[2].Pic)
			if (player[2].Pic == player[3].Pic)
				if (player[3].Pic == player[4].Pic)
					flush = true;
	//straightx6
	if (player[0].Num == 1)//ace case
	{
		if (player[1].Num == player[0].Num+10)//royal straight case
			if (player[2].Num == player[1].Num+1)
				if (player[3].Num == player[2].Num+1)
					if (player[4].Num == player[3].Num+1)
					{
						straight = true;
						royalStraight = true;
					}
	}
	else 
	{
		if (player[1].Num == player[0].Num+1)
			if (player[2].Num == player[1].Num+1)
				if (player[3].Num == player[2].Num+1)
					if(player[4].Num == player[3].Num+1)
						straight = true;
	}

	//straight flush x1000
	if (straight == true && flush == true)
		straightFlush = true;
	
	//royal straight flush x10000
	if (royalStraight == true && flush == true)
		royalStraightFlush = true;
	
	//jack or higherx1
	if (count == 0 || count == 1)
		if (straight == false)
			if (flush == false)
				if (player[4].Num >= 11 || player[0].Num == 1)
					highCard = true;

	//winnings distribution
	
	if (royalStraight == true)
	{
		cout << "Royal Straight! You win $" << bet*(10000) << "!" << endl;
		startingFunds = startingFunds + bet*(10000);
	}
	else if (straightFlush == true)
	{
		cout << "Straight Flush! You win $" << bet*(1000) << "!" << endl;
		startingFunds = startingFunds + bet*(1000);
	}
	else if (fourCard == true)
	{
		cout << "Four of a kind! You win $" << bet*(20) << "!" << endl;
		startingFunds = startingFunds + bet*(20);
	}
	else if (fullHouse == true)
	{
		cout << "Full House! You win $" << bet*(10) << "!" << endl;
		startingFunds = startingFunds + bet*(10);
	}
	else if (flush == true)
	{
		cout << "Flush! You win $" << bet*(8) << "!" << endl;
		startingFunds = startingFunds + bet*(8);
	}
	else if (straight == true)
	{
		cout << "Straight! You win $" << bet*(6) << "!" << endl;
		startingFunds = startingFunds + bet*(6);
	}
	else if (threeCard == true)
	{
		cout << "Three of a kind! You win $" << bet*(4) << "!" << endl;
		startingFunds = startingFunds + bet*(4);
	}
	else if (twoPair == true)
	{
		cout << "Two Pair! You win $" << bet*(2) << "!" << endl;
		startingFunds = startingFunds + bet*(2);
	}
	else if (highCard == true)
	{
		cout << "High Card! You win $" << bet << endl;
		startingFunds = startingFunds;
	}
	else 
	{
		cout << "You lose $" << bet << endl;
		startingFunds = startingFunds - bet;
	}
}

