Instructions for how to compile and operate the Casino Game!
Author: Mitchell Krystofiak
Last Updated: December 8, 2020

1. Download the zip file titled "Casino.zip"
2. You will need to extract the files inside of Casino.zip. There are two ways to do this:
	
	(a) You can navigate to the directory where Casino.Zip is downloaded and extract the files
	(b) You can download the unzip utility to unzip a folder from the terminal

	Method (a): 1.Click on the file manager
		    2.Navigate to the directory where Casino.zip is downloaded
		    3.Right click on the file titled "Casino.zip" and click "extract here" or
		      "extract..." and select where you want the files to unzip to.
		    4.The place you extracted the files to should have a new directory with those
                      files enclosed in it.
	Method (b): 1.Right click on the desktop and click "Open in terminal".
                    2.Navigate to the directory where Casino.zip is downloading by using "cd" to 
                      change directories.
		    3.You will need to type the following command "sudo apt-get install unzip" and 
                      follow the the instructions. This will add an unzip utility to your system.
		    4.Now, you can type "unzip Casino.zip" if you wish to extract the files into the
                      same directory. Type "unzip Casino.zip -d DESTINATION_FOLDER", inserting the 
                      name of the directory into the DESTINATION_FOLDER field.
                    5.The place you unzipped the files to should have a new directory with those
		      files enclosed in it.

3. Once the files are extracted, you need to make sure g++ is installed to compile the program.
   Type in the terminal "sudo apt install g++" and follow the instructions to install the g++
   compiler.
4. Once the g++ compiler is installed, you will also need to install the "make" command. Type in the    terminal "sudo apt install make" and follow the instructions to install make.
5. Now we can compile the program. In the extracted files, there is a file called "makefile". This is   the key to compiling. Type "make" to compile the program. 
6. After the program successfully compiles, you can now type "./run" to start the Casino game.


In Game Operation

1. When in game, you will be prompted to play either poker or black jack. Type in "p" or "P" for
   poker, or "b" or "B" for blackjack.
2. Next, the program will ask for you to input how much money you want to start with. Type in an 
   integer amount.
3. Next, the program will ask again if you want to play the game. If you would like to, type in "y"
   or "Y", if not, type in "n" or "N" and it will print out your financial information for the game.
4. Next, the program will ask what you would like to bet. Type in an integer amount less than 
   your starting amount. The program will not let you type in a value that doesn't make sense.
5. Now the game will begin, either poker or blackjack. The game will operate as follows:
	
	Poker: You will be dealt five cards. Pick which cards you want to redraw by typing either
               0 or 1. After changing cards, you will see your final hand and your winnings.
	BlackJack: You will be dealt two cards and so will the dealer. If the dealers top card is an 			ace, you will be asked to bet insurance. Decide if you want to or not. Then, you
		   you will be asked if you want to hit or stand. Decide accordingly. After you bust
		   or you stand, your card sum will be compared to the dealers and you will then see
		   your winnings, if any.

6. If you have money remaining after the bet, you will be prompted to play again. Then, the game
   either ends or you will be asked to repeat the betting and playing option.

Thank you for downloading the Casino Game. I hope that you enjoy it!
