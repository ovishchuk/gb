/*
    gb/lesson_7/main.cpp
*/
#include "mylib.hpp"
#include <iostream>
#include <fstream>
// задание 2
#define inrange(num, range) ( num >= 0 && num < range ? true : false )
// задание 3
#define INT_ARR_SIZE 10
#define SwapINT(a, b) ( {   \
    int tmp = a;       \
    a = b;                  \
    b = tmp;                \
} )

void sortIntArray(int *array, const size_t SIZE)
{
    bool swap;

    do 
    {
        swap = false;

        for ( size_t i = 0; i < SIZE - 1; i++ )
        {
            if ( array[i] > array[i + 1] )
            {
                SwapINT(array[i], array[i + 1]);
                swap = true;
            }
        }
    } 
    while ( swap );
}

// служебная функция
void printIntArray(int *array, const size_t SIZE)
{
    for ( size_t i = 0; i < SIZE; i++ )
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

// задание 4
#pragma pack(push, 1)
struct Emploee
{
    std::string firstName = "null";
    std::string lastName  = "null";
    std::string occupation = "null";
    unsigned int age = 0;
    double salary = 0.0;
};
#pragma pack(pop)

int main()
{
    // задания 1 и 5
    std::cout << "-=== Задания 1 и 5 ===-" << std::endl;
    const size_t FLOAT_ARR_SIZE = 10;
    float myFloatArray[FLOAT_ARR_SIZE];

    MyFloatLib::initArrayRand(myFloatArray, FLOAT_ARR_SIZE);
    MyFloatLib::printArray(myFloatArray, FLOAT_ARR_SIZE);
    MyFloatLib::countPositiveAndNegative(myFloatArray, FLOAT_ARR_SIZE);

    // задание 2
    std::cout << "\n-== Задание 2 ==-" << std::endl;
    unsigned int number = 0;
    unsigned int rangeMaxOut = 2000;
    std::cout << "Введите число: ";
    std::cin >> number;
    
    if ( inrange(number, rangeMaxOut) )
    {
        std::cout << "true" << std::endl;
    }
    else
    {
        std::cout << "false" << std::endl;
    }

    // задание 3
    std::cout << "\n-== Задание 3 ==-" << std::endl;
    int intArray[INT_ARR_SIZE];
    std::cout << INT_ARR_SIZE << " элементов." << std::endl;
    int numInt;

    for ( size_t i = 0; i < INT_ARR_SIZE; i++ )
    {    
        std::cout << "Введите целое число: ";
        std::cin >> numInt;
        intArray[i] = numInt;
    }

    printIntArray(intArray, INT_ARR_SIZE);
    sortIntArray(intArray, INT_ARR_SIZE);
    printIntArray(intArray, INT_ARR_SIZE);

    // задание 4
    std::cout << "-== Задание 4 ==-" << std::endl;

    Emploee emploee
    {
        "Gordon",
        "Freeman",
        "engineer",
        32,
        2500.00
    };

    std::cout << "Имя:\t" << emploee.firstName
        << "\nФамилия:\t" << emploee.lastName
        << "\nДолжность:\t" << emploee.occupation
        << "\nВозраст:\t" << emploee.age
        << "\nЗарплата:\t" << emploee.salary << std::endl;
    std::cout << "Размер структуры: " << sizeof(Emploee) << std::endl;

    std::ofstream file("Emploee.txt");
    std::string structText(
"#pragma pack(push, 1)\n\
struct Emploee\n\
{\n\
    std::string firstName = \"null\";\n\
    std::string lastName  = \"null\";\n\
    std::string occupation = \"null\";\n\
    unsigned int age = 0;\n\
    double salary = 0.0;\n\
};\n\
#pragma pack(pop)");

    file << structText;

    return 0;
}