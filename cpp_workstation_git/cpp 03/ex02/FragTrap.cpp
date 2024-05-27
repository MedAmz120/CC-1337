/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 13:15:13 by moamzil           #+#    #+#             */
/*   Updated: 2024/05/15 16:43:49 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    this->name = "Random";
    this->Hit_points = 100;
    this->Energy_points = 100;
    this->Attack_damage = 30;
    std::cout << "FragTrap " << this->name << " is created" << std::endl;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
    this->name = name;
    this->Hit_points = 100;
    this->Energy_points = 100;
    this->Attack_damage = 30;
    std::cout << "FragTrap " << this->name << " is created" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "Fragtrap " << name << " Destructor called" << std::endl;
}

void    FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << name << " request high a five !!!" << std::endl;
}