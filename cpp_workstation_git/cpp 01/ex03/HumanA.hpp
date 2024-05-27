#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA {
    private:
    std::string name;
    Weapon& weapon;

    public:
    HumanA (std::string name_it, Weapon& weapon) : name(name_it) , weapon(weapon) {};
    void    attack();
};


#endif