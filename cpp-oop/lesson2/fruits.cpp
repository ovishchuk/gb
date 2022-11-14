#include <string>
#include <iostream>

/*
  2. Создать классы Apple (яблоко) и Banana (банан), которые наследуют класс 
  Fruit (фрукт). У Fruit есть две переменные-члена: name (имя) и color (цвет). 
  Добавить новый класс GrannySmith, который наследует класс Apple.
*/

/*
int main()
{
Apple a("red");
Banana b;
GrannySmith c;

std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

return 0;
}

  Код, приведенный выше, должен давать следующий результат:

  My apple is red.
  My banana is yellow.
  My Granny Smith apple is green.
*/

class Fruit
{
public:
    Fruit() : name("fruit"), color("green") {}
    std::string getName() { return name; }
    std::string getColor() { return color; }
protected:
    std::string name;
    std::string color;
};

class Apple : public Fruit
{
public:
    Apple() { name = "apple"; }
    Apple(std::string newColor) { color = newColor; name = "apple"; }
};

class Banana : public Fruit
{
public:
    Banana() { name = "banana"; color = "yellow";}
};

class GrannySmith : public Apple
{
public:
    GrannySmith() { name = "Granny Smith " + name; }
};

int main()
{
    Apple a("red");
    Banana b;
    GrannySmith c;

    std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
    std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
    std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

    return 0;
}