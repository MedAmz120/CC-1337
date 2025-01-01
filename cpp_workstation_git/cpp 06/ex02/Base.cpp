/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 14:22:53 by moamzil           #+#    #+#             */
/*   Updated: 2025/01/01 14:22:57 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void) {
    srand(time(0));
    int randomValue = rand() % 3;

    if (randomValue == 0) {
        return new A();
    } else if (randomValue == 1) {
        return new B();
    } else {
        return new C();
    }
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p)) {
        std::cout << "A" << std::endl;
    } else if (dynamic_cast<B*>(p)) {
        std::cout << "B" << std::endl;
    } else if (dynamic_cast<C*>(p)) {
        std::cout << "C" << std::endl;
    } else {
        std::cout << "Unknown type" << std::endl;
    }
}

void identify(Base& p) {
    try {
        A& a = dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        (void)a;
        return;
    } catch (std::bad_cast&) {
        // Not an A
    }

    try {
        B& b = dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        (void)b;
        return;
    } catch (std::bad_cast&) {
        // Not a B
    }

    try {
        C& c = dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        (void)c;
        return;
    } catch (std::bad_cast&) {
        // Not a C
    }

    std::cout << "Unknown type" << std::endl;
}

Base::~Base() {};
