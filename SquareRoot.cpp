//Section CSC160 - Computer Science I: C++
//File Name: ex7_1.cpp
//Student: Jeffrey Markham
//Homework Number: Lab 7 
//Description: A program that asks users to enter a number from
//the keyboard and computes its square root
//Last Changed: 04/27/2021

#include <iostream>
#include <cmath>
using namespace std;


int main()
{
    int userNum;
    double squaredNum;


    try
    {
        cout << "Enter a number you want a square root of: ";
        cin >> userNum;    

        if(userNum <= 0)
        {
            throw userNum;
        }
        squaredNum = sqrt(userNum);   

        cout << "The square root of that number is " << squaredNum << endl;
    }

    catch(int e)
    {
        cout << e << " The number you have chosen is a negative number"
             << " you cannot take the square root of a negative number" << endl;
    }
    
    cout << "End of program";

    cout << endl;
    system ("pause");
    return 0;
}