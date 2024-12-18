/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 13:21:54 by moamzil           #+#    #+#             */
/*   Updated: 2024/12/17 19:17:51 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/* ------ ORTHODOX CANONICAL FORM ------ */

Bureaucrat::Bureaucrat() : name("Default")
{
    std::cout << "Default constructor Called For unowkn Bureaucrat" << std::endl;
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
    std::cout << this->name << " Bureaucrat has been Destroyed" << std::endl;
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
