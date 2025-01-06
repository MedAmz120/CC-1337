#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
void    easyfind(T &int_cont, int f_occ) {
    if (find(int_cont.begin(), int_cont.end(), f_occ) != int_cont.end())
        std::cout << "Element " << f_occ << " Found in container" << std::endl;
    else
        throw (std::invalid_argument("Element Not found in container"));
};

#endif