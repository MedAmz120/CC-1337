#include "Bureaucrat.hpp"

int main()
{
       try {
        Bureaucrat b1("John", 6);
        std::cout <<  "++++> " << b1 << std::endl;

        // Bureaucrat cpy(b1);

        // cpy = b1;

        // std::cout <<  "++++> /" << cpy << std::endl;

        // Bureaucrat cpy1(cpy);
        // std::cout <<  "++++> " << cpy1 << std::endl;

        // b1.incrementGrade();
        // std::cout << b1 << std::endl;

        // Bureaucrat b2("Alice", 1);
        // std::cout << b2 << std::endl;

        // b2.decrementGrade();
        // std::cout << b2 << std::endl;

        // // Uncommenting the line below will throw an exception
        // Bureaucrat b3("Bob", 5);

        // // Bureaucrat b2("Alice", 1);
        // std::cout << b3 << std::endl;

        // b3.decrementGrade();
        // std::cout << b3 << std::endl;
        // // Bureaucrat b4("ayache", 160);

    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}
