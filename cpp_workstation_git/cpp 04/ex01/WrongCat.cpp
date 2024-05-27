/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 09:51:17 by moamzil           #+#    #+#             */
/*   Updated: 2024/05/19 11:52:19 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    type = "Random";
    std::cout << "Random WrongCat Default constructor Called" << std::endl;
}

WrongCat::WrongCat(std::string type)
{
    std::cout << "WrongCat " + type + " Constructor Called" << std::endl;
    this->type = type;
}

WrongCat::WrongCat (const WrongCat& copie)
{
    std::cout << "WrongCat copy constructor called" << std::endl;
    *this = copie;
}

WrongCat& WrongCat::operator=(const WrongCat& copie)
{
    std::cout << "WrongCat copy assignement operator called" << std::endl;
    if (this != &copie)
        this->type = copie.type;
    return *this;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat Destructor Called" << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << type << ": miaow, miaow, miaow miaowwwww" << std::endl;
}

std::string WrongCat::getType() const
{
    return this->type;
}