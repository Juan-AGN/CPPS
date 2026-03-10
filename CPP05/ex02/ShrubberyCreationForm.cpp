#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
    std::cout << "ShrubberyCreationForm destructor called" << std::endl; 
}

ShrubberyCreationForm::ShrubberyCreationForm() : AForm::AForm("ShrubberyCreationForm", 145, 137), target("Void") {
    std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src) : AForm::AForm(src.getName(), src.getGradeSign(), src.getGradeExec()),  target(src.target) {
    std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string starget) : AForm::AForm("ShrubberyCreationForm", 145, 137), target(starget) {
    std::cout << "ShrubberyCreationForm string and grade constructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src) {
    std::cout << "ShrubberyCreationForm assign operator called" << std::endl;

    if (this != &src)
        this->target = src.target;
    return (*this);
}

std::string ShrubberyCreationForm::getTarget() const {
    return (this->target);
}

std::ostream &operator<<(std::ostream& os, const ShrubberyCreationForm& theform)
{
    os << theform.getName() << ", grade to sign " << theform.getGradeSign() << ", grade to exec " << theform.getGradeExec() << ", target " << theform.getTarget() << ", is signed: " << theform.getIsSigned();
    return (os);
}

void ShrubberyCreationForm::beExecuted() const {
    std::ofstream outFile((this->getTarget() + "_shrubbery").c_str());
	if (!outFile.is_open())
        throw ShrubberyCreationForm::OutfileFailException();
    outFile << "     /    (      0  )   \\      \n   (  0  (  1        )0    )   \n   (  0 (  11   0    ) 0   )   \n   (  0  (  1        )0    )   \n        \\ (  1  0   )/ //      \n             |     |  //       \n             |     | //        \n             |   0 |//         \n             |     |/          \n             |     |           \n             |     |           \n             |o    |           \n             |     |           \n            /       \\          \n";
    outFile.close();
}

const char *ShrubberyCreationForm::OutfileFailException::what() const throw() {
    return ("ShrubberyCreationForm: Failed to open file");
}