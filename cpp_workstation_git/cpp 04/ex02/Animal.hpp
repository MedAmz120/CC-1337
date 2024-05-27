/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:01:40 by moamzil           #+#    #+#             */
/*   Updated: 2024/05/20 11:55:35 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal {
    protected:
    std::string type;
    
    public:
    Animal();
    Animal(std::string& type);
    Animal(const Animal& copie);
    Animal& operator=(const Animal& copie);
    virtual ~Animal();
    virtual void makeSound() const = 0;
    virtual std::string getType() const;    
};

#endif