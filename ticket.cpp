//Section CSC160 - Computer Science I: C++
//File Name: ticket 
//Student: Jeffrey Markham
//Homework Number: Exercise 32-1  
//Description: program asks for an age and displays the cost of ticket
//Last Changed:

#include <iostream>
using namespace std;

int main()
{
    double age, ticket = 12;

    cout << "Please enter the age\n";
    cin >> age;

    if (age <= 8 || age >= 65)
    {
        ticket = 6;
    }
    else
    {
        ticket = 12;
    }
    cout << "Your tickets costs " << ticket << endl;

    cout << endl;
    system ("pause");
    return 0;
}