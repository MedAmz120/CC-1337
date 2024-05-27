/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 13:40:37 by moamzil           #+#    #+#             */
/*   Updated: 2024/05/06 13:41:33 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

#include <iostream>
#include <cmath>

class Fixed {
    private:
    int fixed_point;
    const static int fractional_bits = 8;
    
    public:
    Fixed (); // default constructor
    Fixed(float v); // float constructor
    Fixed(const int num); // INT constructor
    Fixed (const Fixed& copie); // copy constructor
    Fixed& operator=(const Fixed& copie); // Copy Assignment Operator
    ~Fixed();

    // Comparison Operators
    bool operator<(const Fixed& a) const;
    bool operator>(const Fixed& a) const;
    bool operator<=(const Fixed& a) const;
    bool operator>=(const Fixed& a) const;
    bool operator==(const Fixed& a) const;
    bool operator!=(const Fixed& a) const;

    // Arithmetic Operators
    Fixed operator+(const Fixed& a) const;
    Fixed operator-(const Fixed& a) const;
    Fixed operator*(const Fixed& a) const;
    Fixed operator/(const Fixed& a) const;

    
    Fixed& operator++();// Pre-increment Operator
    Fixed operator++(int);// Post-increment Operator
    Fixed& operator--();// Pre-decrement Operator
    Fixed operator--(int);// Post-decrement Operator

    // Comparison between two objects instance
    static const Fixed& min(const Fixed& fix_1, const Fixed& fix_2);
    static const Fixed&  max(const Fixed& fix_1, const Fixed& fix_2);

    float   toFloat(const Fixed& fixed) const ;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif