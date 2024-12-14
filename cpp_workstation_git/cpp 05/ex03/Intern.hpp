#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
    public:
    Intern ();
    Intern (const Intern &copie);
    Intern &operator=(const Intern &copie);
    ~Intern();

    AForm *CreatePresidentialPardonForm(std::string target);
    AForm *CreateShrubberyCreationForm(std::string target);
    AForm *CreateRobotmyRequestForm(std::string target);
    AForm *makeForm(std::string form_name, std::string target);
};

#endif