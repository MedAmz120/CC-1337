/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:59:31 by moamzil           #+#    #+#             */
/*   Updated: 2024/05/20 12:35:57 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal {
    public:
    Dog();
    Dog(std::string type);
    Dog(const Dog& copie);
    Dog& operator=(const Dog& copie);
    ~Dog();

    void        makeSound() const;
    std::string getType()   const;
};

#endif