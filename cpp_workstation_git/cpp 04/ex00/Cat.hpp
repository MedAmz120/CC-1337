/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 09:51:37 by moamzil           #+#    #+#             */
/*   Updated: 2024/05/20 12:34:21 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal {
    public:
    Cat(); // constructor (default)
    Cat(std::string type); // constructor 2
    Cat(const Cat& copie); // copy constructor (CPconstructor)
    Cat& operator=(const Cat& copie); // copy assignment operator (cpaop)
    ~Cat(); // Destructor (DEST)

    void        makeSound() const;
    std::string getType()   const;
};

#endif