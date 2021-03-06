/*
    task5.cpp

    Со звёздочкой. Пользователь вводит с клавиатуры число (год): от 1 до 3000. 
    Написать программу, которая определяет является ли этот год високосным. 
    Каждый 4-й год является високосным, кроме каждого 100-го, при этом каждый 
    400-й – високосный. Вывести результаты работы программы в консоль.
*/
#include <iostream>

// проверяем высокосность
bool isLeap(size_t year)
{
    // если (год не кратен 4) или (кратен 100 но не кратен 400), он невысокосный
    return !( (year % 4) || (!(year % 100) && (year % 400)) );
}

int main()
{
    // для проверяемых годов
    size_t year = 0;

    // проверим года 10 раз
    for ( size_t i = 0; i < 10; i++ )
    {
        std::cout << i + 1 << " >> Enter year between 1 and 3000: ";
        std::cin >> year;

        // проверяем, чтобы год был 1-3000
        if ( year >= 1 && year <= 3000 )
        {
            if ( isLeap(year) )
            {
                // высокосный
                std::cout << "Year is leap." << std::endl;
            }
            else
            {
                // не высокосный
                std::cout << "Year is not leap." << std::endl;
            }
        }
        else
        {
            // год оказался вне разрешенного диапазона
            std::cout << "Year is out of allowed range." << std::endl;
            // сбрасываем счетчик
            i--;
        }
    }

    return 0;
}