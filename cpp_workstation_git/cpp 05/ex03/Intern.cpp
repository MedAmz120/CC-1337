#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &other)
{
    *this = other;
}

AForm *Intern::CreateShrubberyCreationForm(std::string target)
{
    return (new ShrubberyCreationForm(target));
}

AForm *Intern::CreateRobotmyRequestForm(std::string target)
{
    return (new RobotomyRequestForm(target));
}

AForm *Intern::CreatePresidentialPardonForm(std::string target)
{
    return (new PresidentialPardonForm(target));
}

AForm *Intern::makeForm(std::string form_name, std::string target)
{
    std::string rry;
}