#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template<typename ourtype>
void    swap(ourtype &a, ourtype &b)
{
    ourtype temp;
    temp = a;
    a = b;
    b = temp;
}

template<typename ourtype>
ourtype     max(ourtype &a, ourtype &b)
{
    if (a > b)
        return a;
    return b;
}

template<typename ourtype>
ourtype     min(ourtype &a, ourtype &b)
{
    if (a < b)
        return a;
    return b;
}

#endif