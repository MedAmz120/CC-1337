#include "Bureaucrat.hpp"

/* ------ ORTHODOX CANONICAL FORM ------ */

Bureaucrat::Bureaucrat() : name("Default")
{
    std::cout << "Default constructor Called" << std::endl;
    this->grade = 150;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copie)
{
    *this = copie;
    std::cout << "Copy constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name_it, int grade_it) : name(name_it)
{
    std::cout << "Bureaucrat " + name + " intiated" << std::endl;
    if (grade_it < 1)
        throw GradeTooHighException();
    else if (grade_it > 150)
        throw GradeTooLowException();
    else
        this->grade = grade_it;

}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat has been Destroyed" << std::endl;
}


/* --------------------------------------- */


Bureaucrat& Bureaucrat::operator=(const Bureaucrat& copie)
{
    std::cout << "Copy Assignment operator Called" << std::endl;
    this->grade = copie.grade;
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& Bureaucrat)
{
    os << Bureaucrat.getName() << ", Bureaucrat grade " << Bureaucrat.getGrade();
    return os;
}

/* --------------------------------------- */

int Bureaucrat::getGrade() const {
    return this->grade;
}

const std::string Bureaucrat::getName() const {
    return this->name;
}

const char* Bureaucrat::GradeTooHighException::what() const throw ()
{
    return "Grade is to high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw ()
{
    return "Grade is to low";
}

void    Bureaucrat::incrementGrade()
{
    if (grade > 1)
        grade--;
    else
        throw GradeTooHighException();
}

void    Bureaucrat::decrementGrade()
{
    if (grade < 150)
        grade++;
    else
        throw GradeTooLowException();
}

void    Bureaucrat::signForm(AForm &form)
{
    try {
        form.beSigned(*this);
        std::cout << name << " signed " << form.getName() << "." << std::endl;
    }
    catch (std::exception& e){
        std::cout << name << " couldn't sign " << form.getName() << " because " << e.what() << "." << std::endl; 
    }

}