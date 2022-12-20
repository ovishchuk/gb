/*
    mymath.hpp
    helper header for fractions.cpp
*/

#ifndef GB_OOP_LESSON3_MYMATH_HPP
#define GB_OOP_LESSON3_MYMATH_HPP

namespace MyMath
{
// greatest common devisor
int gcd(int a, int b)
{
    //while ( a && b ) { a > b ? a  %= b : b %= a; }
    int tmp;

    while ( b )
    {
        tmp = b;
        b = a % b;
        a = tmp;
    }

    //return a + b;
    return a;
}

// lowest common mutiple
int lcm(int a, int b)
{
    return (a * b) / gcd(a, b);
}

// reduse fraction (modifies input data!)
bool fractionReduce(int& numerator, int& denominator)
{
    if ( numerator % MyMath::gcd(numerator, denominator) == 0 &&
        denominator % MyMath::gcd(numerator, denominator) == 0)
    {
        int _gcd = MyMath::gcd(numerator, denominator);
        numerator /= _gcd;
        denominator /= _gcd;
        return true;
    }
    return false;
}

} // namespace MyMath

#endif // GB_OOP_LESSON3_MYMATH_HPP