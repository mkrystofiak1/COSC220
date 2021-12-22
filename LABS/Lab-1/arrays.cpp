//Program: arrays.cpp
//Author: Mitchell Krystofiak
//Description: This program will calculate the mean of an array of numbers
//             using two different functions.
//Date: 09/15/2020

#include <iostream>

using namespace std;
double mean(int [],int  n);
double mean2(int *ptr, int n);

int main()
{
    cout << "Please enter the number integers to put in an array: ";
    int n;
    cin >> n;
    while (n<=0)
    {
        cout << "Input is not positive." << endl;
        cout << "Please enter the number of integers to put in an array: ";
        cin >> n;
    }
    cout << "Please enter integers to fill the array: ";
    int array[n];

    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
        while (array[i]<=0)
        {
            cout << "Input is not positive." << endl;
            cout << "Please enter a positive integer: ";
            cin >> array[i];
        }
    }
    double average = mean(array,n);
    int *ptr;
    ptr = array;
    double average2 = mean2(ptr,n);
    cout << "The mean using function 1 is: " << average << endl;
    cout << "The mean using function 2 is: " << average2 << endl;
    return 0;
}
double mean(int array[],int n)
{
    double average = 0;
    int sum = 0;
    for (int i=0; i<n;i++)
    {
        sum = sum + array[i];
    }
    average = sum/static_cast<double>(n);
    return average;
}
double mean2(int *ptr, int n)
{
    double average = 0;
    int sum = 0;
    for (int i = 0; i < n ; i++)
    {
        sum = sum + *(ptr + i);
    }
    average = sum/static_cast<double>(n);
    return average;
}
