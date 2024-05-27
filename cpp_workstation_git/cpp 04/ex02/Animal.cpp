/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:02:08 by moamzil           #+#    #+#             */
/*   Updated: 2024/05/19 13:20:43 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

/* ------ ORTHODOX CANONICAL FORM ------ */

Animal::Animal()
{
    type = "Random";
    std::cout << "Animal Consctructor Called" << std::endl;
}

Animal::Animal(std::string& type)
{
    this->type = type;
    std::cout << type << " Animal Consctructor Called" << std::endl;
}

Animal::~Animal()
{
    std::cout << type << " Animal Desctructor Called" << std::endl;
}

Animal::Animal(const Animal& copie)
{
    std::cout << type << " Animal Copy Constructor Called" << std::endl;
    *this = copie;
}

Animal& Animal::operator=(const Animal& copie)
{
    std::cout << type << "Animal Copy Assignement Operator Called" << std::endl;
    if (this != &copie)
        type = copie.type;
    return *this;
}

void    Animal::makeSound() const
{
}

std::string Animal::getType() const
{
    return this->type;
}