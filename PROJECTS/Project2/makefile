all: run


run:  Poker.o Card.o CasinoGame.o Blackjack.o
	g++ Poker.o Card.o CasinoGame.o Blackjack.o -o run

Poker.o: Poker.cpp
	g++ -c Poker.cpp

Card.o: Card.cpp
	g++ -c Card.cpp

CasinoGame.o: CasinoGame.cpp
	g++ -c CasinoGame.cpp

Blackjack.o: Blackjack.cpp
	g++ -c Blackjack.cpp

clean:
	rm -rf *.o run
