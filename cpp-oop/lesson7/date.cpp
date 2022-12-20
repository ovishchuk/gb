/*
    @file date.cpp
    @author Oleksandr Ishchuk <o.v.ishchuk@gmail.com>
*/

/*
    1. Создайте класс Date с полями день, месяц, год и методами доступа к этим 
    полям. Перегрузите оператор вывода для данного класса. Создайте два "умных" 
    указателя today и date. Первому присвойте значение сегодняшней даты. Для 
    него вызовите по отдельности методы доступа к полям класса Date, а также 
    выведите на экран данные всего объекта с помощью перегруженного оператора 
    вывода. Затем переместите ресурс, которым владеет указатель today в 
    указатель date. Проверьте, являются ли нулевыми указатели today и date и 
    выведите соответствующую информацию об этом в консоль.
*/

/*
    2. По условию предыдущей задачи создайте два умных указателя date1 и date2.
    • Создайте функцию, которая принимает в качестве параметра два умных 
      указателя типа Date и сравнивает их между собой (сравнение происходит по 
      датам). Функция должна вернуть более позднюю дату.
    • Создайте функцию, которая обменивает ресурсами (датами) два умных 
      указателя, переданных в функцию в качестве параметров.

    Примечание: обратите внимание, что первая функция не должна уничтожать 
    объекты, переданные ей в качестве параметров.
*/
#include <iostream>
#include <memory>

class Date
{
private:
    int m_day;
    int m_month;
    int m_year;
public:
    Date() : m_day(1), m_month(1), m_year(1900) {}
    Date(int day, int month, int year)
        : m_day(day), m_month(month), m_year(year)
    {
    }
    ~Date() {}
    int Day() const { return m_day; }
    int Month() const { return m_month; }
    int Year() const { return m_year; }
    void Set(int day, int month, int year)
    {
        m_day = day;
        m_month = month;
        m_year = year;
    }
    friend std::ostream& operator<<(std::ostream& out, Date& date);
};

std::ostream& operator<<(std::ostream& out, Date& date)
{
    return out << date.m_day << "." << date.m_month << "." << date.m_year;
}

// 2.1
Date& Later(const std::unique_ptr<Date>& date1, const std::unique_ptr<Date>& date2)
{
    if ( date1.get()->Year() == date2.get()->Year() )
    {
        if ( date1.get()->Month() == date2.get()->Month() )
        {
            if ( date1.get()->Day() == date2.get()->Day() ) return *date1;
            else
            {
                if ( date1.get()->Day() > date2.get()->Day() ) return *date1;
                else return *date2;
            }

        }
        else
        {
            if ( date1.get()->Month() > date2.get()->Month() ) return *date1;
            else return *date2;
        }
    }
    else
    {
        if ( date1.get()->Year() > date2.get()->Year() ) return *date1;
        else return *date2;
    }
}

// 2.2
template<typename T>
void SwapPtrs(std::unique_ptr<T>& pA, std::unique_ptr<T>& pB)
{
    /*
    // с ипользованием библиотечной функции
    pA.swap(pB);
    */

    // велосипед :-)
    // сохраняем данные
    T* tmpPtrA = pA.get();
    T* tmpPtrB = pB.get();
    // освобождаем указатели, во избежание вызова делитера на них
    pA.release();
    pB.release();
    // размещаем данные
    pA.reset(tmpPtrB);
    pB.reset(tmpPtrA);
}

int main()
{
    // 1.
    std::unique_ptr<Date> today(new Date);
    std::unique_ptr<Date> date;

    today.get()->Set(13, 12, 2022);
    std::cout << "Day: " << today.get()->Day() <<
                ", Month: " << today.get()->Month() <<
                ", Year: " << today.get()->Year() << std::endl <<
                "Date: " << *today.get() << std::endl;
    today.swap(date);

    if ( !today ) std::cout << "today is nullptr" << std::endl;
    else std::cout << "today: " << today.get() << std::endl;

    if ( !date ) std::cout << "date is nullptr" << std::endl;
    else std::cout << "date: " << date.get() << std::endl;

    // 2.1
    std::unique_ptr<Date> date1(new Date(3, 10, 2019));
    std::unique_ptr<Date> date2(new Date(5, 5, 2022));

    std::cout << "Later date is: " << Later(date1, date2) << "\n" <<
        *date1 << "\n" <<
        *date2 << std::endl;

    // 2.2
    std::unique_ptr<Date> pA(new Date(1, 1, 1111));
    std::unique_ptr<Date> pB(new Date(2, 2, 2222));
    std::cout << "Before swap: " << *pA << " <-> " << *pB << std::endl;
    SwapPtrs(pA, pB);
    std::cout << "After swap: " << *pA << " <-> " << *pB << std::endl;
    
    return 0;
}