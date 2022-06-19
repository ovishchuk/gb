/*
    gb/lesson_6/task1.cpp

    Выделить в памяти динамический одномерный массив типа int. Размер массива
    запросить у пользователя. Инициализировать его числами степенями двойки: 
    1, 2, 4, 8, 16, 32, 64, 128 ... Вывести массив на экран. Не забыть 
    освободить память. =) Разбить программу на функции.
*/
#include <iostream>

// возвращаем динамический массив длины SIZE
int * createIntArray(const size_t SIZE)
{
    // размер не может быть 0
    if ( SIZE > 0 )
    {
        return new int[SIZE]{};
    }

    // если SIZE <= 0 
    return nullptr;
}

// узнаем у поользователя длину массива и возвращаем ее
size_t askArraySize()
{   
    // size_t бросает исключение при отрицательном вводе и программа прерывается
    // int это исправляет (другого способа пока не знаю)
    int size = 0;
    
    // длина не может быть < 1
    while ( size < 1 )
    {
        std::cout << "Введите длину массива: ";
        std::cin >> size;

        // если длина меньше 1, сообщаем пользователю
        if ( size < 1 )
        {
            std::cout << "Длина массива должна быть больше ноля." << std::endl;
        }
    }

    return (size_t)size;
}

void cleanArray(int * array)
{
    delete [] array;
    array = nullptr;
}

void initArrayByMultTwo(int * arr, size_t SIZE)
{
    unsigned int value = 1;

    for ( size_t i = 0; i < SIZE; i++ )
    {
        arr[i] = value;
        value *= 2;
    }
}

template <typename ArrT>
void printNumArray(ArrT * arr, const size_t SIZE)
{
    std::cout << "Ваш массив: " << std::endl;

    for (size_t i = 0; i < SIZE; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    const size_t ARR_SIZE = askArraySize();

    int * array = createIntArray(ARR_SIZE);

    if ( array != nullptr )
    {
        initArrayByMultTwo(array, ARR_SIZE);
        printNumArray(array, ARR_SIZE);
        cleanArray(array);
    }

    return 0;
}