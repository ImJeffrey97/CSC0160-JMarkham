//Section CSC160 - Computer Science I: C++
//File Name: Lab 1
//Student: Jeffrey Markham
//Homework Number: Lab 1 
//Description: Grocery store
//Last Changed: 01/29/2021
//P11.cpp - This C++ Program will compute the profits of selling soft drinks

#include <iostream>
using namespace std;

int main()
{

    int cases_per_day, bottles_perday;
    int bottles_per_case = 12;
    double profit_per_bottle = 0.2; //cents per bottle profit
    double profit_per_day, profit_per_year;

    cout << "Press enter after entering each number \n";
    cout << "Enter number of cases \n";
    cin >> cases_per_day;

    profit_per_day = cases_per_day * bottles_per_case * profit_per_bottle;
    profit_per_year = 365 * profit_per_day;

    cout << "The store has made: ";
    cout << profit_per_day;
    cout << " per day. \n";
    cout << "That means the profit for one year will be: ";
    cout << profit_per_year << endl;
    cout << "Good business?! \n";
    
    return 0;
}