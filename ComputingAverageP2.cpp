//Section CSC160 - Computer Science I: C++
//File Name: ex33_4 
//Student: Jeffrey Markham
//Homework Number: P33_3
//Description:
//Last Changed:

#include <iostream>
using namespace std;

int main()
{
    int x;
    int count = 0; //(1) initialize a counter to 0 to count number of values
    int N; //Number of values for which the average must be computed
    double sum = 0; //initialize the sum to 0 to make sure the sum at the beginning is 0
    double average;

    cin >> N;
    do
    {
        //read each number and compute the sum:
        cout << "\n Enter a grade <Enter>: ";
        cin >> x;
        sum = sum + x;
        count++; //(3) update the count

    } while (count < N); //(2) read N gardes and compute their sum, count ensures N entries

    if (N == 0)
    {
        cout << "You haven't enter 0 number, no average will be computed, bye \n";
    }
    else
    {
        average = average = sum / N;
        cout << "The average of these " << N << " grades is " << average << endl;
    }

    cout << endl;
    system ("pause");
    return 0;
}