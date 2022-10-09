//Section CSC160 - Computer Science I: C++
//File Name: Lab 4 P4_1b
//Student: Jeffrey Markham
//Homework Number: P4_1b
//Description: A program that uses a flexible size array of integers
//Last Changed: 02/24/2021

#include <iostream>
using namespace std;

const int SIZE = 8; //Set th maximum size for the array

int main(void)
{
    int numlist[SIZE];

    //Read SIZE integers from the keyboard
    for (int i = 0; i < SIZE; i++)
    {
        cout << "Enter value #" << i + 1 << ": ";
        cin >> numlist[i];
    }    

    //Display the numbers in reverse order
    for (int i = SIZE; i > 0; i--)
    {
        cout << "Value #" << i << ": ";
        cout << numlist[i - 1] << endl; //Pay attention to i - 1!
    }
    
    cout << endl;
    system ("pause");
    return 0;
}