/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 13:14:40 by moamzil           #+#    #+#             */
/*   Updated: 2024/05/15 16:52:57 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    ClapTrap Clap1("josh");
    ScavTrap Scav1("MIRINDA");
    FragTrap Frag1("POOR GUY");
    Clap1.attack("MIRINDA");
    Scav1.attack("josh");
    Frag1.attack("MIRINDA");
    Scav1.guardGate();
    Frag1.highFivesGuys();    
}
