//Section CSC160 - Computer Science I: C++
//File Name: P4_2c
//Student: Jeffrey Markham
//Homework Number: P4_2c
//Description: An example for partially filled arrays
//Last Changed: 03/03/2021

#include <iostream>
#include <ctype.h>
using namespace std;

const int MAXSIZE = 20;
void read_array(char d_array[], int& size); //array will be modified
void write_array(const char d_array[], int size); //array will not be modified

int main(void)
{
    char digit_array[MAXSIZE];
    int size, i;

    size = 0;
    cout << "Enter an integer no more than 20 digits: ";
    read_array(digit_array, size);
    write_array(digit_array, size);

    cout << endl;
    system ("pause");
    return 0;
}

void read_array(char d_array[], int& size)
{
    char digit;
    do
    {
        cin.get(digit);
        if (isdigit(digit))
        {
            d_array[size] = digit;
            ++size;
        }
    } while (size < 20 && isdigit(digit));
}

void write_array(const char d_array[], int size)
{
    cout << "The integers you entered are: ";
    for (int i = 0; i < size; ++i)
    {
        cout << d_array[i];
    }
    cout << endl;
}