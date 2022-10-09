//Section CSC160 - Computer Science I: C++
//File Name: Lab 1
//Student: Jeffrey Markham
//Homework Number: Lab 1 
//Description: Grocery store part 2
//Last Changed: 01/29/2021
//P11.cpp - This C++ Program will compute the profits of selling soft drinks

#include <iostream>
using namespace std;

int main()
{

    int cases_per_day, bottles_per_day;
    int bottles_per_case = 12;
    double profit_per_bottle = 0.22; //cents per bottle profit
    double profit_per_day, profit_per_year, profit_10_years;

    cout << "Press enter after entering each number \n";

    cout << "Enter number of cases \n";
    cin >> cases_per_day;

    profit_per_day = cases_per_day * bottles_per_case * profit_per_bottle;
    profit_per_year = 365 * profit_per_day;

    cout << "The store has made: ";
    cout << profit_per_day;
    cout << " per day. \n";

    bottles_per_day = cases_per_day * 12;

    cout << "The number of bottles sold: ";
    cout << bottles_per_day << endl;

    cout << "That means the profit for one year will be: ";
    cout << profit_per_year << endl;

    profit_10_years = profit_per_year * 10;

    cout << "That means the profit for 10 years will be: ";
    cout << profit_10_years << endl;

    cout << "Good business?! \n";

    return 0;
}