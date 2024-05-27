#include "Zombie.hpp"

int main()
{
    class Zombie*   zombies;
    int i = -1;

    zombies = zombieHorde(ZOMBIES_NUMBER, "William");
    while (++i < ZOMBIES_NUMBER)
        zombies[i].announce();
    delete[] zombies;
    return (0);
}