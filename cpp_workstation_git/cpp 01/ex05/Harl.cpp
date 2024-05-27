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
    int i = 0;
    std::string req[4] = {"DEBUG", "INFO", "WARNING", "ERROR"}; // use to compare with the level entered
    void (Harl::*p[4])(); // array name p of four pointers to memeber function of harl class // (empty) take no arguments
    
    p[0] = &Harl::debug;
    p[1] = &Harl::info;
    p[2] = &Harl::warning;
    p[3] = &Harl::error;
    while (i < 4)
    {
        if (req[i] == level)
        {
            (this->*p[i])();
            break ;
        }
        i++;
    }
}

Harl::Harl()
{
}

Harl::~Harl()
{
}
