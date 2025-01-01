/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 16:06:06 by moamzil           #+#    #+#             */
/*   Updated: 2024/12/31 16:13:32 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main() {
    Data* ptr = NULL;
    Data* new_ptr = NULL;
    uintptr_t raw;

    ptr = new Data;
    ptr->str = "Lorem ipsum";

    raw = Serializer::serialize(ptr);    
    std::cout << "raw = " << raw << std::endl;
    new_ptr = Serializer::deserialize(raw);
    
    std::cout << "Data from origin ptr: " << ptr->str << std::endl;
    std::cout << "Data from serialized new_ptr: " << new_ptr->str << std::endl;

    delete ptr;
    return 0;
}