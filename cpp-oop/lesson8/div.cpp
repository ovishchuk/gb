/*
    1. Написать шаблонную функцию div, которая должна вычислять результат 
    деления двух параметров и запускать исключение DivisionByZero, если второй 
    параметр равен 0. В функции main выводить результат вызова функции div в 
    консоль, а также ловить исключения.
*/
#include <iostream>
#include <exception>

class DivisionByZero
{
public:
    void getError()
    {
        std::cerr << "Division by zero is not alloved." << std::endl;
    }
};

template <typename T>
int div(const T& a, const T& b)
{
    if ( *b == 0 ) throw DivisionByZero();
    return *a / *b;
}

int main()
{
    int a, b;
    std::cout << "a: ";
    std::cin >> a;
    std::cout << "b: ";
    std::cin >> b;

    try
    {
        std::cout << "Result: " << div(&a, &b) << std::endl;
    }
    catch (DivisionByZero& exception)
    {
        exception.getError();
    }

    return 0;
}