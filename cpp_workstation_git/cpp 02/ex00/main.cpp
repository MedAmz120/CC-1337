/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 13:16:04 by moamzil           #+#    #+#             */
/*   Updated: 2024/05/06 13:37:32 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {
    Fixed a; // new object instance
    Fixed b( a ); // Copy Constructor create an exact duplicate instance of a object
    Fixed c; //Fixed c; // new object instance of type Fixed
    //use the copy assignment operator to perform the update. 
    //This ensures that a reflects the latest state from b.

    c = b;
    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;
    return 0;
}
