#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
    private:
    typedef struct	s_form
    {
		std::string	type;
		AForm		*form;
	}		t_form;
    public:
    Intern ();
    Intern (const Intern &copie);
    Intern &operator=(const Intern &copie);
    ~Intern();

    AForm *makeForm(const std::string& form_name, const std::string& target) const;
};

#endif