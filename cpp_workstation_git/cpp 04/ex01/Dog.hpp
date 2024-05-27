/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:59:31 by moamzil           #+#    #+#             */
/*   Updated: 2024/05/19 15:28:01 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
    public:
    Dog();
    Dog(std::string type);
    Dog(const Dog& copie);
    Dog& operator=(const Dog& copie);
    ~Dog();
    void makeSound() const;
    std::string getType() const;
    
    private:
    Brain* dog_brain;
};

#endif