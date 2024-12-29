#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    try {
        Bureaucrat bureaucrat("Jake", 23);
        std::cout << bureaucrat << std::endl;

        int input = 0;
        while (input != 4) {
            std::cout << "------- Menu -------" << std::endl;
            std::cout << "1. ShrubberyCreationForm" << std::endl;
            std::cout << "2. RobotomyRequestForm" << std::endl;
            std::cout << "3. PresidentialPardonForm" << std::endl;
            std::cout << "4. Exit" << std::endl;
            std::cout << "---> ";
            std::cin >> input;

            switch(input) {
                case 1: // ShrubberyCreationForm
                {
                    ShrubberyCreationForm shrubberyForm("Shrubbery_1");
                    std::cout << "-->" << shrubberyForm << std::endl;
                    bureaucrat.signForm(shrubberyForm);
                    shrubberyForm.execute(bureaucrat);
                    std::cout << "-->" << shrubberyForm << std::endl;
                    break;
                }
                case 2: // RobotomyRequestForm
                {
                    RobotomyRequestForm robotomyForm("Roboto_1");
                    std::cout << "-->" << robotomyForm  << std::endl;
                    bureaucrat.signForm(robotomyForm);
                    robotomyForm.execute(bureaucrat);
                    std::cout << "-->" << robotomyForm  << std::endl;
                    break;
                }
                case 3: // PresidentialPardonForm
                {
                    PresidentialPardonForm pardonForm("President_1");
                    std::cout << "-->" << pardonForm << std::endl;
                	bureaucrat.signForm(pardonForm);
                    pardonForm.execute(bureaucrat);
                    std::cout << "-->" << pardonForm << std::endl;
                    break;
                }
                case 4: // Exit
                    std::cout << "Exiting program..." << std::endl;
                    break;
                default:
                    std::cerr << "Invalid input, please try again." << std::endl;
            }
        }
    } catch (std::exception const & exception) {
        std::cerr << "Error: " << exception.what() << std::endl;
    }

}
