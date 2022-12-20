/*
  1. Создать абстрактный класс Figure (фигура). Его наследниками являются классы 
  Parallelogram (параллелограмм) и Circle (круг). Класс Parallelogram — базовый 
  для классов Rectangle (прямоугольник), Square (квадрат), Rhombus (ромб). Для 
  всех классов создать конструкторы. Для класса Figure добавить чисто 
  виртуальную функцию area() (площадь). Во всех остальных классах переопределить
  эту функцию, исходя из геометрических формул нахождения площади.
*/
#include <math.h>
#include <iostream>

class Figure
{
public:
    virtual ~Figure() {}
    virtual double area() = 0;
};

class Parallelogram : virtual public Figure
{
protected:
    double m_sideA;
    double m_sideB;
public:
    Parallelogram() {}
    Parallelogram(double sideA, double sideB)
        : m_sideA(sideA), m_sideB(sideB) 
    {
    }
    virtual ~Parallelogram() {}
    virtual double area() override
    {
        return m_sideA * m_sideB;
    }
};

class Circle : virtual public Figure
{
private:
    double m_radius;
public:
    Circle(double radius)
        : m_radius(radius)
    {
    }
    ~Circle() {}
    virtual double area() override
    {
        return 3.14 * pow(m_radius, 2);
    }
};

class Rectangle : virtual public Parallelogram
{
public:
    Rectangle(double sideA, double sideB) : Parallelogram(sideA, sideB) {}
    ~Rectangle() {}
};

class Square : virtual public Parallelogram
{
public:
    Square(double side) : Parallelogram(side, side) {}
    ~Square() {}
};

class Rhombus : virtual public Parallelogram
{
private:
    double m_diagA;
    double m_diagB;
public:
    Rhombus(double diagA, double diagB)
        : m_diagA(diagA), m_diagB(diagB)
    {
        // side**2 == (diagA / 2)**2 + (diagB / 2)**2
        m_sideA = sqrt(pow(m_diagA / 2, 2) + pow(m_diagB / 2, 2));
        m_sideB = m_sideA;
    }
    ~Rhombus() {}
    virtual double area() override
    {
        return 0.5 * m_diagA * m_diagB;
    }    
};

int main()
{
    Circle circle(5.6);
    Rectangle rect(3.5, 6);
    Square square(4);
    Rhombus rhombus(4.6, 8);

    std::cout << "Circle:         |  " << circle.area()
        << "\nRectangle:      |  " << rect.area()
        << "\nSquare:         |  " << square.area()
        << "\nRhombus:        |  " << rhombus.area() << std::endl;

    return 0;
}