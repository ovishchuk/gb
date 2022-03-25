/*
    task3.cpp

    Написать программу которая выводит на экран список всех нечетных чисел от 1 
    до 50. Например: "Your numbers: 1 3 5 7 9 11 13 …". Для решения используйте 
    любой С++ цикл.
*/
#include <iostream>

int main()
{
    std::cout << "Your numbers: " << std::endl;

    for ( size_t i = 1; i <= 50; i++)
    {
        if ( i % 2 == 1 )
        {
            std::cout << i << " ";
        }
    }

    std::cout << std::endl;

    return 0;
}