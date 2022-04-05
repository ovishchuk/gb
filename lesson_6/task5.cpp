/*
    gb/lesson_6/task5.txt

    Написать программу, которая проверяет присутствует ли указанное 
    пользователем при запуске программы слово в указанном пользователем файле 
    (для простоты работаем только с латиницей). Используем функцию find которая 
    есть в строках std::string.
*/
#include <iostream>
#include <fstream>

/*
    проверяет файл на наличие слова

    word - слово
    fileName - файл для поиска
    line - сюда вернем номер строки, гле найдено слово (nullptr для игнора)
    column - сюда вернем номер колонки (nullptr для игнора)

    Заметка: слово ищет даже если оно часть другого, но в задании не уточнялось
    искать отдельное. Но как реализовать, впринципе, понимаю (с помощью исключения
    символов в строке по по пробелам, табам и т.д.).
*/
bool findWordInTxtFile(std::string word, std::string fileName,
                        unsigned *line, unsigned *column)
{
    // предусмотрительно обнуляем line и column
    if ( line != nullptr )
    {
        *line = 0;
    }
    if ( column != nullptr )
    {
        *column = 0;
    }

    // открываем файл для чтения
    std::ifstream inFile(fileName);

    if ( !inFile )
    {
        std::cout << "Не удалось открыть файл: " << fileName << std::endl;
    }
    else
    {
        std::string buffer = "";
        size_t foundFlag;

        // ищем построчно
        while ( getline(inFile, buffer) )
        {
            if ( line != nullptr ) 
            {
                /*
                начинаем со строки 1
                не могу понять, почему разыменование
                    *line++;
                инкрементирует указатель, а не значение, идентично с  
                    line++;
                */
                (*line)++;
            }

            foundFlag = buffer.find(word);

            if ( foundFlag != std::string::npos )
            {
                if ( column != nullptr )
                {
                    // колонка считается с 0
                    *column = foundFlag + 1;
                }
                
                return true;
            }
        }
    }

    return false;
}

int main(int argc, char *argv[])
{
    // получаем искомое слово первым указателем
    std::string searchedWord = argv[1];
    std::string fileName = "";
    std::cout << "Слово для поиска: " << searchedWord
        << "\nФайл для поиска: ";
    std::cin >> fileName;

    unsigned line = 0;
    unsigned column = 0;

    if ( findWordInTxtFile(searchedWord, fileName, &line, &column) )
    {
        std::cout << "Слово найдено, позиция: ln " << line << ", col " << column
            << std::endl;
    }
    else
    {
        std::cout << "Слово не найдено" << std::endl;
    }

    return 0;
}