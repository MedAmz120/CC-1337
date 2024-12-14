#include "ScalarConverter.hpp"

int     ascii_ = 0;

bool check_displayable(int c)
{
    if (c >= 1 && c <= 9)
        return true;
    if (!(c >= 1 && c <= 9) && !isprint(c))
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
        if (str.length() == 1)
        {
            if (isalpha(str[0]) || !isdigit(str[0]))
            {
                std::cout << "char : " << str[0] << std::endl;
                ascii_ = str[0];
                return ;
            }
        }
        int     ascii = std::stoi(str);
        ascii_ = ascii;
        if (!check_displayable(ascii))
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
        ascii_ = 48;
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

void ScalarConverter::convert(const std::string& str)
{
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