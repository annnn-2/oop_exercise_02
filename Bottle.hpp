#ifndef Bottle_hpp
#define Bottle_hpp

#include <cstdio>
#include <cstdlib>//для использования функции strtod
#include <iostream> //для ввода/вывода
#include <cstring> //для работы со строками


class Bottle {//
    private:
    //атрибуты класса
    double a, b;
    //методы класса
    friend double operator+(const Bottle& lhv,const Bottle& rhv); //friend для обращения к privat членам класса
    friend double operator-(const Bottle& lhv,const Bottle& rhv);
    friend bool operator==(const Bottle& lhv,const Bottle& rhv);
    friend bool operator<(const Bottle& lhv,const Bottle& rhv);
    friend bool operator>(const Bottle& lhv,const Bottle& rhv);
    friend std::ostream &operator<<(std::ostream &out,const Bottle& rec);
    friend std::istream &operator>>(std::istream &in, Bottle& rec);
    public:
    //методы класса
    Bottle() : a(0), b(0) {}
    Bottle(double aa, double bb) : a(aa), b(bb) {}
    virtual ~Bottle(){}
};

#endif /* Bottle_hpp */
