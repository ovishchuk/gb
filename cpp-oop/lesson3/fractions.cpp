/*
  3. Создать класс: Fraction (дробь). Дробь имеет числитель и знаменатель 
  (например, 3/7 или 9/2). Предусмотреть, чтобы знаменатель не был равен 0. 
  Перегрузить:

  математические бинарные операторы (+, -, *, /) для выполнения действий с 
  дробями
  унарный оператор (-)
  логические операторы сравнения двух дробей (==, !=, <, >, <=, >=).

  Примечание: Поскольку операторы < и >=, > и <= — это логические 
  противоположности, попробуйте перегрузить один через другой.

  Продемонстрировать использование перегруженных операторов.
*/
#include <iostream>
#include <string>
#include "mymath.hpp"

class Fraction
{
private:
    int m_numerator;      // числитель
    int m_denominator;    // знаменатель
public:
    Fraction(int numerator, int denominator)
        : m_numerator(numerator), m_denominator(denominator)
    {
        if ( m_denominator == 0 )
        {
            std::cout << "WARNING: denominator is 0. Setting to 1." << std::endl;
            m_denominator = 1;
        }
    }
    int getNumerator() { return m_numerator; }
    int getDenominator() { return m_denominator; }
    std::string StrValue() 
    {
        if ( m_numerator == m_denominator ) { return "1";}
        else if ( m_numerator == -1 && m_denominator == 1 ) { return "-1"; }
        else { return std::to_string(m_numerator) + "/" + std::to_string(m_denominator); }
    }
    
    Fraction operator+(const Fraction& right)
    {
        // общий знаменатель
        int commonDenom = MyMath::lcm(m_denominator, right.m_denominator);
        // итоговый числитель
        int resultNum = (m_numerator * ( commonDenom / m_denominator )) +
            (right.m_numerator * ( commonDenom / right.m_denominator ));
        // сокращаем итоговую дробь
        MyMath::fractionReduce(resultNum, commonDenom);

        return Fraction(resultNum, commonDenom);
    }

    Fraction operator-(const Fraction& right)
    {
        // общий знаменатель
        int commonDenom = MyMath::lcm(m_denominator, right.m_denominator);
        // итоговый числитель
        int resultNum = (m_numerator * ( commonDenom / m_denominator )) -
            (right.m_numerator * ( commonDenom / right.m_denominator ));
        // сокращаем итоговую дробь
        MyMath::fractionReduce(resultNum, commonDenom);
        return Fraction(resultNum, commonDenom);
    }

    Fraction operator*(const Fraction& right)
    {
        int resultNum = m_numerator * right.m_numerator;
        int resultDenom = m_denominator * right.m_denominator;
        MyMath::fractionReduce(resultNum, resultDenom);
        return Fraction(resultNum, resultDenom);
    }
    Fraction operator*(const int& right)
    {
        int resultNum = m_numerator * right;
        int resultDenom = m_denominator;
        MyMath::fractionReduce(resultNum, resultDenom);
        return Fraction(resultNum, resultDenom);
    }

    Fraction operator/(const Fraction& right)
    {
        int resultNum = m_numerator * right.m_denominator;
        int resultDenom = m_denominator * right.m_numerator;
        MyMath::fractionReduce(resultNum, resultDenom);
        return Fraction(resultNum, resultDenom);
    }
    Fraction operator/(const int& right)
    {
        int resultNum = m_numerator;
        int resultDenom = m_denominator * right;
        MyMath::fractionReduce(resultNum, resultDenom);
        return Fraction(resultNum, resultDenom);
    }

    // unary
    Fraction operator-()
    {
        int resultNum = -m_numerator;
        int resultDenom = m_denominator;
        return Fraction(resultNum, resultDenom);
    }

    // equality operators
    bool operator==(const Fraction& right)
    {
        int commonDenom = MyMath::lcm(m_denominator, right.m_denominator);
        int numeratorL = m_numerator * (commonDenom / m_denominator);
        int numeratorR = right.m_numerator * (commonDenom / right.m_denominator);
        if ( numeratorL == numeratorR ) { return true; }
        else { return false; }
    }
    bool operator!=(const Fraction& right)
    {
        int commonDenom = MyMath::lcm(m_denominator, right.m_denominator);
        int numeratorL = m_numerator * (commonDenom / m_denominator);
        int numeratorR = right.m_numerator * (commonDenom / right.m_denominator);
        if ( numeratorL != numeratorR ) { return true; }
        else { return false; }
    }

    bool operator>(const Fraction& right)
    {
        int commonDenom = MyMath::lcm(m_denominator, right.m_denominator);
        int numeratorL = m_numerator * (commonDenom / m_denominator);
        int numeratorR = right.m_numerator * (commonDenom / right.m_denominator);
        if ( numeratorL > numeratorR ) { return true; }
        else { return false; }
    }
    bool operator<(const Fraction& right)
    {
        if ( *this > right ) { return false; }
        else { return true; }
    }
    bool operator>=(const Fraction& right)
    {
        int commonDenom = MyMath::lcm(m_denominator, right.m_denominator);
        int numeratorL = m_numerator * (commonDenom / m_denominator);
        int numeratorR = right.m_numerator * (commonDenom / right.m_denominator);
        if ( numeratorL >= numeratorR ) { return true; }
        else { return false; }
    }
    bool operator<=(const Fraction& right)
    {
        if ( *this > right ) { return false; }
        else { return true; }
    }
};

int main()
{
    // operator+
    Fraction frAdd1(3, 4);
    Fraction frAdd2(2, 15);
    Fraction frAdd3 = frAdd1 + frAdd2;
    std::cout << "operator+:" << std::endl;
    std::cout << frAdd1.StrValue() << " + " << frAdd2.StrValue() << " = " << frAdd3.StrValue() << std::endl;
 
    // operator-
    Fraction frSub1(-2, 4);
    Fraction frSub2(2, 8);
    Fraction frSub3 = frSub1 - frSub2;
    std::cout << "\noperator-:" << std::endl;
    std::cout << frSub1.StrValue() << " - " << frSub2.StrValue() << " = " << frSub3.StrValue() << std::endl;

    // operator*
    Fraction frMul1(3, 4);
    Fraction frMul2(2, 5);
    Fraction frMul3 = frMul1 * frMul2;
    std::cout << "\noperator*:" << std::endl;
    std::cout << frMul1.StrValue() << " * " << frMul2.StrValue() << " = " << frMul3.StrValue() << std::endl;
    frMul3 = frMul1 * 3;
    std::cout << frMul1.StrValue() << " * " << "3" << " = " << frMul3.StrValue() << std::endl;

    // operator/
    Fraction frDev1(3, 7);
    Fraction frDev2(4, 5);
    Fraction frDev3 = frDev1 / frDev2;
    std::cout << "\noperator/:" << std::endl;
    std::cout << frDev1.StrValue() << " / " << frDev2.StrValue() << " = " << frDev3.StrValue() << std::endl;
    frDev3 = frDev1 / 3;
    std::cout << frDev1.StrValue() << " / " << "3" << " = " << frDev3.StrValue() << std::endl;

    // unary operator-
    Fraction frSubUn(4, 5);
    std::cout << "\nunary operator-:" << std::endl;
    std::cout << frSubUn.StrValue() << " <=> "; 
    frSubUn = -frSubUn;
    std::cout << frSubUn.StrValue() << std::endl;

    // operator==
    Fraction frEqual1(1, 4);
    Fraction frEqual2(1, 2);
    Fraction frEqual3 = frEqual1;
    std::cout << "\noperator==:" << std::endl;
    if ( frEqual1 == frEqual2 ) { std::cout << "Something wrong" << std::endl; }
    else { std::cout << frEqual1.StrValue() << " != " << frEqual2.StrValue() << std::endl; }
    if ( frEqual1 == frEqual3 ) { std::cout << frEqual1.StrValue() << " == " << frEqual3.StrValue() << std::endl; }
    else { std::cout << "Something wrong" << std::endl; }

    // operator!=
    Fraction frNEqual1(1, 4);
    Fraction frNEqual2(1, 2);
    Fraction frNEqual3 = frNEqual1;
    std::cout << "\noperator!=:" << std::endl;
    if ( frNEqual1 != frNEqual3 ) { std::cout << "Something wrong" << std::endl; }
    else { std::cout << frNEqual1.StrValue() << " == " << frNEqual3.StrValue() << std::endl; }
    if ( frNEqual1 != frNEqual2 ) { std::cout << frNEqual1.StrValue() << " != " << frNEqual2.StrValue() << std::endl; }
    else { std::cout << "Something wrong" << std::endl; }

    // operator> operator<
    Fraction frGreater1(2, 3);
    Fraction frGreater2(1, 3);
    std::cout << "\noperator> & operator<:" << std::endl;
    if ( frGreater1 > frGreater2 ) 
    { std::cout << frGreater1.StrValue() << " > " << frGreater2.StrValue() << std::endl; }
    if ( frGreater2 < frGreater1 ) 
    { std::cout << frGreater2.StrValue() << " < " << frGreater1.StrValue() << std::endl; }
    //operator>=
    std::cout << "\noperator>=:" <<std::endl;
    if ( frGreater1 >= frGreater2 )
    { std::cout << frGreater1.StrValue() << " >= " << frGreater2.StrValue() << std::endl; }
    //operator>=
    std::cout << "\noperator<=:" <<std::endl;
    if ( frGreater2 <= frGreater1 )
    { std::cout << frGreater2.StrValue() << " <= " << frGreater1.StrValue() << std::endl; }
    return 0;
}