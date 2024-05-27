/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 10:32:22 by moamzil           #+#    #+#             */
/*   Updated: 2024/05/21 16:21:07 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Brain.hpp"
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    int n = 10;
    const Animal* arr[n];
    // const Animal* arrcopy[n];
    
    for (int c = 0; c < n / 2; c++)
        arr[c] = new Dog();
        
    for (int c = n / 2; c < n; c++)
        arr[c] = new Cat();

    // for (int c = 0; c < n; c++)
    //     arrcopy[c] = new Animal(*arr[c]);
    
    for (int c = 0; c < n; c++)
        delete arr[c];
        
    Dog basic;
    {
        Dog tmp = basic;
    }
    
    system("leaks -q Animal");
    return 0;
}
