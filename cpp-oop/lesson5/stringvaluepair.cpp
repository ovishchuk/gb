/*
3. Написать шаблон класса StringValuePair, в котором первое значение всегда типа
string, а второе — любого типа. Этот шаблон класса должен наследовать частично 
специализированный класс Pair, в котором первый параметр — string, а второй — 
любого типа данных.

Следующий код:

int main()
{
StringValuePair<int> svp("Amazing", 7);
std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';
return 0;
}

… должен производить следующий результат:
Pair: Amazing 7

Подсказка: при вызове конструктора класса Pair из конструктора класса 
StringValuePair не забудьте указать, что параметры относятся к классу Pair.
*/
#include <iostream>
#include <string>

template<typename T>
class Pair
{
protected:
    std::string m_first;
    T m_second;
public: 
    Pair<T>(std::string first, T second)
        : m_first(first), m_second(second) {}
    virtual ~Pair() {}
    std::string first() { return m_first; }
    T second() { return m_second; }
};

template<typename T>
class StringValuePair : public Pair<T>
{
public:
    StringValuePair<T>(std::string first, T second)
        : Pair<T>(first, second) {}
};

int main()
{
    StringValuePair<int> svp("Amazing", 7);
    std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';
    return 0;
}