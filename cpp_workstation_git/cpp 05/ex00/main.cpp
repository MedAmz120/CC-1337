/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 19:22:48 by moamzil           #+#    #+#             */
/*   Updated: 2024/12/17 19:23:01 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    try {
        Bureaucrat b1("John", 150);
        std::cout << b1 << std::endl;
        b1.incrementGrade();
        std::cout << b1.getName() << " grade is " << b1.getGrade() << std::endl;
        b1.decrementGrade();
        std::cout << b1.getName() << " grade is " << b1.getGrade() << std::endl;

        Bureaucrat  b2("Jake", 1);
        std::cout << b2 << std::endl;
        //b2.incrementGrade();
        b2.decrementGrade();
        std::cout << b2.getName() << " grade is " << b2.getGrade() << std::endl;

        Bureaucrat b3;
        b3 = b2;
        std::cout << b3 << std::endl;
    } catch (std::exception& exception) {
        std::cerr << "Exception: " << exception.what() << std::endl;
    }
}
