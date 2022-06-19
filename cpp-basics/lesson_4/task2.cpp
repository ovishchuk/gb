/*
    task2.cpp

    Написать программу, выводящую на экран строку “true”, если две целочисленные
    константы, объявленные в её начале либо обе равны десяти сами по себе, либо 
    их сумма равна десяти. Иначе "false".
*/
#include <iostream>

int main()
{
    const int NUM_1 = 3;
    const int NUM_2 = 10;

    if ( (NUM_1 == 10 && NUM_2 == 10) || (NUM_1 + NUM_2 == 10) )
    {
        std::cout << "true" << std::endl;
    }
    else
    {
        std::cout << "false" << std::endl;
    }

    return 0;
}