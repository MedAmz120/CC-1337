/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 13:29:21 by moamzil           #+#    #+#             */
/*   Updated: 2024/05/19 15:40:23 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain Default Constructor called" << std::endl;
}

Brain::~Brain()
{
    std::cout << "Brain destructor Called" << std::endl;
}

Brain::Brain(const Brain& copie)
{
    std::cout << "Brain copy constructor called" << std::endl;
    *this = copie;
}

// Brain& Brain::operator=(const Brain& copie)
// {
//     std::cout << "Brain copy assignment operator called" << std::endl;
// }