#pragma once

// COLORS
#define RESET   "\033[0m"
#define RED     "\033[1;31m"        /* Red */
#define GREEN   "\033[1;32m"        /* Green */
#define YELLOW  "\033[1;33m"        /* Yellow */
#define BLUE    "\033[1;34m"        /* Blue */
#define MAGENTA "\033[1;35m"        /* Magenta */
#define CYAN    "\033[1;36m"        /* Cyan */
#define I_BLUE  "\033[3;34m"        /* White */

#include <exception>
#include <iostream>

class Bureaucrat;

class Form {
    private:
        const std::string _name;
        bool _signed;
        const int _requiredToSign;
        const int _requiredToExecute;
    public:
        Form(void);
        ~Form(void);
        Form(std::string name);
        Form(std::string name, int requiredToSign, int requiredToExecute);
        Form(const Form& copy);
        Form &operator=(const Form& copy);
        std::string getName(void) const;
        int getToSign(void) const;
        int getToExec(void) const;
        std::string getIsSigned(void) const;
        void beSigned(Bureaucrat& b);
        class GradeTooHighException: public std::exception {
            const char* what() const throw();
        };
        class GradeTooLowException: public std::exception {
            const char* what() const throw();
        };
};
std::ostream &operator<<(std::ostream& out, Form& form);
