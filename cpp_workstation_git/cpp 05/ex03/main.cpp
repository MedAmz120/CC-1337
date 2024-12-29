#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	Intern	intern;
	AForm	*test;

	test = intern.makeForm("shrubbery creation", "jake");
	std::cout << *test << std::endl;
	std::cout << std::endl;


	// test = intern.makeForm("robotomy request", "paul");
	// std::cout << *test << std::endl;
	// std::cout << std::endl;

	// test = intern.makeForm("presidential pardon", "david");
	// std::cout << *test << std::endl;
	// std::cout << std::endl;
	
	// test = intern.makeForm("undefined", "0U");
	delete test;

	return 0;
}
