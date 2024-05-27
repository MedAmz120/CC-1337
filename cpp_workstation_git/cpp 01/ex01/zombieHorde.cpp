#include "Zombie.hpp"

void    Zombie::name_it(std::string name)
{
    Zombie::name = name;
}
Zombie::Zombie()
{
}

Zombie* zombieHorde( int N, std::string name )
{
    class Zombie* zombies = new Zombie[N];
    int i = -1;

    while (++i < N)
        zombies[i].name_it(name);
    return (zombies);
}