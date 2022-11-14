#include <string>
#include <iostream>

/*
  1. Создать класс Person (человек) с полями: имя, возраст, пол и вес. 
  Определить методы переназначения имени, изменения возраста и веса. Создать 
  производный класс Student (студент), имеющий поле года обучения. Определить 
  методы переназначения и увеличения этого значения. Создать счетчик количества 
  созданных студентов. В функции main() создать несколько (не больше трёх) 
  студентов. Вывести информацию о них.
*/

class Person
{
protected:
    std::string m_name;
    unsigned m_age;
    const char m_sex;
    float m_weight;
public:
    Person();
    Person(char sex) : m_name("null"), m_age(0), m_weight(0.0f), m_sex(sex) {} 
    void setName(std::string name) { m_name = name; }
    void setAge(unsigned age) { m_age = age; }
    void setWeight(float weight) { m_weight = weight; }
};

class Student: public Person
{
private:
    int m_studyYear;
public:
    static size_t studentCount;
    Student(char sex) : Person(sex) { studentCount++; }
    void setStudyYear(int year) { m_studyYear = year; }
    void incrementStudyYear() { m_studyYear++; }
    void Info()
    {
        std::cout << "Name       | " << m_name
            << "\nAge        | " << m_age
            << "\nSex        | " << m_sex
            << "\nWeight     | " << m_weight
            << "\nStudy year | " << m_studyYear << std::endl;
    }
};

size_t Student::studentCount = 0;

int main()
{
    Student Dmitriy('M');
    Dmitriy.setName("Dmitriy");
    Dmitriy.setAge(18);
    Dmitriy.setStudyYear(2022);
    Dmitriy.setWeight(72.0f);

    Student Nadia('F');
    Nadia.setName("Nadia");
    Nadia.setAge(20);
    Nadia.setStudyYear(2020);
    Nadia.setWeight(55.5f);

    Dmitriy.Info();
    std::cout << std::endl;

    Nadia.Info();
    std::cout << std::endl;

    std::cout << "Total students: " << Student::studentCount << std::endl;

    return 0;
}