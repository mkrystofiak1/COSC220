//Program: Unique.cpp
//Author: Mitchell Krystofiak
//Description: This program will analyze a text file and print out a list of the unique words.
//Date: December 2, 2020

#include<iostream>
#include<set>
#include<fstream>
#include<string>
using namespace std;

int main()
{
	
	string word,filename;
	set<string> unique; // declare set for unique words
	set<string>::iterator it; //declare iterator to access the set members
	cout << "Enter the file name: ";//gets filename and opens it
	cin >> filename;	
	ifstream textFile;
	textFile.open(filename);
	if (!textFile)//tests for if valid filename
	{
		cout << "Error opening file!" << endl;
		exit(1);
	}
	while (!textFile.eof() && textFile >> word)//scans through the file
	{
		unique.insert(word);//inserts the word into the set, but does not insert repeated words
	}
	textFile.close();
	for (it = unique.begin(); it != unique.end(); it++) //prints out the sets contents
		cout << *it << endl;
	return 0;
}
