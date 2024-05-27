/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 09:51:17 by moamzil           #+#    #+#             */
/*   Updated: 2024/05/20 12:34:02 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
    type = "Cat";
    std::cout << "Cat Has born (default constructor)" << std::endl;
}

Cat::Cat(std::string type)
{
    std::cout << type + " Has newly born (constructor 2)" << std::endl;
    this->type = type;
}

Cat::Cat (const Cat& copie)
{
    std::cout << copie.type << "Has born (CPconstructor)" << std::endl;
    *this = copie;
}

Cat& Cat::operator=(const Cat& copie)
{
    std::cout << copie.type << "is looking like this newly born (cpaop)" << std::endl;
    if (this != &copie)
        this->type = copie.type;
    return *this;
}

Cat::~Cat()
{
    std::cout << this->type << " is dead :) RIP (DEST)" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << type << ": miaow, miaow, miaow miaowwwww" << std::endl;
}

std::string Cat::getType() const
{
    return this->type;
}