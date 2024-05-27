/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 18:29:09 by moamzil           #+#    #+#             */
/*   Updated: 2024/05/21 15:28:16 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
    type = "Dog";
    std::cout << type << " is in Now" << std::endl;
    this->dog_brain = new Brain();
}

Dog::Dog(std::string type)
{
    std::cout << type << " is in Now" << std::endl;
    this->type = type;
}

Dog::Dog(const Dog& copie)
{
    std::cout << "Dog Now has another look like brother" << std::endl;
    *this = copie;
}

Dog& Dog::operator=(const Dog& copie)
{
    std::cout << "Dog Brother hood has a matching DNA" << std::endl;
    if (this != &copie)
        this->type = copie.type;
    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog is Killed Now :( RIP" << std::endl;
    delete this->dog_brain;
}

void    Dog::makeSound() const
{
    std::cout << type << ": hau, hau, how how" << std::endl;
}

std::string Dog::getType() const
{
    return this->type;
}