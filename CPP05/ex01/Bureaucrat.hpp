#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>

class Form;

class Bureaucrat {
    public:
        Bureaucrat();
        Bureaucrat(std::string sname, int sgrade);
        ~Bureaucrat(void);
        Bureaucrat(const Bureaucrat& src);
        Bureaucrat& operator=(const Bureaucrat& src);
        std::string getName() const;
        int getGrade() const;
        void getLowered();
        void getRaise();
        void signForm(Form &theform);

        class GradeTooHighException : public std::exception {
            public:
                virtual const char *what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                virtual const char *what() const throw();
        };

    private:
        const std::string   name;
        int                 grade;
        
};

std::ostream &operator<<(std::ostream& stream, const Bureaucrat& buro);

#endif