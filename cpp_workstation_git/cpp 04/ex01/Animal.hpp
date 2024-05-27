/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:01:40 by moamzil           #+#    #+#             */
/*   Updated: 2024/05/20 12:30:04 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal {
    protected:
    std::string type;
    
    public:
    Animal(); // constructor (default)
    Animal(std::string& type); // constructor 2 with parameter
    Animal(const Animal& copie); // copy constructor
    Animal& operator=(const Animal& copie); // copy assignement operator
    virtual ~Animal(); /* destructor (virtual cause we are dynamically creating our object so we make sure 
    all destructor are called properly for good memory resources cleanup) */
    virtual void makeSound() const;
    virtual std::string getType() const;    // return the animal type
};

#endif