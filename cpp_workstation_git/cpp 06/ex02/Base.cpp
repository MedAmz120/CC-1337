#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void) {
    srand(time(0));
    int randomValue = rand() % 3; // Generate a random number between 0 and 2

    if (randomValue == 0) {
        return new A(); // Create and return an instance of A
    } else if (randomValue == 1) {
        return new B(); // Create and return an instance of B
    } else {
        return new C(); // Create and return an instance of C
    }
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p)) {
        std::cout << "A" << std::endl; // If p is of type A
    } else if (dynamic_cast<B*>(p)) {
        std::cout << "B" << std::endl; // If p is of type B
    } else if (dynamic_cast<C*>(p)) {
        std::cout << "C" << std::endl; // If p is of type C
    } else {
        std::cout << "Unknown type" << std::endl; // Fallback for safety
    }
}

void identify(Base& p) {
    try {
        A& a = dynamic_cast<A&>(p); // Attempt to cast to A
        std::cout << "A" << std::endl; // If successful
        (void)a;
        return;
    } catch (std::bad_cast&) {
        // Not an A
    }

    try {
        B& b = dynamic_cast<B&>(p); // Attempt to cast to B
        std::cout << "B" << std::endl; // If successful
        (void)b;
        return;
    } catch (std::bad_cast&) {
        // Not a B
    }

    try {
        C& c = dynamic_cast<C&>(p); // Attempt to cast to C
        std::cout << "C" << std::endl; // If successful
        (void)c;
        return;
    } catch (std::bad_cast&) {
        // Not a C
    }

    std::cout << "Unknown type" << std::endl; // Fallback for safety
}

Base::~Base() {};
