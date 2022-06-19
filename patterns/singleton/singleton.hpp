#ifndef PATTERNS_SINGLETON_HPP
#define PATTERNS_SINGLETON_HPP

class Singleton
{
public:
    static Singleton* getInstance();
private:
    Singleton();
    static Singleton* instance;
};

#endif // PATTERNS_SINGLETON_HPP