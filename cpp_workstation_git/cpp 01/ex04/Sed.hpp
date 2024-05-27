#ifndef SED_HPP
#define SED_HPP
#define EXIT_FAILURE 1

#include <iostream>
#include <fstream>
// #include <string>

class args {
    public:
    std::string     s1;
    std::string     s2;
    std::ifstream   src; // "input file stream" and is used to read data from files
    std::string     source_file;
    args(const char* filename, const std::string& arg1, const std::string& arg2) : s1(arg1), s2(arg2), source_file(filename), src(filename) {}
};

void    quit_program(int error, std::string cerr);
void    ft_sed(args *data);

#endif