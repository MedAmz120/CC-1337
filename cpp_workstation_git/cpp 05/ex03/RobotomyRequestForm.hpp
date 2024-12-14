#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class Bureaucrat;

class RobotomyRequestForm : public AForm {
    private:
    std::string target;

    public:
    RobotomyRequestForm ();
    RobotomyRequestForm (const std::string& TRG);
    RobotomyRequestForm (const RobotomyRequestForm &copie);
    ~RobotomyRequestForm ();

    std::string getTarget() const;
    void    execute(Bureaucrat const & executor) const;
    RobotomyRequestForm &operator=(const RobotomyRequestForm &copie);
};


#endif