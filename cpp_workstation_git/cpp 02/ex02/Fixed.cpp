/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 13:40:45 by moamzil           #+#    #+#             */
/*   Updated: 2024/05/06 13:40:49 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* ----------- Constructors ----------- */

Fixed::Fixed() // consrtuctor 1 DEFAULT
{
    std::cout << "Default constructor called" << std::endl;
    fixed_point = 0;
}

Fixed::Fixed(const int num) // Int Constructor
{
    std::cout << "Int constructor called" << std::endl;
    const int scale = 1 << fractional_bits;
    fixed_point = num * scale;
}

Fixed::Fixed(const float v) // Float constructor
{
    std::cout << "float constructor called" << std::endl;
    const int scale = 1 << fractional_bits;
    fixed_point = roundf(v * scale);
}


/* ----------- Method Functions----------- */


float Fixed::toFloat(const Fixed& fixed) const {
    return (float)(fixed.fixed_point) / (1 << fractional_bits);
}

const Fixed& Fixed::min(const Fixed& fix_1, const Fixed& fix_2)
{
    if (fix_1 < fix_2)
        return (fix_1);
    return (fix_2);
}

const Fixed&  Fixed::max(const Fixed& fix_1, const Fixed& fix_2)
{
    if (fix_1 > fix_2)
        return (fix_1);
    return (fix_2);
}

/* ----------- Comparison operators ----------- */

bool Fixed::operator<(const Fixed& a) const {
    return fixed_point < a.fixed_point;
}

bool Fixed::operator>(const Fixed& a) const {
    return fixed_point > a.fixed_point;
}

bool Fixed::operator<=(const Fixed& a) const {
    return fixed_point <= a.fixed_point;
}

bool Fixed::operator>=(const Fixed& a) const {
    return fixed_point >= a.fixed_point;
}

bool Fixed::operator==(const Fixed& a) const {
    return fixed_point == a.fixed_point;
}

bool Fixed::operator!=(const Fixed& a) const {
    return fixed_point != a.fixed_point;
}




/* ----------- Arithmetic operators ----------- */

Fixed Fixed::operator+(const Fixed& a) const 
{
    Fixed result;
    result.fixed_point = fixed_point + a.fixed_point;
    return result;
}

Fixed Fixed::operator-(const Fixed& a) const {
    Fixed result;
    result.fixed_point = fixed_point - a.fixed_point;
    return result;
}

Fixed Fixed::operator*(const Fixed& a) const {
    Fixed result;
    result.fixed_point = (fixed_point * a.fixed_point) / (1 << fractional_bits);
    return result;
}

Fixed Fixed::operator/(const Fixed& a) const {
    Fixed result;

    result.fixed_point = (fixed_point * (1 << fractional_bits)) / a.fixed_point;
    return result;
}


/* ----------- Increment operators ----------- */

Fixed& Fixed::operator++() { // pre-inc ++a
    this->fixed_point++;
    // 0 to 1 then when << operator called 1 / 256 which result 0.0033...
    return *this;
}

Fixed& Fixed::operator--() {  // pre-dec --a
    this->fixed_point--;
    return *this;
}

Fixed Fixed::operator++(int) { // post-inc a++
    Fixed temp(*this);
    this->fixed_point++;
    return temp;
}

Fixed Fixed::operator--(int) { // post-dec a--
    Fixed temp(*this);
    this->fixed_point--;
    return temp;
}



/* ----------- << Operator ----------- */

std::ostream& operator<< (std::ostream& ostream, const Fixed& fixed)
{
    ostream << fixed.toFloat(fixed);
    return (ostream);
}



/* ----------- ORTHODOX CANONICAL FORM ----------- */

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

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}