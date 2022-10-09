//Section CSC160 - Computer Science I: C++
//File Name: P34_1 
//Student: Jeffrey Markham
//Homework Number: P34_1 
//Description: read and average some integers, print the result
//Last Changed:

#include <iostream>
using namespace std;

int main()
{
    int x;
    int count = 0; //(1) initialize a counter to 0 to count  number of values
    int choice = 1; //This is the choice that controls the looping continuation or termination
    double sum = 0; // initialize the sum to 0 to make sure the sum at the beginning is 0 
    double average;

    while (choice == 1) //(2) read N grades and compute their sum, count ensures N entries
    {
        //read each number and compute the sum:
        cout << "\n Enter a grade <Enter>: ";
        cin >> x;
        sum = sum + x;
        count++; //(3) update the count
        //prompt the user:
        cout << "Do you wish to enter another grade? (1 for yes and 0 or other key for no): " << endl;
        cin >> choice;
    }

    if (count == 0)
    {
        cout << "You haven't entered any number, no average will be computed, bye \n";
    }
    else
    {
        average = sum / count; //Notice that we have divided by count this time
        cout << "The average of these " << count << " grade is " << average << endl;
    }
    
    cout << endl;
    system ("pause");
    return 0;
}