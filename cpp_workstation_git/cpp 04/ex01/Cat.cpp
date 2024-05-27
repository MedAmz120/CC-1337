/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 09:51:17 by moamzil           #+#    #+#             */
/*   Updated: 2024/05/21 15:27:23 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
    type = "Cat";
    std::cout << "Cat Has born" << std::endl;
    this->cat_brain = new Brain();
}

Cat::Cat(std::string type)
{
    std::cout << type + " Has newly born" << std::endl;
    this->type = type;
    this->cat_brain = new Brain();
}

Cat::Cat (const Cat& copie)
{
    std::cout << copie.type << "Has born (cpconstructor)" << std::endl;
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
    std::cout << this->type << " is dead :) RIP" << std::endl;
    delete this->cat_brain;
}

void Cat::makeSound() const
{
    std::cout << type << ": miaow, miaow, miaow miaowwwww" << std::endl;
}

std::string Cat::getType() const
{
    return this->type;
}