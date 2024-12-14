#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public AForm {
    private:
    std::string     target;

    public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(const std::string& TRG);
    ShrubberyCreationForm(const ShrubberyCreationForm &copie);
    ~ShrubberyCreationForm();

    std::string getTarget() const;
    void execute(Bureaucrat const & executor) const;
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &copie);
};

#endif