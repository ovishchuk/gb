/*
    task1.cpp
    
    Написать программу, проверяющую что сумма двух (введенных с клавиатуры) 
    чисел лежит в пределах от 10 до 20 (включительно), если да – вывести 
    строку "true", в противном случае – "false";
*/
#include <iostream>

int main()
{
    int num1;
    int num2;

    std::cout << "Enter first number: ";
    std::cin >> num1;
    std::cout << "Enter second number: ";
    std::cin >> num2;

    if ( num1 + num2 >= 10 && num1 + num2 <= 20 )
    {
        std::cout << "true" << std::endl;
    }
    else
    {
        std::cout << "false" << std::endl;
    }

    return 0;
}