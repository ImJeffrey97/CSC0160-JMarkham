//Section CSC160 - Computer Science I: C++
//File Name: p7_2.cpp
//Student: Jeffrey Markham
//Homework Number: Lab 7
//Description: This program computes donuts per glasses of milk
//Last Changed: 04/27/2021

#include <iostream>
using namespace std;

class NoMilk
{
    public:
        NoMilk();
        NoMilk(int how_many);
        int get_donuts();
    private:
        int count;
};

int main()
{
    int donuts, milk;
    double dpg;

    try
    {
        cout << "Enter number of donuts:\n";
        cin >> donuts;
        cout << "Enter number of glasses of milk:\n";
        cin >> milk;

        if(milk <= 0)
        {
            throw NoMilk(donuts);

            dpg = donuts/double(milk);
            cout << donuts << " donuts.\n"
                 << milk << " glasses of milk.\n"
                 << "You have " << dpg
                 << " donuts for each glass of milk.\n";
        }
    }

    catch(NoMilk e)
    {
        cout << e.get_donuts() << "donuts, and No milk!\n"
             << "Go buy some milk.\n";
    }

    cout << "End of program.";

    cout << endl;
    system ("pause");
    return 0;
}

NoMilk::NoMilk()
{}
NoMilk::NoMilk(int how_many): count(how_many)
{}

int NoMilk::get_donuts()
{
    return count;
}