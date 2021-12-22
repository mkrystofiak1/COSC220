//Program: TextFiles.cpp
//Author: Mitchell Krystofiak
//Description: This program will display unique words in text files, the words that appear in both, and the ones that appear in one and not the other.
//Date: Decemeber 2, 2020

#include<iostream>
#include<fstream>
#include<string>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;

void displayUnion(set<string> set1, set<string> set2)
{
	vector<string> result(set1.size() + set2.size());

	auto iter = set_union(set1.begin(), set1.end(), set2.begin(), set2.end(), result.begin());
	result.resize(iter - result.begin());

	for (auto element: result)
		cout << element << " ";
	cout << endl;
}

void displayIntersection(set<string> set1, set<string> set2)
{
	vector<string> result(set1.size() + set2.size());

	auto iter = set_intersection(set1.begin(),set1.end(), set2.begin(), set2.end(), result.begin());
	result.resize(iter - result.begin());

	for (auto element: result)
		cout << element << " ";
	cout << endl;
}

void difference(set<string> set1, set<string> set2)
{
	vector<string> result(set1.size() + set2.size());

	auto iter = set_difference(set1.begin(),set1.end(),set2.begin(),set2.end(),result.begin());
	result.resize(iter - result.begin());

	for (auto element: result)
		cout << element << " ";
	cout << endl;
}

void symmetric(set<string> set1, set<string> set2)
{
	vector<string> result(set1.size() + set2.size());

	auto iter = set_symmetric_difference(set1.begin(),set1.end(),set2.begin(),set2.end(),result.begin());
	result.resize(iter - result.begin());

	for (auto element: result)
		cout << element << " ";
	cout << endl;
}

int main()
{
	string word, filename1, filename2;
	set<string> first;
	set<string> second;

	set<string>::iterator it;
	set<string>::iterator it2;
	ifstream textFile;

	cout << "Enter the first file's name: ";
	cin >> filename1;

	cout << "Enter the second file's name: ";
	cin >> filename2;
	
	textFile.open(filename1);
	if (!textFile)
	{
		cout << "Error opening first file!" << endl;
		exit(1);
	}

	while (!textFile.eof() && textFile >> word)
	{
		first.insert(word);
	}
	textFile.close();

	textFile.open(filename2);
	if (!textFile)
	{
		cout << "Error opening second file!" << endl;
		exit(1);
	}

	while(!textFile.eof() && textFile >> word)
	{
		second.insert(word);
	}
	textFile.close();
	
	cout << "Unique words in both files: " << endl;
	cout << endl;
	displayUnion(first, second);

	cout << endl;
	
	cout << "Words that appear in both files: " << endl;
	cout << endl;
	displayIntersection(first, second);

	cout << endl;

	cout << "Words that appear only in the first file: " << endl;
	cout << endl;
	difference(first, second);

	cout << endl;

	cout << "Words that appear only in the second file: " << endl;
	cout << endl;
	difference(second, first);

	cout << endl;

	cout << "Words that appear in either file but not both: " << endl;
	cout << endl;
	symmetric(first, second);

	return 0;
}
