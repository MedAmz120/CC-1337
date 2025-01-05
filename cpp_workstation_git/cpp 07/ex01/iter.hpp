#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template<typename ourtype, typename func>
void    iter(ourtype arr, int len, func called_func)
{
    for (int i = 0; i < len; ++i)
    {
        called_func (arr[i]);
    }
}

#endif