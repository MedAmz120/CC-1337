#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &other)
{
    *this = other;
}

Intern::~Intern() {}

Intern&	Intern::operator=(const Intern& other)
{
	(void)other;
	return (*this);
}

AForm *Intern::makeForm(const std::string& form_name, const std::string& target) const
{
	AForm	*new_form;

	t_form	data[] = 
	{
		{ "presidential pardon", new PresidentialPardonForm(target) },
		{ "robotomy request", new RobotomyRequestForm(target) },
		{ "shrubbery creation", new ShrubberyCreationForm(target) },
		{ "", NULL }
	};

	new_form = NULL;
	for (int i = 0; data[i].form != NULL; i++)
	{
		if (data[i].type == form_name)
			new_form = data[i].form;
		else
			delete data[i].form;
	}
	if (new_form == NULL)
		std::cout << "Form \'" << form_name << "\' does not exist "<< std::endl;
	else
		std::cout << "Intern creates " << form_name << std::endl;
	return new_form;
}