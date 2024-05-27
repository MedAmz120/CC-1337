#include "Harl.hpp"

void Harl::debug() {
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info() {
    std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning() {
    std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error() {
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void    Harl::complain(std::string level)
{
    std::string req[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Harl::*p[4])();
    p[0] = &Harl::debug;
    p[1] = &Harl::info;
    p[2] = &Harl::warning;
    p[3] = &Harl::error;
    int i = 0;
    int cas_e = -1;
    while (i < 4)
    {
        if (req[i] == level)
        {
            cas_e = i;
            break ;
        }
        i++;
    }
    switch (cas_e)
    {
        case 0:
        Harl::debug();
        case 1:
        Harl::info();
        case 2:
        Harl::warning();
        case 4:
        Harl::error();
        break;
        default:
        std::cout << "[ Probably complaining about insignificant problems ]";
    }
}

Harl::Harl()
{
}

Harl::~Harl()
{
}