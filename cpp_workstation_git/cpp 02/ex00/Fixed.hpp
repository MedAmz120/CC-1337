/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 13:15:24 by moamzil           #+#    #+#             */
/*   Updated: 2024/05/06 13:37:36 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

#include <iostream>

class Fixed {
    private:
    int                 fixed_point;
    const static int    fractional_bits = 8;
    
    public:
    Fixed ();
    Fixed (const Fixed& copie);
    Fixed& operator=(const Fixed& copie); // Copy Assignment Operator
    ~Fixed();

    int     getRawBits(void) const;
    void    setRawBits(int const raw);
};

#endif