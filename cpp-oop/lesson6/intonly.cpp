/*
    @file intonly.cpp
    @author Oleksandr Ishchuk <o.v.ishchuk@gmail.com>
*/

/*
  1. Создать программу, которая считывает целое число типа int. И поставить 
  «защиту от дурака»: если пользователь вводит что-то кроме одного 
  целочисленного значения, нужно вывести сообщение об ошибке и предложить ввести
  число еще раз. Пример неправильных введенных строк:

  rbtrb
  nj34njkn
  1n
*/
#include <iostream>
#include <string>
#include <sstream>

bool IsNum(const std::string& str)
{
    for ( size_t i = 0; i < str.length(); i++ )
    {
        if ( !isdigit(str[i]) )
        {
            std::cout << "Not a Number." << std::endl;
            return false;
        }
    }

    return true;
}

int main()
{
    std::string str;
    bool success = false;

    // repeat if not a number; success exit if number.
    do
    {
        std::cout << "Enter number: ";
        std::getline(std::cin, str);
    }
    while ( !IsNum(str) );

    return 0;
}
