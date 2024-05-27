/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 09:51:37 by moamzil           #+#    #+#             */
/*   Updated: 2024/05/19 11:55:06 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
    public:
    WrongCat();
    WrongCat(std::string type);
    WrongCat(const WrongCat& copie);
    WrongCat& operator=(const WrongCat& copie);
    ~WrongCat();
    void makeSound() const;
    std::string getType() const;
};

#endif