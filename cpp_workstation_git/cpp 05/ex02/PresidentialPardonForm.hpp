#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm {
    private:
    std::string target;

    public:
    PresidentialPardonForm ();
    PresidentialPardonForm (const std::string& TRG);
    PresidentialPardonForm (const PresidentialPardonForm &copie);
    ~PresidentialPardonForm ();

    std::string getTarget() const;
    PresidentialPardonForm &operator=(const PresidentialPardonForm &copie);
    void    execute(Bureaucrat const & executor) const;

};




#endif