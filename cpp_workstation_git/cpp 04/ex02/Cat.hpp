/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 09:51:37 by moamzil           #+#    #+#             */
/*   Updated: 2024/05/19 15:27:45 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
    public:
    Cat();
    Cat(std::string type);
    Cat(const Cat& copie);
    Cat& operator=(const Cat& copie);
    ~Cat();
    void makeSound() const;
    std::string getType() const;
    
    private:
    Brain* cat_brain;
};

#endif