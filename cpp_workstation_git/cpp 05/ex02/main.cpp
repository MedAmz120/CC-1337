#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#define ORANGE_TEXT "\033[38;5;208m"
#define RED_TEXT "\033[38;5;196m"
#define YELLOW_TEXT "\033[38;5;226m"
#define BLUE_TEXT "\033[38;5;27m"
#define RESET_TEXT "\033[0m"

int main()
{
    try {
        Bureaucrat bureaucrat("John", 25);
        std::cout << ORANGE_TEXT << "-->" << bureaucrat << RESET_TEXT << std::endl;

        int choice = 0;
        while (choice != 4) {
            std::cout << "------- Menu -------" << std::endl;
            std::cout << "1. ShrubberyCreationForm" << std::endl;
            std::cout << "2. RobotomyRequestForm" << std::endl;
            std::cout << "3. PresidentialPardonForm" << std::endl;
            std::cout << "4. Exit" << std::endl;
            std::cout << "Enter your choice: ";
            std::cin >> choice;

            switch(choice) {
                case 1: // ShrubberyCreationForm
                {
                    ShrubberyCreationForm shrubberyForm("me");
                    std::cout << BLUE_TEXT << "-->" << shrubberyForm << RESET_TEXT << std::endl;
                    bureaucrat.signForm(shrubberyForm);
                    shrubberyForm.execute(bureaucrat);
                    std::cout << BLUE_TEXT << "-->" << shrubberyForm << RESET_TEXT << std::endl;
                    break;
                }
                case 2: // RobotomyRequestForm
                {
                    RobotomyRequestForm robotomyForm("yassine");
                    std::cout << RED_TEXT << "-->" << robotomyForm << RESET_TEXT  << std::endl;
                    bureaucrat.signForm(robotomyForm);
                    robotomyForm.execute(bureaucrat);
                    std::cout << RED_TEXT << "-->" << robotomyForm << RESET_TEXT  << std::endl;
                    break;
                }
                case 3: // PresidentialPardonForm
                {
                    PresidentialPardonForm pardonForm("sma7lia");
                    std::cout << YELLOW_TEXT << "-->" << pardonForm << RESET_TEXT << std::endl;
                	bureaucrat.signForm(pardonForm);
                    pardonForm.execute(bureaucrat);
                    std::cout << YELLOW_TEXT << "-->" << pardonForm << RESET_TEXT << std::endl;
                    break;
                }
                case 4: // Exit
                    std::cout << "Exiting program..." << std::endl;
                    break;
                default:
                    std::cerr << "Invalid choice, please try again." << std::endl;
            }
        }
    } catch (std::exception const & e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

}
