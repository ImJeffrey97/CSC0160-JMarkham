//Section CSC160 - Computer Science I: C++
//File Name: P4_2b
//Student: Jeffrey Markham
//Homework Number: P4_2b
//Description: An example for partially filled array
//Last Changed: 03/03/2021

#include <iostream>
#include <ctype.h>
using namespace std;

const int MAXSIZE = 20;

int main(void)
{
    char digit_array[MAXSIZE], digit;
    int size, i;

    size = 0;
    cout << "Enter an integer with no more than 20 digits: ";
    do
    {
        cin.get(digit);
        if (isdigit(digit))
        {
            digit_array[size] = digit;
            ++size;
        }
    } while (size < 20 && isdigit(digit));
    
    cout << "The integer you entered is: ";
    for (i = 0; i < size; ++i)
    {
        cout << digit_array[i];
    }
    cout << endl;
    
    cout << endl;
    system ("pause");
    return 0;
}