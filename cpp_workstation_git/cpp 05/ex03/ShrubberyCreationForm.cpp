#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery", 145, 137)
{
    this->target = "Default";
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& TRG) : AForm("Shrubbery", 145, 137), target(TRG)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copie)
{
    *this = copie;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

std::string ShrubberyCreationForm::getTarget() const
{
    return this->target;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copie)
{
    this->target = copie.target;
    return *this;
}

/* ---------------------- END ORTHODOX CANONICAL FORM ---------------------- */

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
    std::ofstream   file;
    std::string     name;

    this->checkExecutability(executor);
    name = target + "_shrubbery";
    file.open(name.c_str(), std::ofstream::out);

    std::string tree = 
              "      *\n"
               "     /|\\\n"
               "    / | \\\n"
              "   /  |  \\\n"
              "  /   |   \\\n"
               " /    |    \\\n"
             "/_____|_____\\\n"
                "     | |\n"
              "    -----      \n";
    if (!file)
    {
        std::cout << "error while creating file" << std::endl;
        return ;
    }
    file << tree;
    std::cout << "ShrubberyCreationForm executed successfully by " << executor.getName() << std::endl;
}