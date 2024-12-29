/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 19:24:29 by moamzil           #+#    #+#             */
/*   Updated: 2024/12/17 19:24:34 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
    private:
    const std::string name;
    bool  is_signed;
    const int gradeToSign;
    const int gradeToExec;

    public:
    Form();
    Form(const std::string& name_it, const int s_Grade, const int ex_Grade);
    Form(const Form &copie);
    ~Form();
    Form& operator=(const Form& copie);


    class GradeTooHighException : public std::exception {
        virtual const char* what() const throw();
    };
    
    class GradeTooLowException : public std::exception {
        virtual const char* what() const throw();
    };

    void    beSigned(const Bureaucrat &bureaucrat); // sign the form
    const   std::string& getName();
    bool    get_signed(); // signed or not
    int getSigngrade();
    int getExecgrade();
};

std::ostream& operator<<(std::ostream& out, Form& Form);

#endif