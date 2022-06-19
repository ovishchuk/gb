/*
    gb/lesson_6/task4.cpp
    -std=c++2a

    (3. Написать программу, которая создаст два текстовых файла (*.txt), примерно
    по 50-100 символов в каждом (особого значения не имеет с каким именно 
    содержимым). Имена файлов запросить у польлзователя.)

    4*. Написать функцию, «склеивающую» эти файлы в третий текстовый файл (имя 
    файлов спросить у пользователя).
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

void appendFiles()
{
    std::string baseName = "";
    std::cout << "Введите имя базового файла: ";
    std::cin >> baseName;
    std::ifstream baseFile(baseName);

    if ( !baseFile.is_open() )
    {
        std::cout << "Невозможно открыть файл " << baseName << std::endl;
    }
    else
    {
        std::string addonName = "";
        std::cout << "Введите имя добавляемого файла: ";
        std::cin >> addonName;
        std::ifstream addonFile(addonName);

        if ( !addonFile.is_open() )
        {
            std::cout << "Невозможно открыть файл " << addonName << std::endl;
        }
        else
        {
            std::string resultName = "";
            std::cout << "Введите имя итогового файла: ";
            std::cin >> resultName;
            std::ofstream resultFile(resultName, std::ios_base::app);

            if ( !resultFile.is_open() )
            {
                std::cout << "Невозможно открыть файл " << resultName << std::endl;
            }
            else
            {
                std::string buffer = "";

                // записываем первый файл
                while ( getline(baseFile, buffer) )
                {
                    resultFile << buffer << std::endl;
                    buffer = "";
                }

                // закрываем первый файл
                baseFile.close();

                // записываем второй файл
                while ( getline(addonFile, buffer) )
                {
                    resultFile << buffer << std::endl;
                    buffer = "";
                }

                // закрываем второй файл
                addonFile.close();

                // закрываем итоговый файл
                resultFile.close();
            }
        }
    }
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

    appendFiles();

    return 0;
}