#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#define ZOMBIES_NUMBER 5

#include <iostream>
#include <cstdlib>

class Zombie {
    private:
    std::string name;

    public:
    Zombie ();
    ~Zombie ();
    void    announce(void);
    void    name_it(std::string str);
};

Zombie* zombieHorde( int N, std::string name );

#endif