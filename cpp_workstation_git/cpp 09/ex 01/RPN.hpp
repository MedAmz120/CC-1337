#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <stdexcept>

class RPN {
    private:
    std::stack<int>  stack;

    public:
    RPN();
    RPN(const RPN& copie);
    RPN& operator=(const RPN& copie);
    ~RPN();

    int    rpn_calculation(const std::string& rpn);
    void   operation_(const std::string& oper);
    void   number_(const std::string& number);
};

#endif