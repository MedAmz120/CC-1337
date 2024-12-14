#include "AForm.hpp"


/* ------------------------------- START ORTHODOX CANONICAL AForm  ---------------------------------*/

AForm::AForm() : name ("default") , gradeToSign (1), gradeToExec (1)
{
    std::cout << "Default constructor Called" << std::endl;
    is_signed = false;
}

AForm::AForm(const std::string& name_it, const int s_Grade, const int ex_Grade) : name(name_it), gradeToSign(s_Grade), gradeToExec(ex_Grade)
{
    std::cout << name << " AForm constructor called" << std::endl;
    is_signed = false;
    if (s_Grade < 1 || ex_Grade < 1)
        throw GradeTooHighException();
    else if (s_Grade > 150 || ex_Grade > 150)
        throw GradeTooLowException();
}

AForm& AForm::operator=(const AForm& copie)
{
    std::cout << "copy assignment operator called";
    this->is_signed = copie.is_signed;
    return *this;
}

AForm::AForm(const AForm &copie)  : name(copie.name), gradeToSign(copie.gradeToSign), gradeToExec(copie.gradeToExec)
{
    *this = copie;
    std::cout << "copy constructor called" << std::endl;
}

AForm::~AForm()
{
}

/* ------------------------------- END ORTHODOX CANONICAL AForm  ---------------------------------*/

void    AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() <= gradeToSign)
        is_signed = true;
    else
        throw GradeTooLowException ();
}

const char* AForm::GradeTooHighException::what() const throw ()
{
    return "Grade is too high exception";
}

const char* AForm::GradeTooLowException::what() const throw ()
{
    return "Grade is too low exception";
}

const char* AForm::InvalidFormException::what() const throw ()
{
    return "Unsigned forms cannot be executed";
}
/* -------------- START SETTERS AND GETTERS ------------ */

const std::string& AForm::getName()
{
    return this->name;
}

bool AForm::get_signed()
{
    return this->is_signed;
}
int AForm::getSigngrade()
{
    return this->gradeToSign;
}

int AForm::getExecgrade()
{
    return this->gradeToExec;
}

/* -------------- END SETTERS AND GETTERS ------------ */

std::ostream& operator<<(std::ostream& out, AForm& AForm)
{
    out << "AForm: " << AForm.getName();
    out << " Grade To Sign : " << AForm.getSigngrade();
    out << " Grade To Execute : " << AForm.getExecgrade();
    out << " Signed : " << ((AForm.get_signed()) ? "yes " : "No");

    return (out);
}

void    AForm::checkExecutability(const Bureaucrat& executor) const
{
    if (executor.getGrade() > gradeToExec)
        throw GradeTooLowException();
    if (!this->is_signed)
        throw InvalidFormException();
}