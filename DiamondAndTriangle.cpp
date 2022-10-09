//Section CSC160 - Computer Science I: C++
//File Name: ex5_10.cpp
//Student: Jeffrey Markham
//Homework Number: Lab 5
//Description: drawing a diamond or a triangle with user input
//Last Changed: 

#include <iostream>
using namespace std;

void instructions();//This function describes the program and how it works
int menu();//This function will return a choice to the main: 1) draw triangle, 2) draw diamond, and 3) quit
void draw_shape(int choice);//This function calls on appropriate function depending on the choice to draw a shape
int get_size();//This function will return the size of the shape, same function for either of the shapes
char get_char();//This function will ask the user to select a character that will be used to draw the shape
void draw_triangle(int size, char c);//This function draws a triangle of size using character c
void draw_diamond(int size, char c);//This function first calls draw_trianlge, then add_bottom to draw the diamond
void draw_bottom(int size, char c);//This function actually draws an upside down triangle of size size-l as the bottom diamond

int main()
{
    int choice;
    
    instructions();
    choice = menu();
    if(choice != 1 || choice != 2)
    {
        cout << "you requested to quit, bye \n";
        return 0;
    }

    draw_shape(choice);

    cout << endl;
    system ("pause");
    return 0;
}

void instructions()
{
    cout << "Enter either 1, 2, or 3. 1 is for triangle, 2 is for a diamond, and 3 is to quit";
    cout << endl;
}

int menu()
{
    int choice;
    cout << "Your choice is: ";
    cin >> choice;
    return choice;
}

void draw_shape(int choice)
{
    int size;
    char c;
    size = get_size();
    c = get_char();
    if (choice == 1)
    {
        draw_triangle(size, c);
    }
    else if (choice == 2)
    {
        draw_diamond(size, c);
    }
}

int get_size()
{
    int size;
    cout << "Enter size of the shape ";
    cin >> size;
    return size;
}

char get_char()
{
    char c;
    cout << "what character do you wnat to use? ";
    cin >> c;
    return c;
}

void draw_triangle(int size, char c)
{
    for (int a = 1; a < size; a ++)
    {
        for (int b = 1; b < a; b ++)
        {
            cout << c;
        }
        cout << endl;
    }
}

void draw_diamond(int size, char c)
{
    draw_triangle(size, c);
    draw_bottom(size, c);
}

void draw_bottom(int size, char c)
{
    for (int a = 1; a < size; a ++)
    {
        for (int b = 1; b < a; b++)
        {
            cout << c;
        }
        cout << endl;
    }
}