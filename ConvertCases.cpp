//Section CSC160 - Computer Science I: C++
//File Name: P64.cpp
//Student: Jeffrey Markham
//Homework Number: Lab 6
//Description: This program reads one character from the keyboard and will
//convert it to uppercase, if it is lowercase convert it to lowercase
//if it is uppercase display a message, if it is a digit
//Last Changed: 04/16/2021

#include <iostream>
#include <ctype.h>
using namespace std;

int main()
{
    char c;

    cout << "Enter a character \n";
    cin >> c;

    if(isalpha(c))
    {
        if(isupper(c))
        {
            c = tolower(c);
            cout << "Your character " << c << " is in uppercase.";
            cout << "Its lowercase case is " << c << endl;
        }
        else
        {
            c = toupper(c);
            cout << "Your character " << c << " is in lowercase.";
            cout << "Its uppercase is " << c << endl;
        }
    }
    else
    {
        cout << "Your character " << c << " is a digit. \n";
    }

    if (isspace(c))
    {
        cout << "Your character " << c << " is a white spaced character.";
    }
    else
    {
        cout << "Your character " << c << " is not a white spaced character. ";
    }
    return 0;
}
