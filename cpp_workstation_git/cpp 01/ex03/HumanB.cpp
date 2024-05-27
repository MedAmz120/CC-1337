#include "HumanB.hpp"

void    HumanB::attack() {
    if (weapon != NULL)
        std::cout << name << " attacks with their " << weapon->getType() << std::endl;
    else
         std::cout << name << " Has no Gun to attack " << std::endl;
}

void    HumanB::setWeapon(Weapon &HB_weapon)
{
    weapon = &HB_weapon;
}