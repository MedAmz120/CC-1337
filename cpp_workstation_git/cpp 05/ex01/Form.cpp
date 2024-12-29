/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 19:23:57 by moamzil           #+#    #+#             */
/*   Updated: 2024/12/17 19:23:59 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Form.hpp"


/* ------------------------------- START ORTHODOX CANONICAL FORM  ---------------------------------*/

Form::Form() : name ("default") , gradeToSign (1), gradeToExec (1)
{
    std::cout << "Default constructor Called" << std::endl;
    is_signed = false;
}

Form::Form(const std::string& name_it, const int s_Grade, const int ex_Grade) : name(name_it), gradeToSign(s_Grade), gradeToExec(ex_Grade)
{
    std::cout << name << " Form constructor called" << std::endl;
    is_signed = false;
    if (s_Grade < 1 || ex_Grade < 1)
        throw GradeTooHighException();
    else if (s_Grade > 150 || ex_Grade > 150)
        throw GradeTooLowException();
}

Form& Form::operator=(const Form& copie)
{
    std::cout << "copy assignment operator called";
    this->is_signed = copie.is_signed;
    return *this;
}

Form::Form(const Form &copie)  : name(copie.name), gradeToSign(copie.gradeToSign), gradeToExec(copie.gradeToExec)
{
    *this = copie;
    std::cout << "copy constructor called" << std::endl;
}

Form::~Form()
{
}

/* ------------------------------- END ORTHODOX CANONICAL FORM  ---------------------------------*/

void    Form::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() <= gradeToSign)
        is_signed = true;
    else
        throw GradeTooLowException ();
}

const char* Form::GradeTooHighException::what() const throw ()
{
    return "Grade is too high exception";
}

const char* Form::GradeTooLowException::what() const throw ()
{
    return "Grade is too low exception";
}

/* -------------- START SETTERS AND GETTERS ------------ */

const std::string& Form::getName()
{
    return this->name;
}

bool Form::get_signed()
{
    return this->is_signed;
}
int Form::getSigngrade()
{
    return this->gradeToSign;
}

int Form::getExecgrade()
{
    return this->gradeToExec;
}

/* -------------- END SETTERS AND GETTERS ------------ */

std::ostream& operator<<(std::ostream& out, Form& Form)
{
    out << "Form: " << Form.getName() << std::endl;
    out << " Grade To Sign : " << Form.getSigngrade() << std::endl;
    out << " Grade To Execute : " << Form.getExecgrade() << std::endl;
    out << " Signed : " << ((Form.get_signed()) ? "yes " : "No") << std::endl;

    return (out);
}
