/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 13:29:21 by moamzil           #+#    #+#             */
/*   Updated: 2024/05/21 15:14:53 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Dexter made a Brain for an Animal (CONSTRUCTOR)" << std::endl;
}

Brain::~Brain()
{
    std::cout << "Dexter Has failed Brain is destroyed (DESTRUCTOR)" << std::endl;
}

Brain::Brain(const Brain& copie)
{
    std::cout << "Brain copy constructor called" << std::endl;
    *this = copie;
}

Brain& Brain::operator=(const Brain& copie)
{
    std::cout << "Brain copy assignment operator called" << std::endl;
    if (this != &copie)
        for (int i = 0; i < 100; i++)
            this->ideas[i] = copie.ideas[i];
    return *this;
}