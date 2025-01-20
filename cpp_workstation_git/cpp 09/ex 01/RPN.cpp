#include "RPN.hpp"

RPN::RPN () {}

RPN::RPN(const RPN& copie) {
    *this = copie;
}

RPN& RPN::operator=(const RPN& copie) {
    if (this != &copie)
        stack = copie.stack;
    return *this;
}

RPN::~RPN() {}

void    RPN::number_(const std::string& number_token)
{
    std::istringstream  iss(number_token);
    int number;

    if (iss >> number)
    {
        if (number >= 10)
            throw std::logic_error("Error: Number is > 10 -> " + number_token);
        stack.push(number);
    }
    else
        throw std::logic_error("Error: invalid token -> " + number_token);
}

void    RPN::operation_(const std::string& oper)
{
    if (stack.size() < 2)
        throw std::logic_error("Error: bad operator -> " + oper);
    int number2 = stack.top(); // get the top stack value
    stack.pop(); // pop it
    int number1 = stack.top(); // get the next top stack value again
    stack.pop(); // pop it

    if (oper == "+")
        stack.push(number1 + number2);
    else if (oper == "-")
        stack.push(number1 - number2);
    else if (oper == "*")
        stack.push(number1 * number2);
    else if (oper == "/")
    {
        if (number2 == 0)
            throw std::logic_error("Error: division by 0");
        stack.push(number1 / number2);
    }
}

int RPN::rpn_calculation(const std::string& rpn)
{
    std::istringstream  iss(rpn); // Tokenize rpn
    std::string         token;

    while (iss >> token) // >> pulls out one token at a time
    {
        if (token == "/" || token == "+" || token == "-" || token == "*")
            operation_(token);
        else
            number_(token);
    }
    if (stack.size() != 1)
        throw std::logic_error("Error: Invalid argument <RPN>");
    return stack.top(); // the only member left on the stack is the result 
}