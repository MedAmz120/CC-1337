/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 13:14:40 by moamzil           #+#    #+#             */
/*   Updated: 2024/05/15 12:46:03 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ClapTrap.hpp"

int main()
{
    ClapTrap Clap1("josh");

    Clap1.attack("CJ");
    Clap1.takeDamage(10);
    Clap1.attack("LOOL");
    Clap1.attack("LOOL");
    Clap1.attack("LOOL");
    Clap1.beRepaired(10);
    Clap1.attack("DEBUG");
}
