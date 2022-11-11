#include <iostream>
#include <math.h>
#include <cstdint>

/*
  1. Создать класс Power, который содержит два вещественных числа. Этот класс 
  должен иметь две переменные-члена для хранения этих вещественных чисел. Еще 
  создать два метода: один с именем set, который позволит присваивать значения 
  объявленным в классе переменным, второй — calculate, который будет выводить 
  результат возведения первого числа в степень второго числа. Задать значения 
  этих двух чисел по умолчанию.
*/

class Power
{
private:
    int m_na;
    int m_nb;
public:
    Power()
    {
        m_na = 0;
        m_nb = 0;
    }

    void set(int a, int b)
    {
        m_na = a;
        m_nb = b;
    }

    void calculate()
    {
        int result = pow(m_na, m_nb);
        std::cout << result << std::endl;
    }
};

/*
  2. Написать класс с именем RGBA, который содержит 4 переменные-члена типа 
  std::uint8_t: m_red, m_green, m_blue и m_alpha (#include cstdint для доступа к 
  этому типу). Задать 0 в качестве значения по умолчанию для m_red, m_green, 
  m_blue и 255 для m_alpha. Создать конструктор со списком инициализации членов, 
  который позволит пользователю передавать значения для m_red, m_blue, m_green и 
  m_alpha. Написать функцию print(), которая будет выводить значения 
  переменных-членов.
*/

class RGBA
{
private:
    uint8_t m_red;
    uint8_t m_green;
    uint8_t m_blue;
    uint8_t m_alpha;
public:
    RGBA()
    {
        m_red = 0;
        m_green = 0;
        m_blue = 0;
        m_alpha = 255;
    }

    RGBA(std::uint8_t red, std::uint8_t green, std::uint8_t blue, std::uint8_t alpha)
        : m_red(red), m_green(green), m_blue(blue), m_alpha(alpha)
    {
    }

    void print()
    {
        std::cout << "red: " << +m_red
            << "\ngreen: " << +m_green
            << "\nblue: " << +m_blue
            << "\nalpha: " << +m_alpha << std::endl;
    }
};

/*
  3. Написать класс, который реализует функциональность стека. Класс Stack должен 
  иметь:

  • private-массив целых чисел длиной 10;

  • private целочисленное значение для отслеживания длины стека;

  • public-метод с именем reset(), который будет сбрасывать длину и все значения 
    элементов на 0;

  • public-метод с именем push(), который будет добавлять значение в стек. 
    push() должен возвращать значение false, если массив уже заполнен, и true в 
    противном случае;

  • public-метод с именем pop() для вытягивания и возврата значения из стека. 
    Если в стеке нет значений, то должно выводиться предупреждение;

  • public-метод с именем print(), который будет выводить все значения стека.

Код main():

int main()
{
Stack stack;
stack.reset();
stack.print();

stack.push(3);
stack.push(7);
stack.push(5);
stack.print();

stack.pop();
stack.print();

stack.pop();
stack.pop();
stack.print();

return 0;

}

  Этот код должен выводить:
  ( )
  ( 3 7 5 )
  ( 3 7 )
  ( )

*/

class Stack
{
private:
    int m_array[10]{0};
    size_t m_length;
public:
    Stack() : m_length(0)
    {
    }

    void reset()
    {
        for ( size_t i = 0; i < m_length; i++ )
        {
            m_array[i] = 0;
        }

        m_length = 0;
    }

    bool push(int number)
    {
        if ( m_length == 10 )
        {
            return false;
        }
        else
        {
            m_array[m_length] = number;
            m_length++;
            return true;
        }
    }

    int pop()
    {
        int number = 0;

        if ( m_length == 0 )
        {
            std::cout << "stack is empty!" << std::endl;
        }
        else
        {
            m_length--;
            number = m_array[m_length];
            m_array[m_length] = 0;
        }

        return number;
    }

    void print()
    {
        std::cout << "( ";
        
        for ( size_t i = 0; i < m_length; i++ )
        {
            std::cout << m_array[i] << " ";
        }

        std::cout << ")" << std::endl;
    }
};

int main()
{
    Stack stack;
    stack.reset();
    stack.print();

    stack.push(3);
    stack.push(7);
    stack.push(5);
    stack.print();

    stack.pop();
    stack.print();

    stack.pop();
    stack.pop();
    stack.print();

    return 0;
}