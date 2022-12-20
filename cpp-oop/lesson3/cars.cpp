/*
  2. Создать класс Car (автомобиль) с полями company (компания) и model 
  (модель). Классы-наследники: PassengerCar (легковой автомобиль) и Bus 
  (автобус). От этих классов наследует класс Minivan (минивэн). Создать 
  конструкторы для каждого из классов, чтобы они выводили данные о классах. 
  Создать объекты для каждого из классов и посмотреть, в какой 
  последовательности выполняются конструкторы. Обратить внимание на проблему 
  «алмаз смерти».

  Примечание: если использовать виртуальный базовый класс, то объект самого 
  "верхнего" базового класса создает самый "дочерний" класс.
*/
#include <iostream>
#include <string>

class Car
{
protected:
    std::string m_company;
    std::string m_model;
public:
    Car() { std::cout << "Car::Car()" << std::endl; }
    virtual ~Car() { std::cout << "Car::~Car()" << std::endl; }
};

class PassengerCar : virtual public Car
{
public:
    PassengerCar() { std::cout << "PassengerCar::PassengerCar()" << std::endl; }
    virtual ~PassengerCar() { std::cout << "PassengerCar::~PassengerCar()" << std::endl; }
};

class Bus : virtual public Car
{
public:
    Bus() { std::cout << "Bus::Bus()" << std::endl; }
    virtual ~Bus() { std::cout << "Bus::~Bus()" << std::endl; }
};

class Minivan : public PassengerCar, public Bus
{
public:
    Minivan() { std::cout << "Minivan::Minivan()" << std::endl; }
    ~Minivan() { std::cout << "Minivan::~Minivan()" << std::endl; }
};

int main()
{
    std::cout << "========== Car object ===========" << std::endl;
    Car car;
    std::cout << "======= PassengerCar object =====" << std::endl;
    PassengerCar passCar;
    std::cout << "========== Bus object ===========" << std::endl;
    Bus bus;
    std::cout << "======== Minivan object =========" << std::endl;
    Minivan mini;
    std::cout << "==== dynamic Minivan object =====" << std::endl;
    Minivan* pMini = new Minivan();
    std::cout << "==== Car ptr to Minivan obj =====" << std::endl;
    Car* pCar = new Minivan();
    std::cout << "========= Destructors ===========" << std::endl;
    delete pMini;
    delete pCar;

    return 0;
}