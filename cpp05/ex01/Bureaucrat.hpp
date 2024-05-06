#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

// MACROS
#define MAX_GRADE 1
#define MIN_GRADE 150

#include "Form.hpp"

class Bureaucrat
{
    private:
        std::string const _name;
        int _grade;
    public:
        Bureaucrat(std::string const name, int grade);
        Bureaucrat(Bureaucrat const &other);
        Bureaucrat &operator=(Bureaucrat const &other);
        ~Bureaucrat();

        std::string getName() const;
        int getGrade() const;

        void gradeUp();
        void gradeDown();
        void signForm(Form& form);

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat);

#endif // BUREAUCRAT_HPP