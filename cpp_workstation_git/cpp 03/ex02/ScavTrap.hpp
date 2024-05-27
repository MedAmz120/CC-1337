/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 22:50:02 by moamzil           #+#    #+#             */
/*   Updated: 2024/05/15 15:40:39 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{     // ScavTrap is the derived class     and CLAPTRAP is the base class
    public:
    ScavTrap ();
    ScavTrap (const std::string& name);
    ~ScavTrap();
    void guardGate(); 
};

#endif
