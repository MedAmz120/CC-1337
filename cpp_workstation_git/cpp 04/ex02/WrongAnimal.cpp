/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:02:08 by moamzil           #+#    #+#             */
/*   Updated: 2024/05/19 12:39:09 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

/* ------ ORTHODOX CANONICAL FORM ------ */

WrongAnimal::WrongAnimal()
{
    std::cout << "WrongAnimal Consctructor Called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string& type)
{
    this->type = type;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal Desctructor Called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& copie)
{
    std::cout << "WrongAnimal Copy Constructor Called" << std::endl;
    *this = copie;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& copie)
{
    std::cout << "WrongAnimal Copy Assignement Operator Called" << std::endl;
    if (this != &copie)
        type = copie.type;
    return *this;
}

void    WrongAnimal::makeSound() const
{
    std::cout << type << "WrongAnimal is making a weird SOUND" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return this->type;
}