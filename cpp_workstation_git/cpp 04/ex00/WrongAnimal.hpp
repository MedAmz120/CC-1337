/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:01:40 by moamzil           #+#    #+#             */
/*   Updated: 2024/05/20 12:53:58 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal {
    protected:
    std::string type;
    
    public:
    WrongAnimal();
    WrongAnimal(std::string& type);
    WrongAnimal(const WrongAnimal& copie);
    WrongAnimal& operator=(const WrongAnimal& copie);
    ~WrongAnimal();
    void makeSound() const;
    std::string getType() const;    
};

#endif