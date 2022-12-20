/*
    2. Написать класс Ex, хранящий вещественное число x и имеющий конструктор по
    вещественному числу, инициализирующий x значением параметра. Написать класс 
    Bar, хранящий вещественное число y (конструктор по умолчанию инициализирует 
    его нулем) и имеющий метод set с единственным вещественным параметром a. 
    Если y + a > 100, возбуждается исключение типа Ex с данными a*y, иначе в y 
    заносится значение a. В функции main завести переменную класса Bar и в цикле 
    в блоке try вводить с клавиатуры целое n. Использовать его в качестве 
    параметра метода set до тех пор, пока не будет введено 0. В обработчике 
    исключения выводить сообщение об ошибке, содержащее данные объекта 
    исключения.
*/
#include <iostream>

class Ex
{
private:
    int x;
public:
    Ex(const int& newX) : x(newX) 
    {
        throw x;
    }
    ~Ex() {}
};

class Bar
{
private:
    int y;
public:
    Bar() : y(0) {}
    ~Bar() {}
    void set(int a)
    {
        if ( y + a > 100 ) { throw Ex(a * y); }
        y = a;
        std::cout << "y = " << y << std::endl;
    }
};

int main()
{
    Bar bar;
    int n;

    try
    {
        do
        {
            std::cout << "Enter number: ";
            std::cin >> n;
            if ( n ) { bar.set(n); }
        }
        while ( n );
    }
    catch(const int& ex)
    {
        std::cerr << "y + number bigger than 100.\n" 
            << "y * number: " << ex << std::endl;
    }

    return 0;
}