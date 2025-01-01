/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 16:01:12 by moamzil           #+#    #+#             */
/*   Updated: 2025/01/01 14:20:53 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <ctype.h>
#include <iomanip>

class ScalarConverter {
    public:
    ScalarConverter();
    ~ScalarConverter();
    ScalarConverter(const ScalarConverter &copie);
    
    static void    convert(const std::string& str);
    static void    convertToChar(const std::string& str);
    static bool    convertToInt(const std::string& str);
    static void    convertToFloat();
    static void    convertToDouble();
};

#endif