#ifndef BASE_HPP
#define BASE_HPP

#include <random>
#include <iostream>


class Base {
    public:
    virtual ~Base() = 0;
};

Base * generate(void);
void identify(Base* p);
void identify(Base& p);

#endif