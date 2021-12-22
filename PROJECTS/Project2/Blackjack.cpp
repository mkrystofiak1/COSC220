//Program: Blackjack.cpp
//Author: Mitchell Krystofiak
//Description: Implementation of the Blackjack Class.
//Date: December 8, 2020

#include"Blackjack.h"
#include"Card.h"
#include<iostream>

using namespace std;

Blackjack::Blackjack()
{
	ShuffleCard();
	
	//deal 1 card to player, 1 card to dealer both face up
	player[0] = GetCard();
	dealer[0] = GetCard();
	//deal next card to player, and another to dealer, should be face down for dealer
	player[1] = GetCard();
	dealer[1] = GetCard();
	Pcounter = 2;
	Dcounter = 2;
}

void Blackjack::playGame(int& startingFunds, int& bet, int& insurance)
{
	int dealerSum=0;
	int playerSum=0;
        int play;
	int position = 1;
	char insur;
	bool game = true;
	int r = 0;
	if (dealer[0].Num == 1)//condition to prompt for insurance
	{
		cout << "Dealers Top Card:" << endl;
		printHand(2);
                cout << "-------------------------------------------" << endl;
                cout << endl;
                cout << "   Would you like to bet insurance(Y/N)?   " << endl;
        	cout << endl;
        	cout << "-------------------------------------------" << endl;
        	cin >> insur;
        	while ( insur != 'y' && insur != 'Y' && insur != 'n' && insur != 'N')
        	{
              		cout << "-------------------------------------------" << endl;
                	cout << endl;
              		cout << "             Invalid response!             " << endl;
              		cout << endl;
              		cout << "   Would you like to bet insurane(Y/N)?    " << endl;
              		cout << endl;
              		cout << "-------------------------------------------" << endl;
              		cin >> insur;
        	}
        	if (insur == 'Y' || insur == 'y')
                	insurance = (0.5)*bet;
		else 
			insurance = 0;	
	}
	dealerSum = dealerSum + blackjackConditions(dealer, 0) + blackjackConditions(dealer,1);
	playerSum = playerSum + blackjackConditions(player, 0) + blackjackConditions(player,1);
	//check if dealer has blackjack
	
	if (dealerSum == 21)//if dealer has blackjack
	{
		if (playerSum == 21)//if player also has blackjack
		{
			game = false;
			determineWinner(1, startingFunds, bet, insurance);
			r = 1;
		}
		else//if player does not have blackjack but dealer does
		{
			game = false;
			determineWinner(2, startingFunds, bet, insurance);
			r = 1;
		}
	}
	else if (playerSum == 21)//if player has blackjack and dealer does not
	{
		game = false;
		determineWinner(3,startingFunds, bet, insurance); 
		r = 1;
	}
	//player goes first
	if (game)
	{
		cout << "Dealers Top Card:" << endl;
		printHand(2);
	}
	while(game)
	{
		cout << "Players Cards:" << endl;
		printHand(3);
		cout << "-------------------------------------------" << endl;
		cout << endl;
		cout << "            Hit(1) or Stand(0)?            " << endl;	
		cout << endl;
		cout << "-------------------------------------------" << endl;
		cin >> play;
		while (play != 0 && play != 1)
		{
			cout << "-------------------------------------------" << endl;
			cout << endl;
			cout << "             Invalid response!             " << endl;
			cout << endl;
			cout << "            Hit(1) or Stand(0)?            " << endl;
			cout << endl;
			cout << "-------------------------------------------" << endl;
			cin >> play;
		}
		if (play == 1)
		{
			position++;
			player[position] = GetCard();
			Pcounter++;
			playerSum = playerSum + blackjackConditions(player,position);
			if (playerSum > 21 || playerSum == 21)
			{
				game = false;
				cout << game << endl;
			}
		}
		else if (play == 0)
		{
			game = false;
		}

	}
	if (r == 0)//condition to not recheck cards after beginning conditions
	{
		int j = 3;
        	//dealers turn
		if (dealerSum >= 17)
			j = 2;
        	for (int i = 2; i < j; i++)
        	{
			dealer[i] = GetCard();
			Dcounter++;
                	dealerSum = dealerSum + blackjackConditions(player,position);
                	if (dealerSum < 17)
			{
				j++;//need to consider if one of these cards is an ace, then we can say sum-10 to count ace as 1 instead of 11
			
			}
        	}
		if (playerSum > 21) //player breaks, dealer doesn't matter
		{
			determineWinner(4, startingFunds, bet, insurance);
		}
		else if (playerSum <= 21)
		{
			if (playerSum == dealerSum)//equal hands
				determineWinner(1, startingFunds, bet, insurance);
			else if (playerSum > dealerSum)
				determineWinner(5, startingFunds, bet, insurance);
			else if (playerSum < dealerSum)
				determineWinner(6, startingFunds, bet, insurance);
		}	
	}	

}

int Blackjack::determineWinner(int i,int& startingFunds, int& bet, int& insurance)
{
	if (i == 1) //if both the dealer and player have blackjack pregame
	{
		//no bets are exchanged, the player doesnt lose any money
		cout << "Player cards:" << endl;
		printHand(1);
		cout << "Dealer cards:" << endl;
		printHand(4);
		cout << "You break even!" << endl;
		
		return startingFunds;
	}
	else if (i == 2) //if only dealer has blackjack pregame
	{
		//if player bet insurance, they lose 50 percent of bet, if no insurance, they lose bet
		if (insurance == 0)
		{
			startingFunds = startingFunds - bet;
			cout << "Player cards:" << endl;
                	printHand(1);
        	        cout << "Dealer cards:" << endl;
	                printHand(4);

			cout << "You lost your bet!" << endl;
			return startingFunds;
		}
		else
		{
			startingFunds = startingFunds - insurance;
			cout << "Player cards:" << endl;
                	printHand(1);
        	        cout << "Dealer cards:" << endl;
	                printHand(4);

			cout << "You lost half of your bet because of insurance!" << endl;
			return startingFunds;
		}
	}
	else if (i == 3) //if only player has blackjack pregame
	{
		//player automatically wins 1.5 times bet
		startingFunds = startingFunds + (1.5)*bet;
		cout << "Player cards:" << endl;
                printHand(1);

		cout << "Blackjack! You win 1.5 times your bet!" << endl;
		return startingFunds;
	}
	else if (i == 4) //if player breaks
	{
		//player loses bet
		startingFunds = startingFunds - bet;
		cout << "Player cards:" << endl;
                printHand(3);
                cout << "Dealer cards:" << endl;
                printHand(4);

		cout << "You lost your bet!" << endl;
		return startingFunds;
	}
	else if (i = 5) //if players sum is greater than dealers
	{
		//player doesn't lose money
		cout << "Player cards:" << endl;
                printHand(3);
                cout << "Dealer cards:" << endl;
                printHand(4);

		cout << "You break even1!" << endl;
		return startingFunds;
	}
	else if (i = 6)//if dealer sum is greater than players
	{
		//player loses bet
		startingFunds = startingFunds - bet;
		cout << "Player cards:" << endl;
                printHand(3);
                cout << "Dealer cards:" << endl;
                printHand(4);

		cout << "You lost your bet!" << endl;
		return startingFunds;
	}
	else
		return 0;
}

void  Blackjack::printHand(int i)
{
	switch(i)
	{
		case 1: //initial player hand
			printMultiple(player, 2);
			break;
		case 2: //initial dealer hand
			printMultiple(dealer,1);
			break;
		case 3: //final player hand
			printMultiple(player,Pcounter);
			break;
		case 4: //final dealer hand
			printMultiple(dealer,Dcounter);
			break;
	}
}
	
