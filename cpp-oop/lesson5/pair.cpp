/*
  2. Реализовать класс Pair, который позволяет использовать разные типы данных в
  передаваемых парах.

  Следующий код:

int main()
{
Pair<int, double> p1(6, 7.8);
cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

const Pair<double, int> p2(3.4, 5);
cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

return 0;

}

  … должен производить следующий результат:
  Pair: 6 7.8
  Pair: 3.4 5

  Подсказка: чтобы определить шаблон с использованием двух разных типов, просто 
  разделите параметры типа шаблона запятой.
*/
#include <iostream>

template<typename T1, typename T2>
class Pair
{
private:
    T1 m_first;
    T2 m_second;
public:
    Pair(T1 first, T2 second) : m_first(first), m_second(second) {}
    T1 first() const
    {
        return m_first;
    }
    T2 second() const
    {
        return m_second;
    }
};

int main()
{
    Pair<int, double> p1(6, 7.8);
    std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

    const Pair<double, int> p2(3.4, 5);
    std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

    return 0;
}