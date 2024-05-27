/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 13:14:34 by moamzil           #+#    #+#             */
/*   Updated: 2024/05/15 15:29:59 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    name = "Random";
    Hit_points = 10;
    Energy_points = 10;
    Attack_damage = 0;
    std::cout << "ClapTrap " + name + " is created" << std::endl;
}

ClapTrap::ClapTrap(std::string const& name_it)
{
    name = name_it;
    Hit_points = 10;
    Energy_points = 10;
    Attack_damage = 0;
    std::cout << "ClapTrap " + name + " is created" << std::endl;
}

/*---------------------------------*/

void ClapTrap::attack(const std::string& target)
{
    if (Hit_points <= 0 || Energy_points <= 0)
        std::cout << name << " have no Hit or Energy points to attack " << target << std::endl;
    else
    {
        std::cout << "ClapTrap " + name << " attacks " + target << ", causing " << Attack_damage << " points of damage!\n";
        Energy_points--;
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (amount <= 0)
    {
        std::cout << "you can't hit " << name << "with this big number go away" << std::endl;
        return ;
    }
    if (this->Hit_points <= amount)
    {
        std::cout << "ClapTrap " << name << " take damage lose of " << amount << " energy points\n";
        this->Hit_points = 0;
        return ;
    }
    std::cout << "ClapTrap " + this->name + " take Damage lose " << amount << " Energy_points" << std::endl;
    this->Hit_points -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (Energy_points <= 0)
    {
        std::cout << "ClapTrap " + name + " Can't repaire itself no Energy points Left" << std::endl;
        return ;
    }
    std::cout << "ClapTrap " + name + " repairing it self + " << amount << " Hits_points" << std::endl;
    Hit_points += amount;
    Energy_points--;
}


/* ------------ ORTHODOX CANONICAL FORM ------------- */

ClapTrap::ClapTrap(const ClapTrap& copie)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = copie;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& copie)
{
    this->name = copie.name;
    this->Hit_points = copie.Hit_points;
    this->Energy_points = copie.Energy_points;
    this->Attack_damage = copie.Attack_damage;
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << name << " Destructor Called" << std::endl;
}
