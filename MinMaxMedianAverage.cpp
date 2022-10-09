//Section CSC160 - Computer Science I: C++
//File Name: Exercise42
//Student: Jeffrey Markham
//Homework Number: Exercise42
//Description: asking a user to input up to 20 numbers and find the maximum, minimum, average, and median.
//Last Changed: 03/03/2021

#include <iostream>
using namespace std;

const int MAX = 20;
void getNumbers(double numbersArray[MAX]);//function for getting the user to input 20 numbers
void sorting(double numbersArray[MAX]);//function that sorts the array
void index_of_smallest_and_largest(double numbersArray[MAX]);//funtion for finding the largest number 
void average(double numbersArray[MAX]);//function for calculating the average
void median(double numbersArray[MAX]);//function for finding the median 

int main()
{
    double numbersArray[MAX];

    getNumbers(numbersArray);
    sorting(numbersArray);
    index_of_smallest_and_largest(numbersArray);
    average(numbersArray);
    median(numbersArray);
    
    cout << endl;
    system ("pause");
    return 0;
}

void getNumbers(double numbersArray[MAX])//function for getting the user to input 20 numbers
{
    int i;
    cout << "Enter " << MAX << " numbers." << endl;
    for (int i = 0; i < MAX; i++)
    {
        cout << "What is your number? ";
        cin >> numbersArray[i];
    }
    cout << "Unsorted numbers: ";
    for (int i = 0; i < MAX; i++)
    {
        cout << numbersArray[i] << " ";
    }
    cout << endl;
}

void sorting(double numbersArray[MAX])
{
    int temp;
    for (int i = 0; i < MAX; i++)
    {
        for (int j = i + 1; j < MAX; j++)
        {
            if (numbersArray[i] > numbersArray[j])
            {
                temp = numbersArray[i];
                numbersArray[i] = numbersArray[j];
                numbersArray[j] = temp;
            }
        }
    }
    cout << "Sorted numbers: ";
    for (int i = 0; i < MAX; i++)
    {
        cout << numbersArray[i] << " ";
    }
    cout << endl;
}

void index_of_smallest_and_largest(double numbersArray[MAX])//function for finding the smallest and largest
{
    int largest = numbersArray[0];
    int smallest = numbersArray[0];
    int i;
    for (int i = 0; i < MAX; i++)
    {
        if (smallest > numbersArray[i])
        {
            smallest = numbersArray[i];
        }
        else if (largest < numbersArray[i])
        {
            largest = numbersArray[i];
        }
    }
    cout << "The smallest number is: " << smallest << endl;
    cout << "The largest number is: " << largest << endl;
}

void average(double numbersArray[MAX])//function for calculating the average
{
    double total = 0;
    for (int i = 0; i < MAX; i++)
    {
        total = total + numbersArray[i];
    }
    cout << "Average is: " << total / 20 << endl;
}

void median(double numbersArray[MAX])
{
    double middle;
    middle = numbersArray [MAX/2] - 1;
    cout << "Your median is: " << middle << endl;
}

