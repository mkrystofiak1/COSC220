all: run

run: Card.o test.o
	g++ Card.o test.o -o run

Card.o: Card.cpp
	g++ -c Card.cpp

test.o: test.cpp
	g++ -c test.cpp

clean:
	rm -rf *.o run
