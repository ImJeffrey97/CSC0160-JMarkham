//Section CSC160 - Computer Science I: C++
//File Name: P62.cpp
//Student: Jeffrey Markham
//Homework Number: Lab 6
//Description: Reads some integers from a file and displays: the
//number, number^2, and the sume of all numbers read up to that point.
//Last Changed: 04/16/2021

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
using namespace std;

void get_stream(ifstream& in_s);


int main()
{
    int x, count = 0;
    float sum = 0, avg;

    ifstream in_s;
    

    get_stream(in_s);
    

    cout << "\t x \t\t x^2 \t\t Current Sum \n";
    cout << "\t === \t\t === \t\t ============= \n";

    while(in_s >> x)
    {
        sum = sum + x;
        cout << "\t" << x << pow(x,2) << "\t\t" << sum << "\n";
        count++;
    }

    avg = sum / count;
    cout << "\n \t\t The average of these" << count << "number is: " << avg << endl;

    in_s.close();
    

    return 0;
}

void get_stream(ifstream& in_s)
{
    char input_file[15];
    cout << "Please input the input file name \n";
    cin >> input_file;

    in_s.open(input_file);
    if(in_s.fail())
    {
        cout << "Input file opening failed. \n";
        exit(1);
    }
}
