all: run

run: TNode.o BST.o Lab7.o
	g++ TNode.o BST.o Lab7.o -o run

TNode.o: TNode.cpp
	g++ -c TNode.cpp

BST.o: BST.cpp
	g++ -c BST.cpp

Lab7.o: Lab7.cpp
	g++ -c Lab7.cpp

clean:
	rm -rf *.o run
