/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 13:38:21 by moamzil           #+#    #+#             */
/*   Updated: 2024/05/06 13:38:23 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

#include <cmath>
#include <iostream>

class Fixed {
    private:
    int fixed_point;
    const static int fractional_bits = 8;
    
    public:
    Fixed ();
    Fixed (const int num); // Const 1
    Fixed (const float f_num); // Const 2
    Fixed (const Fixed& copie);
    Fixed& operator=(const Fixed& copie); // Copy Assignment Operator
    ~Fixed();

    float   toFloat( void ) const;
    int     toInt( void ) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif