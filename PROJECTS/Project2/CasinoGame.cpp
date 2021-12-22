//Program: CasinoGame.cpp
//Author: Mitchell Krystofiak
//Description: This program demonstrates the Blackjack and the Poker card game classes.
//Date: December 8, 2020

#include"Card.h"
#include"Poker.h"
#include"Blackjack.h"

#include<iostream>

using namespace std;

int main()
{
	int startingFunds, startingFundsCopy, bet, insurance;
	char gameSelection, insur;
        char playGame = 'y';
	cout << "-------------------------------------------" << endl;
	cout << endl;
	cout << "           Welcome to the Casino!          " << endl;
	cout << endl;
	cout << "     Play Poker (P) or Black Jack (B)?     " << endl;
	cout << endl;
	cout << "-------------------------------------------" << endl;
	cout << endl;
	cin >> gameSelection;
	while (gameSelection != 'P' && gameSelection != 'p' && gameSelection != 'B' && gameSelection != 'b')
	{
		cout << "-------------------------------------------" << endl;
		cout << endl;
		cout << "          Invalid game selection!          " << endl;
		cout << endl;
		cout << "     Play Poker (P) or Black Jack (B)?     " << endl;
		cout << endl;
		cout << "-------------------------------------------" << endl;
		cin >> gameSelection;
	}
	if (gameSelection == 'P' || gameSelection == 'p')
	{
		cout << "-------------------------------------------" << endl;
		cout << endl;
		cout << "             Welcome to Poker!             " << endl;
		cout << endl;
		cout << "         Enter seed money to play!         " << endl;
		cout << endl;
		cout << "-------------------------------------------" << endl;
		cin >> startingFunds;
		while (startingFunds <= 0)
		{
			cout << "-------------------------------------------" << endl;
			cout << endl;
			cout << "     You can't play with that amount!      " << endl;
			cout << endl;
			cout << "         Enter seed money to play!         " << endl;
			cout << endl;
			cout << "-------------------------------------------" << endl;
			cout << endl;
			cin >> startingFunds;
		}
		startingFundsCopy = startingFunds;
		cout << "-------------------------------------------" << endl;
		cout << endl;
		cout << "     Would you like to play game? (Y/N)    " << endl;
		cout << endl;
		cout << "-------------------------------------------" << endl;
		cin >> playGame;
		while (playGame != 'Y' && playGame !='y' && playGame != 'N' && playGame != 'n')
		{
			cout << "-------------------------------------------" << endl;
			cout << endl;
			cout << "              Invalid choice!              " << endl;
			cout << endl;
			cout << "     Would you like to play game? (Y/N)    " << endl;
			cout << endl;
			cout << "-------------------------------------------" << endl;
			cin >> playGame;
		}
		if (playGame == 'N' || playGame == 'n')
		{
			cout << "-------------------------------------------" << endl;
                        cout << endl;
                        cout << "       Starting Funds = $" << startingFundsCopy << "      " << endl;
                        cout << endl;
                        cout << "       Ending Funds = $" << startingFunds << "      " << endl;
                        cout << endl;
                        cout << "       Total Winnings = $" << startingFunds-startingFundsCopy << "      " << endl;
                        cout << endl;
                        cout << "             Thanks for playing!           " << endl;
                        cout << endl;
                        cout << "-------------------------------------------" << endl;
                        exit(0);
		}
		else if (playGame == 'Y' || playGame == 'y')
		{
			while (playGame == 'Y' || playGame == 'y')
			{
			cout << "-------------------------------------------" << endl;
			cout << endl;
			cout << "        How much do you want to bet?       " << endl;
			cout << endl;
			cout << "-------------------------------------------" << endl;
			cin >> bet;
			while (bet > startingFunds || bet <= 0)
			{
				if ( bet > startingFunds)
				{
					cout << "-------------------------------------------" << endl;
					cout << endl;
					cout << "  Bet cannot be more than your seed money! " << endl;
					cout << endl;
					cout << "       How much do you want to bet?        " << endl;
					cout << endl;
					cout << "-------------------------------------------" << endl;
					cin >> bet;
				}
				else if (bet <= 0)
				{
					cout << "-------------------------------------------" << endl;
                                        cout << endl;
                                        cout << "   Bet cannot be less than or equal to 0!  " << endl;
                                        cout << endl;
                                        cout << "       How much do you want to bet?        " << endl;
                                        cout << endl;
                                        cout << "-------------------------------------------" << endl;
                                        cin >> bet;
				}
			}
			Poker Game;
			Game.printHand();
			Game.changeCards();
			cout << "Final Hand:" << endl;
			Game.printHand();
			Game.determineHandValue(startingFunds, bet);
			if (startingFunds <= 0)
			{
				cout << "-------------------------------------------" << endl;
				cout << endl;
				cout << "          You've run out of money!         " << endl;
				cout << endl;
				cout << "             Thanks for playing!           " << endl;
				cout << endl;
				cout << "-------------------------------------------" << endl;
				exit(1);
			}
			cout << "-------------------------------------------" << endl;
			cout << endl;
			cout << "       Would you like to play again?       " << endl;
			cout << endl;
			cout << "-------------------------------------------" << endl;
			cin >> playGame; //need to play again where we don't ask for seed money at beginning, should be keeping track based on betting and winnings
			if (playGame == 'N' || playGame == 'n')
                	{
                        	cout << "-------------------------------------------" << endl;
                                cout << endl;
                                cout << "       Starting Funds = $" << startingFundsCopy << "      " << endl;
                                cout << endl;
                                cout << "       Ending Funds = $" << startingFunds << "      " << endl;
                                cout << endl;
                                cout << "       Total Winnings = $" << startingFunds-startingFundsCopy << "      " << endl;
                                cout << endl;
                                cout << "             Thanks for playing!           " << endl;
                                cout << endl;
                                cout << "-------------------------------------------" << endl;
                                exit(0);
                	}
			}
		}
	}
	else if (gameSelection == 'B' || gameSelection == 'b')
	{
		cout << "-------------------------------------------" << endl;
                cout << endl;
                cout << "           Welcome to Black Jack!          " << endl;
                cout << endl;
                cout << "          Enter seed money to play!        " << endl;
                cout << endl;
                cout << "-------------------------------------------" << endl;
                cin >> startingFunds;
                while (startingFunds <= 0)
                {
                        cout << "-------------------------------------------" << endl;
                        cout << endl;
                        cout << "     You can't play with that amount!      " << endl;
                        cout << endl;
                        cout << "         Enter seed money to play!         " << endl;
                        cout << endl;
                        cout << "-------------------------------------------" << endl;
                        cout << endl;
                        cin >> startingFunds;
                }
		startingFundsCopy = startingFunds;
		cout << "-------------------------------------------" << endl;
                cout << endl;
                cout << "     Would you like to play game? (Y/N)    " << endl;
                cout << endl;
                cout << "-------------------------------------------" << endl;
                cin >> playGame;
                while (playGame != 'Y' && playGame != 'y' && playGame != 'n' && playGame != 'N')
                {
                        cout << "-------------------------------------------" << endl;
                        cout << endl;
                        cout << "              Invalid choice!              " << endl;
                        cout << endl;
                        cout << "     Would you like to play game? (Y/N)    " << endl;
                        cout << endl;
                        cout << "-------------------------------------------" << endl;
                        cin >> playGame;
                }
		if (playGame == 'N' || playGame == 'n')
                {
                        cout << "-------------------------------------------" << endl;
                        cout << endl;
                        cout << "       Starting Funds = $" << startingFundsCopy << "      " << endl;
                        cout << endl;
                        cout << "       Ending Funds = $" << startingFunds << "      " << endl;
                        cout << endl;
                        cout << "       Total Winnings = $" << startingFunds-startingFundsCopy << "      " << endl;
                        cout << endl;
                        cout << "             Thanks for playing!           " << endl;
                        cout << endl;
                        cout << "-------------------------------------------" << endl;
                        exit(0);
                }
                else if (playGame == 'Y' || playGame == 'y')
                {
			while (playGame == 'Y' || playGame == 'y')
			{
			cout << "-------------------------------------------" << endl;
                        cout << endl;
                        cout << "        How much do you want to bet?       " << endl;
                        cout << endl;
                        cout << "-------------------------------------------" << endl;
                        cin >> bet;
                        while (bet > startingFunds || bet <= 0)
                        {
                                if ( bet > startingFunds)
                                {
                                        cout << "-------------------------------------------" << endl;
                                        cout << endl;
                                        cout << "  Bet cannot be more than your seed money! " << endl;
                                        cout << endl;
                                        cout << "       How much do you want to bet?        " << endl;
                                        cout << endl;
                                        cout << "-------------------------------------------" << endl;
                                        cin >> bet;
                                }
                                else if (bet <= 0)
                                {
                                        cout << "-------------------------------------------" << endl;
                                        cout << endl;
                                        cout << "   Bet cannot be less than or equal to 0!  " << endl;
                                        cout << endl;
                                        cout << "       How much do you want to bet?        " << endl;
                                        cout << endl;
                                        cout << "-------------------------------------------" << endl;
                                        cin >> bet;
                                }
                        }
			Blackjack Game1;
			Game1.playGame(startingFunds, bet, insurance);	
			if (startingFunds <= 0)
                        {
                                cout << "-------------------------------------------" << endl;
                                cout << endl;
                                cout << "          You've run out of money!         " << endl;
                                cout << endl;
                                cout << "             Thanks for playing!           " << endl;
                                cout << endl;
                                cout << "-------------------------------------------" << endl;
                                exit(1);
                        }
			cout << "-------------------------------------------" << endl;
                        cout << endl;
                        cout << "       Would you like to play again?       " << endl;
                        cout << endl;
                        cout << "-------------------------------------------" << endl;
                        cin >> playGame; //need to play again where we don't ask for seed money at beginning, should be keeping track based on betting and winnings
                        if (playGame == 'N' || playGame == 'n')
                        {
                                cout << "-------------------------------------------" << endl;
                                cout << endl;
				cout << "       Starting Funds = $" << startingFundsCopy << "      " << endl;
				cout << endl;
				cout << "       Ending Funds = $" << startingFunds << "      " << endl;
				cout << endl;
				cout << "       Total Winnings = $" << startingFunds-startingFundsCopy << "      " << endl;
				cout << endl;
                                cout << "             Thanks for playing!           " << endl;
                                cout << endl;
                                cout << "-------------------------------------------" << endl;
                                exit(0);
                        }
			}
                }

	}
	return 0;
}
