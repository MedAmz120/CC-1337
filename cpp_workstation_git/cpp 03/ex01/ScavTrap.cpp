/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 22:49:13 by moamzil           #+#    #+#             */
/*   Updated: 2024/05/15 16:40:53 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    this->name = name;
    this->Hit_points = 100;
    this->Energy_points = 50;
    this->Attack_damage = 20;
    std::cout << "ScavTrap " << this->name << " is created" << std::endl;
}

ScavTrap::ScavTrap(const std::string &given_name) : ClapTrap(given_name)
{
    this->name = given_name;
    this->Hit_points = 100;
    this->Energy_points = 50;
    this->Attack_damage = 20;
    std::cout << "ScavTrap " << this->name << " is created" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << name << " Destructor Called" << std::endl;
}

void    ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << this->name << " is now in Gate Keeper Mode" << std::endl;
}