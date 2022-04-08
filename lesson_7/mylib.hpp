/*
    gb/lesson_7/mylib.hpp
*/
#ifndef GB_LESSON_SEVEN_MYLIB_HPP
#define GB_LESSON_SEVEN_MYLIB_HPP
#include <cstdlib>

// задание 5 (+ 1) 
namespace MyFloatLib
{

void initArrayRand(float *array, const size_t SIZE);
void printArray(const float *array, const size_t SIZE);
void countPositiveAndNegative(float *array, const size_t SIZE);

} // namespace MyFloatLib

#endif // GB_LESSON_SEVEN_MYLIB_HPP