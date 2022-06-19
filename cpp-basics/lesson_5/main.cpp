/*
    main.cpp

    1. Написать функцию которая выводит массив double чисел на экран. Параметры 
    функции это сам массив и его размер. Вызвать эту функцию из main.

    Реализация (строка):    56
    Применение:             209

    2. Задать целочисленный массив, состоящий из элементов 0 и 1. Например: 
    [ 1, 1, 0, 0, 1, 0, 1, 1, 0, 0 ]. Написать функцию, заменяющую в принятом 
    массиве 0 на 1, 1 на 0. Выводить на экран массив до изменений и после.
    
    Реализация: 68
    Применение: 214

    3. Задать пустой целочисленный массив размером 8. Написать функцию, которая 
    с помощью цикла заполнит его значениями 1 4 7 10 13 16 19 22. Вывести массив
    на экран.

    Реализация: 96
    Применение: 219

    4. * Написать функцию, которой на вход подаётся одномерный массив и число n 
    (может быть положительным, или отрицательным), при этом метод должен 
    циклически сместить все элементы массива на n позиций.
    
    Реализация: 108
    Применение: 233

    5. ** Написать функцию, которой передается не пустой одномерный 
    целочисленный массив, она должна вернуть истину если в массиве есть место, в
    котором сумма левой и правой части массива равны. Примеры: 
    checkBalance([1, 1, 1, || 2, 1]) → true, 
    checkBalance ([2, 1, 1, 2, 1]) → false, 
    checkBalance ([10, || 1, 2, 3, 4]) → true. 
    Абстрактная граница показана символами ||, эти символы в массив не входят.

    Реализация: 155
    Применение: 254
*/
#include <iostream>

template <typename ArrT>
void printNumArray(ArrT * arr, const size_t SIZE)
{
    std::cout << "Your array: " << std::endl;

    for (size_t i = 0; i < SIZE; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

// задание 1
void printArrayDouble(double * arr, const size_t arrLength)
{
    std::cout << "Your array: " << std::endl;

    for (size_t i = 0; i < arrLength; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

// задание 2
void revertNumArray(int * arr, const size_t arrLength)
{
    // выводим полученный массив
    std::cout << "\nStock array: " << std::endl;

    for ( size_t i = 0; i < arrLength; i++ )
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // тут происходит магия
    for ( size_t i = 0; i < arrLength; i++)
    {
        arr[i] = !arr[i];
    }

    // выводим обновленный массив
    std::cout << "Updated array: " << std::endl;

    for ( size_t i = 0; i < arrLength; i++ )
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

// задание 3
void fillStepArray(int * arr, const size_t arrSize, int step)
{
    int value = 1;

    for ( size_t i = 0; i < arrSize; i++ )
    {
        arr[i] = value;
        value += step;
    }
}

// задание 4*
void shiftArray(int * arr, const size_t ARR_SIZE, const int SHIFT)
{
    // работаем только с ненулевым смещением и положительным размером массива  
    if ( SHIFT && ARR_SIZE > 0 )
    {
        // будем использовать временный массив для хранения левой части основного
        size_t tmpArrSize = 0;

        // определяем длину временного массива        
        if ( SHIFT > 0 )   // для положительного смещения
        {
            tmpArrSize = ARR_SIZE - SHIFT;
        }
        else               // для отрицательного смещения (0 мы уже исключили)
        {
            tmpArrSize = abs(SHIFT);
        }

        // выделяем временный массив
        int * tmpArr = new int[tmpArrSize];

        // заполняем временный массив левой частью основного
        for ( size_t i = 0; i < tmpArrSize; i++ )
        {
            tmpArr[i] = arr[i];
        }

        // переносим правую часть влево
        for ( size_t i = 0; i < ARR_SIZE - tmpArrSize; i++ )
        {
            // используем индексы после переданных во временный массив
            arr[i] = arr[tmpArrSize + i];
        }

        // дописываем сохранненные данные из временного массива вправо
        for ( size_t i = 0; i < tmpArrSize; i++ )
        {
            arr[ARR_SIZE - tmpArrSize + i] = tmpArr[i];
        }

        // удаляем временный массив
        delete[] tmpArr;
        tmpArr = nullptr;
    }
}

// задание 5**
bool checkBallance(int * arr, const size_t SIZE)
{
    // массив не пустой
    if ( SIZE )
    {
        // сумма элементов массива
        long long arrSum = 0;
        
        // считаем сумму
        for ( size_t i = 0; i < SIZE; i++ )
        {
            arrSum += arr[i];
        }

        // сумма должна быть четной
        if ( arrSum % 2 == 0 )
        {
            // будем сравнивать с половиной суммы, определяем сразу, чтобы не
            // вычислять в каждой итерации
            long long halfSum = arrSum / 2;

            // сумма проверочной части
            long long partSum = 0;

            // проверяем баланс
            for ( size_t i = 0; i < SIZE - 1; i++ )
            {
                // прибавляем элемент
                partSum += arr[i];

                // сравниваем 
                // проверяем пока часть не больше или равна половине
                if ( partSum <= halfSum)
                {
                    if ( partSum == halfSum )
                    {
                        return true;
                    }
                }
                else 
                {
                    return false;
                }
            }
        }
    }

    // если массив пустой, выводим false
    return false;
}

int main()
{
    // задание 1
    const size_t D_ARR_SIZE = 5;
    double darray[D_ARR_SIZE] = { 2.34, 3.14, 100.5, 4.2, 5.5 };
    printArrayDouble(darray, D_ARR_SIZE);

    // задание 2
    const size_t REVERT_ARR_SIZE = 8;
    int revArray[REVERT_ARR_SIZE] = { 1, 1, 0, 0, 1, 0, 1, 1 };
    revertNumArray(revArray, REVERT_ARR_SIZE);

    // задание 3
    const size_t STEP_ARR_SIZE = 8;
    int stepArr[STEP_ARR_SIZE] = {0};
    const int STEP = 3;
    fillStepArray(stepArr, STEP_ARR_SIZE, STEP);
    
    // выводим массив
    std::cout << "\nstepArray: ";
    for ( size_t i = 0; i < STEP_ARR_SIZE; i++ )
    {
        std::cout << stepArr[i] << " ";
    }
    std::cout << std::endl;

    // задание 4*
    // смещение
    int shift = 0;
    std::cout << std::endl;
    
    // массив длиной 5, смещение на 2 вправо
    const size_t ARR_1_SIZE = 5;
    shift = 2;
    int array1[ARR_1_SIZE] = { 2, 4, 6, 8, 10 };
    printNumArray( array1, ARR_1_SIZE );
    shiftArray( array1, ARR_1_SIZE, shift );
    printNumArray( array1, ARR_1_SIZE );
    
    // массив длиной 5, смещение на 3 влево
    const size_t ARR_2_SIZE = 6;
    shift = -3;
    int array2[ARR_2_SIZE] = { 1, 3, 5, 7, 9, 11 };
    printNumArray( array2, ARR_2_SIZE );
    shiftArray( array2, ARR_2_SIZE, shift );
    printNumArray( array2, ARR_2_SIZE );

    // задание 5**
    int arrayTrue[5] = { 1, 2, 1, 3, 1 };
    std::cout << checkBallance( arrayTrue, 5 ) << std::endl;

    int arrayFalse[5] = { 3, 6, 2, 1, 9 };
    std::cout << checkBallance(arrayFalse, 5) << std::endl;

    return 0;
}