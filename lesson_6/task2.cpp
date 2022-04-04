/*
    gb/lesson_6/task2.cpp

    Динамически выделить матрицу 4х4 типа int. Инициализировать ее 
    псевдослучайными числами через функцию rand. Вывести на экран. Разбейте вашу
    программу на функции которые вызываются из main.
*/
#include <iostream>
#include <random>

// возвращаем динамическую равностороннюю матрицу со стороной SIZE
int ** createSquareMatrix(const size_t SIZE)
{
    // размер не может быть 0
    if ( SIZE > 0 )
    {
        // выделяем столбцы
        int ** matrix = new int * [SIZE];

        // заполняем столбцы рядами
        for ( size_t i = 0; i < SIZE; i++ )
        {
            // выделяем ряд и инициализируем значения нулями по умолчанию
            matrix[i] = new int[SIZE]{};
        }

        return matrix;
    }

    // если SIZE <= 0 
    return nullptr;
}

void clearSquareMatrix(int ** matrix, const size_t SIZE)
{
    // убеждаемся, что матрица выделена
    if ( matrix != nullptr )
    {
        // удаляем и обнуляем ряды
        for (size_t i = 0; i < SIZE; i++)
        {
            delete [] matrix[i];
            matrix[i] = nullptr;
        }

        // удаляем и обнуляем столбцы
        delete [] matrix;
        matrix = nullptr;
    }
}

void printSquareMatrix(int ** matrix, const size_t SIZE)
{
    for ( size_t i = 0; i < SIZE; i++ )
    {
        for ( size_t j = 0; j < SIZE; j++ )
        {
            std::cout << matrix[i][j] << "\t";
        }

        std::cout << std::endl;
    }
}

void initSquareMatrixRand(int ** matrix, const size_t SIZE)
{
    srand(time(NULL));

    for ( size_t i = 0; i < SIZE; i++ )
    {
        for ( size_t j = 0; j < SIZE; j++ )
        {
            matrix[i][j] = rand();
        }
    }
}

int main()
{
    const size_t MATRIX_SIZE = 4;
    int ** matrix = createSquareMatrix(MATRIX_SIZE);

    if ( matrix != nullptr )
    {
        initSquareMatrixRand(matrix, MATRIX_SIZE);
        printSquareMatrix(matrix, MATRIX_SIZE);
        clearSquareMatrix(matrix, MATRIX_SIZE);
    }

    return 0;
}