/*
  2. Дан вектор чисел, требуется выяснить, сколько среди них различных. 
  Постараться использовать максимально быстрый алгоритм.
*/
#include <vector>
#include <iostream>

int unique(const std::vector<int>& arr)
{
    int result = 0;
    for ( size_t i = 0; i < arr.size(); i++ )
    {
        bool repeat = false;
        for ( size_t j = 0; j < arr.size(); j++ )
        {
            if ( i != j && arr[i] == arr[j] ) { repeat = true; }
        }
        if ( !repeat ) { result++; }
    }
    return result;
}

int main()
{
    std::vector<int> arrInt = { 3, 6, 7, 8, 3, 2, 0, 2, 5 };
    std::cout << unique(arrInt) << std::endl;

    return 0;
}