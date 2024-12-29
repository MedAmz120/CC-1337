/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 19:24:36 by moamzil           #+#    #+#             */
/*   Updated: 2024/12/17 19:24:37 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat	B_1("Jake", 20);
		Form		F_1("init", 15, 19);

		std::cout << F_1 << std::endl;
		B_1.signForm(F_1);
		std::cout << F_1 << std::endl;
	}
	catch (std::exception &exception)
	{
		std::cout << exception.what() << std::endl;
	}

	return 0;
}
