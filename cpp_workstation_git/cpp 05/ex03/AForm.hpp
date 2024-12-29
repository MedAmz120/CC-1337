#ifndef AForm_HPP
#define AForm_HPP

#include <iostream>
#include <fstream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
    private:
    const std::string name;
    bool  is_signed;
    const int gradeToSign;
    const int gradeToExec;

    public:
    AForm();
    AForm(const std::string& name_it, const int s_Grade, const int ex_Grade);
    AForm(const AForm &copie);
    virtual ~AForm();
    AForm& operator=(const AForm& copie);


    class GradeTooHighException : public std::exception {
        virtual const char* what() const throw();
    };
    
    class GradeTooLowException : public std::exception {
        virtual const char* what() const throw();
    };

    class InvalidFormException : public std::exception {
        virtual const char* what() const throw();
    };

    void    beSigned(const Bureaucrat &bureaucrat);
    const   std::string& getName();
    bool get_signed();
    int getSigngrade();
    int getExecgrade();
    virtual void execute(const Bureaucrat& executor) const = 0;
    void    checkExecutability(const Bureaucrat& executor) const;
};

std::ostream& operator<<(std::ostream& out, AForm& AForm);

#endif