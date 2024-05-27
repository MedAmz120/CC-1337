/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 13:14:40 by moamzil           #+#    #+#             */
/*   Updated: 2024/05/15 16:52:47 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    ClapTrap Clap1("josh");
    ScavTrap Scav1("MIRINDA");
    Clap1.attack("CJ"); 
    Clap1.takeDamage(10); 
    Clap1.attack("LOOL");
    Clap1.beRepaired(1);
    Clap1.attack("ENEMY");
    Scav1.attack("PORTS");
    Scav1.takeDamage(100);
    Scav1.attack("TERMINAL");
    Scav1.guardGate();
}
