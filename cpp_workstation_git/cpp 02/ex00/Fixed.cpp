/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 13:15:15 by moamzil           #+#    #+#             */
/*   Updated: 2024/05/06 13:17:45 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed () // constructor
{
    std::cout << "Default constructor called" << std::endl;
    fixed_point = 0;
}

Fixed::Fixed (const Fixed& copie) // copie constructor
{
    std::cout << "Copy constructor called" << std::endl;
    *this = copie;
    /* this = copie;*this refers to the current object instance that's being constructed.*/
}

Fixed& Fixed::operator=(const Fixed& copie) // copy assignment operator
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &copie) /*checks if the object being assigned to itself*/
        fixed_point = copie.fixed_point;
    return *this; 
}

int Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (fixed_point);
}

void    Fixed::setRawBits(int const raw)
{
    fixed_point = raw;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}