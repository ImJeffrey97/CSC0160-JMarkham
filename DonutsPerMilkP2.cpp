//Section CSC160 - Computer Science I: C++
//File Name: P7_1b.cpp
//Student: Jeffrey Markham
//Homework Number: Lab 7 
//Description: This program computes donuts per glass of milk
//This program uses the C++ exception handling
//Last Changed: 04/27/2021

#include <iostream>
using namespace std;


int main()
{
    int donuts, milk;
    double dpg;

    try
    {
        cout << "Enter number of donuts:\n";
        cin >> donuts;
        cout << "Enter number of glasses of milk: \n";
        cin >> milk;
    
        if(milk <=0)
        {
            throw donuts;
        }
        dpg = donuts/double(milk);
        cout << donuts << " donuts.\n"
             << milk << " glasses of milk.\n"
             << "you have " << dpg
             << " donuts for each glass of milk. \n";
    }

    catch(int e)
    {
        cout << e << " donuts, and No Milk!\n"
             << "Go buy some milk.\n";
    }

    cout << "End of program. \n";
    
    cout << endl;
    system ("pause");
    return 0;
}