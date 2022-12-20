/*
    @file endll.cpp
    @author Oleksandr Ishchuk <o.v.ishchuk@gmail.com>
*/

/*
  2. Создать собственный манипулятор endll для стандартного потока вывода, 
  который выводит два перевода строки и сбрасывает буфер.
*/
#include <iostream>
#include <sstream>

std::ostream& endll(std::ostream& out)
{
    // std::endl сбрасывает буфер
    return (out << "\n" << std::endl);
}

int main()
{
    std::cout << "Два перевода:" << endll << "Done" << std::endl;

    return 0;
}