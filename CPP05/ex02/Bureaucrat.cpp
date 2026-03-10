#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::~Bureaucrat(void)
{
    std::cout << "Bureaucrat destructor called" << std::endl; 
}

Bureaucrat::Bureaucrat() : name("Dispensable Bureaucrat"), grade(150) {
    std::cout << "Bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& src) : name(src.name), grade(src.grade) {
    std::cout << "Bureaucrat copy constructor called" << std::endl;
    if (this->grade > 150)
        throw Bureaucrat::GradeTooLowException();
    if (this->grade < 1)
        throw Bureaucrat::GradeTooHighException();
}

Bureaucrat::Bureaucrat(std::string sname, int sgrade) : name(sname), grade(sgrade) {
    std::cout << "Bureaucrat string and grade constructor called" << std::endl;
    if (this->grade > 150)
        throw Bureaucrat::GradeTooLowException();
    if (this->grade < 1)
        throw Bureaucrat::GradeTooHighException();
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& src) {
    std::cout << "Bureaucrat assign operator called" << std::endl;

    if (this != &src)
    {
        this->grade = src.grade;
    }
    return (*this);
}

std::string Bureaucrat::getName() const {
    return (this->name);
}

int Bureaucrat::getGrade() const {
    return (this->grade);
}

void Bureaucrat::getRaise() {
    if (this->grade <= 1)
        throw Bureaucrat::GradeTooHighException();
    else
        this->grade --;
}

void Bureaucrat::getLowered() {
    if (this->grade >= 150)
        throw Bureaucrat::GradeTooLowException();
    else
        this->grade ++;
}

void Bureaucrat::signForm(AForm &theform) {
    try
    {
        theform.beSigned(*this);
        std::cout << *this << " signed " << theform << "." << std::endl;
    }
    catch(const std::exception& error)
    {
        std::cout << *this << " couldn't sign " << theform << " because " << error.what() << "." << std::endl;
    }
    
}

void Bureaucrat::executeForm(AForm const & form) {
    try
    {
       form.execute(*this);
        std::cout << *this << " executed " << form << "." << std::endl;
    }
    catch(const std::exception& error)
    {
        std::cout << *this << " couldn't execute " << form << " because " << error.what() << "." << std::endl;
    }
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
    return ("Bureaucrat: Grade too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
    return ("Bureaucrat: Grade too low");
}

std::ostream &operator<<(std::ostream& os, const Bureaucrat& buro)
{
    os << buro.getName() << ", bureaucrat grade " << buro.getGrade();
    return (os);
}
