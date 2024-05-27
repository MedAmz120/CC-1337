/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 13:39:25 by moamzil           #+#    #+#             */
/*   Updated: 2024/05/06 13:39:28 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void )
{
    Fixed a; // default constructor executed
    Fixed const b( 10 ); // int constructor called
    Fixed const c( 42.42f ); // float constructor called
    Fixed const d( b ); // copy constructor called
    a = Fixed( 1234.4321f ); // copy assignment and float constructor called


    std::cout << "a is " << a << std::endl;     /*----------------------*/
    std::cout << "b is " << b << std::endl;     /*-----Converting-------*/
    std::cout << "c is " << c << std::endl;     /*----------To----------*/
    std::cout << "d is " << d << std::endl;     /*------FloatFixp-------*/
    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;

    return (0);
}
