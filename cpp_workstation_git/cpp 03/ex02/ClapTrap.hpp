/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 13:14:56 by moamzil           #+#    #+#             */
/*   Updated: 2024/05/15 15:31:43 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {
    protected:
    std::string     name;
    unsigned int    Hit_points;
    unsigned int    Energy_points;
    unsigned int    Attack_damage;
    
    public:
    ClapTrap(std::string const& name);
    ClapTrap();
    ClapTrap(const ClapTrap& copie);
    ClapTrap& operator=(const ClapTrap& copie);
    ~ClapTrap();
    

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

#endif