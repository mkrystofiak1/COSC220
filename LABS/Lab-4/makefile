all: run

run: Node.o LinkedList.o La3.o
	g++ Node.o LinkedList.o La3.o -o run

Node.o: Node.cpp
	g++ -c Node.cpp

LinkedList.o: LinkedList.cpp
	g++ -c LinkedList.cpp

La3.o: La3.cpp
	g++ -c La3.cpp
clean:
	rm -rf *o run
