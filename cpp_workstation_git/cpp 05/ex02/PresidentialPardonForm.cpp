#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5)
{
    this->target = "default";
}

PresidentialPardonForm::PresidentialPardonForm (const std::string& TRG) : AForm("PresidentialPardonForm", 25, 5)
{
    this->target = TRG;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copie)
{
    *this = copie;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &copie)
{
    this->target = copie.target;
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{}

std::string PresidentialPardonForm::getTarget() const
{
    return this->target;
}

void    PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	this->checkExecutability(executor);
	std::cout << this->target << " has been pardoned by Zafod Beeblebrox." << std::endl;	
}