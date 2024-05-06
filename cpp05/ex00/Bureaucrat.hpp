#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

// COLORS
#define RESET   "\033[0m"
#define RED     "\033[1;31m"      /* Red */
#define GREEN   "\033[1;32m"      /* Green */
#define YELLOW  "\033[1;33m"      /* Yellow */
#define BLUE    "\033[1;34m"      /* Blue */
#define MAGENTA "\033[1;35m"      /* Magenta */
#define CYAN    "\033[1;36m"      /* Cyan */
#define I_BLUE  "\033[3;34m"    /* White */

// MACROS
#define MAX_GRADE 1
#define MIN_GRADE 150

#include <iostream>

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