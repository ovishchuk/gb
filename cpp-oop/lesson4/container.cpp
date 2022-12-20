/*
  1. Добавить в контейнерный класс, который был написан в этом уроке, методы:

  • для удаления последнего элемента массива (аналог функции pop_back() в 
    векторах)
  • для удаления первого элемента массива (аналог pop_front() в векторах)
  • для сортировки массива
  • для вывода на экран элементов.
*/
#include <iostream>
#include <cassert>

class ArrayInt
{
private:
    unsigned m_length;
    int* m_data;
public:
    ArrayInt() : m_length(0), m_data(nullptr) {}
    ArrayInt(unsigned length) : m_length(length)
    {
        assert(length >= 0);
        if ( length > 0 ) { m_data = new int[length]; }
        else { m_data = nullptr; }
    }
    ~ArrayInt()
    {
        if ( m_data != nullptr ) delete[] m_data;
    }
    void erase()
    {
        if ( m_data != nullptr && m_length ) 
        {
            delete[] m_data;
            m_length = 0;
            m_data = nullptr;
        }
    }
    void push_back(int data)
    {
        int* newData = nullptr; 
        if ( m_data != nullptr )
        {
            newData = new int[m_length + 1];
            for ( size_t i = 0; i < m_length; i++ )
            {
                newData[i] = m_data[i];
            }
            delete[] m_data;
        }
        else
        {
            newData = new int[1];
        }
        newData[m_length] = data;
        m_length++;
        m_data = newData;            
    }
    void pop_back()
    {
        if ( m_data != nullptr )
        {
            m_length--;
            if ( m_length )
            {
                int* newData = new int[m_length];
                for ( size_t i = 0; i < m_length; i++ )
                {
                    newData[i] = m_data[i];
                }
                delete[] m_data;
                m_data = newData;
            }
            else
            {
                delete[] m_data;
                m_data = nullptr;
            }
        }
    }
    void pop_front()
    {
        if ( m_data )
        {
            m_length--;
            if ( m_length )
            {
                int* newData = new int[m_length];
                for ( size_t i = 1; i <= m_length; i++ )
                {
                    newData[i - 1] = m_data[i];
                }
                delete[] m_data;
                m_data = newData;
            }
            else
            {
                delete[] m_data;
                m_data = nullptr;
            }
        }
    }
    void sort()
    {
        bool swap;
        do
        {
            swap = false;
            for ( size_t i = 1; i < m_length; i++ )
            {
                if ( m_data[i - 1] > m_data[i] )
                {
                    int tmp = m_data[i - 1];
                    m_data[i - 1] = m_data[i];
                    m_data[i] = tmp;
                    swap = true;
                }

            }
        } while ( swap );
    }
    void print()
    {
        for ( size_t i = 0; i < m_length; i++ )
        {
            std::cout << m_data[i] << " ";
        }
        std::cout << std::endl;
    }
    int& operator[](const int index)
    {
        assert(index >= 0);
        return m_data[index];
    }
};

int main()
{
    ArrayInt arr(3);
    arr[0] = 5;
    arr[1] = 3;
    arr[2] = 1;
    arr.print();
    std::cout << "push_back()" << std::endl;
    arr.push_back(6);
    arr.print();
    std::cout << "sort()" << std::endl;
    arr.sort();
    arr.print();
    std::cout << "pop_front()" << std::endl;
    arr.pop_front();
    arr.print();
    std::cout << "pop_back()" << std::endl;
    arr.pop_back();
    arr.print();

    return 0;
}