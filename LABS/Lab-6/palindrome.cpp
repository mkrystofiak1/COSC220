//Program: palindrome.cpp
//Author: Mitchell Krystofiak
//Description: This program will test for palindromes.
//Date: November 3, 2020

#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

bool isPalindrome(string input, int start, int end)
{
	if (start < end)
	{
		if (input[start] != input[end])
		{
			return false;
		}
		return isPalindrome(input, start + 1, end -1);
	}
	else
	{
		return true;
	}
}

int main()
{
	string input, copy;
	int count = 0;
	cout << "Enter a string: ";
	getline(cin, input);
	cout << endl;
	copy = input;
	
	copy.erase(remove(copy.begin(), copy.end(), ' '), copy.end());

	int size = copy.length()-1;
	if (isPalindrome(copy, 0, size))
		cout << "Is a palindrome!" << endl;
	else
		cout << "Is not a palindrome!" << endl;

	return 0;
}
