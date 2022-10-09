//Section CSC160 - Computer Science I: C++
//File Name: P53_1.cpp
//Student: Jeffrey Markham
//Homework Number: Lab 5
//Description: Computes the total cost of purchases made
//Last Changed: 03/25/2021

#include <iostream>
using namespace std;

double total_cost (int number_par, double price_par);//(1) Function delcaration

int main()
{
    double price, bill;
    int number;

    cout << "Enter the number of items purchased: ";
    cin >> number;
    cout << "Enter the price per item $";
    cin >> price;

    bill = total_cost (number, price);//(2) Function call

    // The following three lines are used for formatting purposes. Since a precision of 2
    // is set, then all numbers will be displayed with two decimal points. We work with $
    // this seems to be the most appropriate way to display the numbers.
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    cout << number << " items at " << "$" << price << " each. \n" << "Final bill, including tax, is $" << bill << endl;

    cout << endl;
    system ("pause");
    return 0;
}

//(3) Function definition 
double total_cost(int number_par, double price_par)//Function heading
{//Function body begins here
    const double TAX_RATE = 0.05; //5% sales tax, const is to make sure this value stays unchanged
    double subtotal;

    subtotal = price_par * number_par;

    return (subtotal + subtotal * TAX_RATE);
}//Function body ends here