#include "ScalarConverter.hpp"

int     ascii_ = 0;

bool check_displayable(int c)
{
    // if (c >= 1 && c <= 9)
    //     return true;
    if (/*!(c >= 1 && c <= 9) && */!isprint(c))
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
    std::cout << "float : "<< std::fixed <<std::setprecision(1) << result << "f" <<std::endl;
}

void ScalarConverter::convertToDouble()
{
    double result = ascii_;
    std::cout << "double : "<< std::fixed <<std::setprecision(1) << result <<std::endl;
}

bool string_combination_checker(const std::string& str)
{
    int dotCount = 0; // Keep track of dots
    int signCount = 0; // Keep track of + or -
    
    for (size_t i = 0; i < str.length(); i++) {
        char c = str[i];
        
        // Check if the character is a digit
        if (isdigit(c)) {
            continue; // Digits are always fine
        }
        
        // Check for '+' or '-' at the start
        if ((c == '+' || c == '-') && i == 0) {
            signCount++;
            continue;
        }
        
        // Check for '.' but only allow one
        if (c == '.') {
            dotCount++;
            if (dotCount > 1) {
                return false; // Too many dots
            }
            continue;
        }

        // Check for 'f' at the end (for float)
        if (c == 'f' && i == str.length() - 1) {
            continue; // 'f' at the end is fine
        }

        // Anything else is invalid
        return false;
    }
    if (signCount > 1)
        return false;
    return true; // If we passed all checks, it's valid
}

void ScalarConverter::convert(const std::string& str)
{
    if (!string_combination_checker(str))
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;

        if (str == "nanf")
        {
            std::cout << "float: " << str << std::endl;
            std::cout << "double: nan" << std::endl; // Adjust double output
        }
        else if (str == "-inff" || str == "+inff")
        {
            std::cout << "float: " << str.substr(1) << std::endl; // Skip the sign
            std::cout << "double: " << str.substr(1, str.length() - 2) << std::endl; // Remove 'f'
        }
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