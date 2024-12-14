#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat {
    private:
    const std::string name;
    int     grade;
    
    public:
    Bureaucrat();
    Bureaucrat(const Bureaucrat &copie);
    Bureaucrat(const std::string& name_it, int grade_it);
    ~Bureaucrat();

    const std::string getName() const;
    int     getGrade() const;
    void    incrementGrade();
    void    decrementGrade();

    // Exception Classes

    class GradeTooHighException : public std::exception {
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
        virtual const char* what() const throw();
    };

    Bureaucrat& operator=(const Bureaucrat& copie);
    void    signForm(Form &form);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif