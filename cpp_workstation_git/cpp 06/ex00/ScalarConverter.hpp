#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <ctype.h>
#include <iomanip>

class ScalarConverter {
    public:
    static void    convert(const std::string& str);

    static void    convertToChar(const std::string& str);
    static bool    convertToInt(const std::string& str);
    static void    convertToFloat();
    static void    convertToDouble();
};

#endif