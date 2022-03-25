/* 
    lesson_2/main.cpp

    1. Создать и инициализировать переменные пройденных типов данных (short int,
        int, long long, char, bool, float, double).
    2. Создать перечисление (enum) с возможными вариантами символов для игры 
        в крестики-нолики.
    3. Создать массив, способный содержать значения такого перечисления и 
        инициализировать его.
    4. * Создать структуру (struct) данных «Поле для игры в крестики-нолики» и 
        снабдить его всеми необходимыми свойствами (подумайте что может понадобиться).
    5. ** Создать структуру (struct MyVariant) объединяющую: 
        union MyData (int, float, char) и 3-и битовых поля (флага) указывающими 
        какого типа значение в данный момент содержится в объединении 
        (isInt, isFloat, isChar). Продемонстрировать пример использования в коде
        этой структуры.
*/
#include <string>
#include <iostream>


// Задание 2:
enum Sign { SIGN_EMPTY, SIGN_CROSS, SIGN_ZERO };


// Задание 4*:
struct Field
{
    Sign cell[3][3] = { Sign::SIGN_EMPTY }; // Задание 3

    bool gameIsActive = true;
    std::string playerName[2] = { "null", "null" };
    std::string winnerName = "null";
};


// Задание 5**:
union MyData
{
    int num;
    float fnum;
    char ch;
};

struct MyVariant
{
    MyData data;
    int isInt : 1;
    int isFloat : 1;
    int isChar : 1;
};


int main()
{
    // Задание 1: 
    short int shnum = 0;
    int inum = 0;
    long long llnum = 0;
    char ch = 'A';
    bool flag = true;
    float fnum = 0.0f;
    double dnum = 0.0;

    // test 1 (Field default values)
    Field field;
    std::cout << "Player 1 name: " << field.playerName[0]
        << "\nPlayer 2 name: " << field.playerName[1]
        << "\nWinner name: " << field.winnerName
        << "\nCentral cell symbol value is " << field.cell[1][1] <<std::endl;
    
    // Задание 5** (применение)
    MyVariant myVariant;
    // int
    myVariant.data.num = 7;
    myVariant.isInt = 1;
    myVariant.isFloat = 0;
    myVariant.isChar = 0;
    // float
    myVariant.data.fnum = 3.14f;
    myVariant.isInt = 0;
    myVariant.isFloat = 1;
    myVariant.isChar = 0;
    // char
    myVariant.data.ch = 'Z';
    myVariant.isInt = 0;
    myVariant.isFloat = 0;
    myVariant.isChar = 1;

    return 0;    
}