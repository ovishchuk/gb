/*
    gb/lesson_7/mylib.cpp
*/
#include "mylib.hpp"
#include <random>
#include <iostream>

// задание 5 (+ 1)
namespace MyFloatLib
{

void initArrayRand(float *array, const size_t SIZE)
{
    srand(time(NULL));

    const float randLo = -2000.0f;
    const float randHi = 2000.0f;

    for ( size_t i = 0; i < SIZE; i++ )
    {
        array[i] = randLo + static_cast<float> (rand()) / (static_cast<float> (RAND_MAX / (randHi - randLo)));
    }
}

void printArray(const float *array, const size_t SIZE)
{
    for ( size_t i = 0; i < SIZE; i++ )
    {
        std::cout << array[i] << " ";
    }

    std::cout << std::endl;
}

void countPositiveAndNegative(float *array, const size_t SIZE)
{
    unsigned positive = 0;
    unsigned negative = 0;

    for ( size_t i = 0; i < SIZE; i++ )
    {
        if ( array[i] > 0 )
        {
            positive++;
        }
        else
        {
            negative++;
        }
    }

    std::cout << positive << " positives\n"
            << negative << " negatives" << std::endl;
}

} // namespace MyFloatLib