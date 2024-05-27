#include "Zombie.hpp"

Zombie::~Zombie()
{
    std::cout << name << " is dead !\n";
}

void    Zombie::announce(void)
{
    std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}
