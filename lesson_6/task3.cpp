/*
    gb/lesson_6/task3.cpp

    Написать программу, которая создаст два текстовых файла (*.txt), примерно
    по 50-100 символов в каждом (особого значения не имеет с каким именно 
    содержимым). Имена файлов запросить у польлзователя.
*/
#include <fstream>
#include <iostream>
#include <string>

void writeFile(std::string filename)
{
    filename += ".txt";

    std::ofstream stream(filename);

    if ( stream.is_open() )
    {
        for ( size_t i = 0; i < 5; i++ )
        {
            stream << i << "\tзапись в файл " << filename << std::endl;
        }
    }
    else
    {
        std::cout << "Не получилось открыть файл для записи." << std::endl;
    }

    stream.close();
}

int main()
{
    std::string filename = "";

    std::cout << "Введите имя первого файла (без расширения): ";
    std::cin >> filename;
    writeFile(filename);

    std::cout << "Введите имя второго файла (без расширения): ";
    std::cin >> filename;
    writeFile(filename);
}