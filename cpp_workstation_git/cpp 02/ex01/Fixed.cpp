/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 13:38:10 by moamzil           #+#    #+#             */
/*   Updated: 2024/05/06 13:38:11 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* ------------------CONSTRUCTORS-------------------------------- */

Fixed::Fixed() // consrtuctor 1 DEFAULT
{
    std::cout << "Default constructor called" << std::endl;
    fixed_point = 0;
}

Fixed::Fixed (const int num) // constructor 2 INT
{
    std::cout << "Int constructor called" << std::endl;
    const int scale = 1 << fractional_bits; // 1 left shifted by 8 bits 256
    fixed_point = num * scale;
}

Fixed::Fixed (const float f_num) // constructor 3 FLOAT
{
    std::cout << "Float constructor called" << std::endl;
    const int scale = 1 << fractional_bits;
    fixed_point = roundf(f_num * scale);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

/* ------------------METHOD FUNCTIONS-------------------------------- */


float Fixed::toFloat( void ) const
{
    float   floating_point;

    floating_point = (float)(fixed_point) / (1 << fractional_bits);
    return (floating_point);
}

int Fixed::toInt( void ) const
{
    int     int_value;

    int_value = fixed_point >> fractional_bits;
    return (int_value);
}

/* -----------------ORTHODOX CANONICAL FORM------------------------ */


Fixed::Fixed (const Fixed& copie) // copie constructor
{
    std::cout << "Copy constructor called" << std::endl;
    *this = copie;
}

Fixed& Fixed::operator=(const Fixed& copie) // copy assignment operator
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &copie)
        fixed_point = copie.fixed_point;
    return *this;
}


/* -------------------------OPERATORS------------------------------- */

std::ostream& operator<< (std::ostream& ostream, const Fixed& fixed)
{
    ostream << fixed.toFloat();
    return (ostream);
}