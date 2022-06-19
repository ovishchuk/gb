#include "singleton.hpp"
#include <iostream>

int main()
{
    Singleton *instance1 = Singleton::getInstance();

    std::cout << "1 - " << instance1 << std::endl; 
    
    Singleton *instance2 = Singleton::getInstance();

    std::cout << "2 - " << instance2 << std::endl; 

    delete instance1;
    instance1 = nullptr;
    delete instance2; // double free runtime error here
    instance2 = nullptr;

    return 0;
}