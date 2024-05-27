#include "Zombie.hpp"

int main()
{
    class Zombie* newz;

    std::string name = "Harry";
    std::string name2 = "Thomas";
    randomChump(name);
    newz = newZombie(name2);
    delete(newz);
    return (0);
}