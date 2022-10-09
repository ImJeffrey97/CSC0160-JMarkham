//Section CSC160 - Computer Science I: C++
//File Name: Lab 4 p4_1
//Student: Jeffrey Markham
//Homework Number: p4_1
//Description: A program that uses an array of integers
//Last Changed: 02/24/2021

#include <iostream>
using namespace std;

int main(void)
{
    int numlist[8], i;

    //Read 8 integers from the keyboard
    for (i = 0; i < 8; i++)
    {
        cout << "Enter value #" << i + 1 << ": ";
        cin >> numlist[i];
    }   
    //Displays the numbers in reverse order 
    for (i = 8; i > 0; i--)
    {
        cout << "Value #" << i << ": ";
        cout << numlist[i-1] << endl; //Pay attention to i-1!
    }
    
    cout << endl;
    system ("pause");
    return 0;
}