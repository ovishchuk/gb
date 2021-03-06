/*
    task4.cpp

    Со звёздочкой. Написать программу, проверяющую, является ли некоторое число 
    простым. Простое число — это целое положительное число, которое делится без 
    остатка только на единицу и себя само.
*/
#include <iostream>

// проверяем, является ли число простым
bool isPrime(size_t num)
{
    // на 1 и само число проверять нет смысла, проверяем все остальные делители
    for ( size_t i = 2; i < num; i++ )
    {
        if ( num % i == 0 )
        {
            // проверяемое число делится на текущий делитель без остатка, 
            // дальше нет смысла проверять, число не простое 
            return false;
        }
    }

    // число прошло проверку, простое
    return true;
}

int main()
{
    // для проверяемых чисел
    int number = 0;

    // проверим числа 10 раз
    for ( size_t i = 0; i < 10; i++ )
    {
        std::cout << "Enter number: ";
        std::cin >> number;

        if ( isPrime(number) )
        {
            // простое
            std::cout << "Your number is prime." << std::endl;
        }
        else
        {
            // не простое
            std::cout << "Your number is not prime." << std::endl;
        }
    }

    return 0;
}