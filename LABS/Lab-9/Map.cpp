//Program: Map.cpp
//Author: Mitchell Krystofiak
//Description: This program will set each letter of the alphabet equal to a character and use it to encrypt and decrypt words.
//Date: Decemeber 2, 2020

#include<iostream>
#include<map>
#include<string>
#include<fstream>
using namespace std;

int main()
{	
	//declares a mapping between the alphabet and a random character
	map<char, char> codes = { {'A','!'},{'B','1'},{'C','@'},{'D','2'},{'E','#'},{'F','$'},{'G','4'},{'H','%'},
		                  {'I','5'},{'J','^'},{'K','6'},{'L','&'},{'M','7'},{'N','*'},{'O','8'},{'P','('},
				  {'Q','9'},{'R',')'},{'S','0'},{'T','`'},{'U','~'},{'V','{'},{'W','['},{'X','}'},
				  {'Y',']'},{'Z','.'},{'a',','},{'b','+'},{'c','/'},{'d','|'},{'e',';'},{'f',':'},
				  {'g','z'},{'h','Y'},{'i','?'},{'j','<'},{'k','>'},{'l','-'},{'m','_'},{'n','d'},
				  {'o','W'},{'p','i'},{'q','c'},{'r','L'},{'s','o'},{'t','q'},{'u','A'},{'v','M'},
				  {'w','b'},{'x','J'},{'y','e'},{'z','H'},{' ','='},{'.','P'},{',','E'}
				};
	map<char, char> inverse;
	map<char, char>::iterator it;
	
	for( it = codes.begin(); it != codes.end(); it++)
	{
		inverse[it->second] = it->first;
	}

	ifstream textFile;
	string filename;
	char letter;
	cout << "Enter the filename: ";
	cin >> filename;
	textFile.open(filename);//opens filename requested
	if(!textFile)//checks file validity
	{
		cout << "Error opening file!" << endl;
		exit(1);
	}
	ofstream output;
	output.open("CodedMessage.txt");
	
	//need to encrypt/decrypt
	
	while (!textFile.eof() && textFile.get(letter))//goes through file and encrypts it
	{
		output << codes[letter];
	}
	textFile.close();	
	output.close();
	
	textFile.open("CodedMessage.txt");
	output.open("DecodedMessage.txt");

	while (!textFile.eof() && textFile >> letter)
	{
		output << inverse[letter];
	}
	textFile.close();
	output.close();

	return 0;
}
