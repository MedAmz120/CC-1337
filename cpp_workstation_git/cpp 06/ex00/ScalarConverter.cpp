/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 16:01:56 by moamzil           #+#    #+#             */
/*   Updated: 2025/01/01 16:00:54 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int     ascii_ = 0;

/* ----------- ORTHODOX CANONICAL FORM -----------*/

ScalarConverter::ScalarConverter () {}
ScalarConverter::ScalarConverter (const ScalarConverter &copie) {
    *this = copie;
}
ScalarConverter::~ScalarConverter () {};

/* ----------- END ORTHODOX CANONICAL FORM -----------*/

bool check_displayable(int c)
{
    if (!isprint(c))
        return false;
    return true;
}

bool    isALLdigits(const std::string& str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] < 48 || str[i] > 57)
            return false;
    return true;
}

bool    string_or_not(const std::string& str)
{
    if (str.length() > 1 && isalpha(str[0]))
        return false;
    return true;
}

bool string_combination_checker(const std::string& str)
{
    int dotCount = 0;
    int signCount = 0;
    
    for (size_t i = 0; i < str.length(); i++) {
        char c = str[i];
        
        if (isdigit(c)) {
            continue;
        }
        if ((c == '+' || c == '-') && i == 0) {
            signCount++;
            continue;
        }
        if (c == '.') {
            dotCount++;
            if (dotCount > 1) {
                return false;
            }
            continue;
        }
        if ((isalpha(c) && i >= 1 && i != 0)) {
            if (c == 'f' && i == str.length() - 1 && !isalpha(str[i - 1])) 
                continue;
            return false;
        }
    }
    if (signCount > 1)
        return false;
    return true;
}

void convertPseudo(const std::string& str) {
    float fValue = std::strtof(str.c_str(), nullptr);
    double dValue = std::strtod(str.c_str(), nullptr);

    std::cout << "Float: " << fValue << "f" << std::endl;
    std::cout << "Double: " << dValue << std::endl;
}


void ScalarConverter::convertToChar(const std::string& str)
{
    if (!string_or_not(str))
        std::cout << "char : Non displayable" << std::endl;
    else
    {
        if (str.length() == 1) // if we test with single char if isnt't goes to the second part
        {
            if (isalpha(str[0]) || !isdigit(str[0]))
            {
                std::cout << "char : " << str[0] << std::endl;
                ascii_ = str[0];
                return ;
            }
        }
        // second part
        int     ascii = std::stoi(str); // if we test with a numeric combination like 89 we convert it to int end up with Y char
        ascii_ = ascii;
        if (ascii < 0)
            std::cout << "char : impossible" << std::endl;
        else if (!check_displayable(ascii))
            std::cout << "char : Non displayable" << std::endl;
        else
        {
            char    c     = static_cast<char>(ascii);
            if (ascii >= 1 && ascii <= 9)
                std::cout << "char : " << str[0] << std::endl;
            else if (c == 0)
                std::cout << "char : 0" << std::endl;
            else if (c == 32)
                std::cout << "char : ' '" << std::endl;
            else
                std::cout << "char : " << c << std::endl;
        }
    }
}

bool ScalarConverter::convertToInt(const std::string& str)
{
    if (ascii_ != 0)
    {
        std::cout << "int : " << ascii_ << std::endl;
        return true;
    }
    else if (ascii_ == 0 && str.length() == 1 && str[0] == '0')
    {
        ascii_ = 0;
        std::cout << "int : " << ascii_<< std::endl;
        return true;
    }
    else
        std::cout << "int : 0" << std::endl;
    return false;
}

void ScalarConverter::convertToFloat()
{
    float result = ascii_;
    std::cout << "float : "<< std::fixed << std::setprecision(1) << result << "f" <<std::endl;
}

void ScalarConverter::convertToDouble()
{
    double result = ascii_;
    std::cout << "double : "<< std::fixed << std::setprecision(1) << result <<std::endl;
}

void ScalarConverter::convert(const std::string& str)
{
    if (!string_combination_checker(str))
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;

        if (str == "nan" || str == "nanf" ||str == "-inff" || str == "+inff" || str == "inff"
            || str == "-inf" || str == "+inf" || str == "inf")
                convertPseudo(str);
        else
        {
            std::cout << "float: impossible" << std::endl;
            std::cout << "double: impossible" << std::endl;
        }
        return;
    }
    convertToChar(str);
    if (convertToInt(str) != false)
    {
        convertToFloat();
        convertToDouble();
        return ;
    }
    std::cout << "float : 0.0f" << std::endl;
    std::cout << "double : 0.0" << std::endl;
}