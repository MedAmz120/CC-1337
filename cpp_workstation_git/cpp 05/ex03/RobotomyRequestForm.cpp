#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45)
{
    target = "Default";
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& TRG) : AForm("RobotomyRequestForm", 72, 45) , target(TRG)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copie)
{
    *this = copie;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

std::string RobotomyRequestForm::getTarget() const {
    return this->target;
}

void    RobotomyRequestForm::execute(Bureaucrat const & executor) const {
    this->checkExecutability(executor);
    std::cout << "Occurrence of some drilling noises" << std::endl;
    srand(time(0));
    if (rand() % 2 == 0)
        std::cout << this->target << " has been robotomized successfully 50% of the time" << std::endl;
    else
        std::cout << "The robotomy failed" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copie)
{
    this->target = copie.target;
    return *this;
}