/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 14:23:05 by moamzil           #+#    #+#             */
/*   Updated: 2025/01/01 14:23:10 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

#include <random>
#include <iostream>


class Base {
    public:
    virtual ~Base() = 0;
};

Base * generate(void);
void identify(Base* p);
void identify(Base& p);

#endif