/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 16:14:43 by moamzil           #+#    #+#             */
/*   Updated: 2024/12/31 16:14:47 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main() {
    Base* basePtr = generate();
    Base &baseReference = *basePtr;
    identify(basePtr);
    identify(baseReference);
    delete basePtr;
    return 0;
}