#pragma once

// COLORS
#define RESET   "\033[0m"
#define RED     "\033[1;31m"      /* Red */
#define GREEN   "\033[1;32m"      /* Green */
#define YELLOW  "\033[1;33m"      /* Yellow */
#define BLUE    "\033[1;34m"      /* Blue */
#define MAGENTA "\033[1;35m"      /* Magenta */
#define CYAN    "\033[1;36m"      /* Cyan */
#define I_BLUE  "\033[3;34m"    /* White */

// includes
#include <exception>
#include <iostream>

class Bureaucrat;

class AForm
{
private:
    const std::string _name;
    bool _isSigned;
    const size_t _requiredGradeToSign;
    const size_t _requiredGradeToExecute;

public:
    AForm(void);
    virtual ~AForm(void);
    AForm(std::string name);
    AForm(std::string name, int requiredGradeToSign, int requiredGradeToExecute);
    AForm(const AForm &copy);
    AForm &operator=(const AForm &copy);
    std::string getName(void) const;
    size_t getGradeToSign(void) const;
    size_t getGradeToExec(void) const;
    std::string getIsSigned(void) const;
    void beSigned(Bureaucrat &b);
    void execute(const Bureaucrat &executor) const;
    virtual void specificExecute(void) const = 0;
    class GradeTooHighException : public std::exception
    {
        const char *what() const throw();
    };
    class GradeTooLowException : public std::exception
    {
        const char *what() const throw();
    };
    class FormNotSignedException : public std::exception
    {
        const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &o, AForm &f);