#pragma once

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
    public:
        Intern(void);
        Intern(const Intern& copy);
        Intern &operator=(const Intern& copy);
        ~Intern(void);
        AForm* makeForm(std::string name, std::string target);
        AForm* makePresidentialPardon(std::string target);
        AForm* makeRobotomyRequest(std::string target);
        AForm* makeShrubberyCreation(std::string target);
        class FormNotFoundException: public std::exception {
            const char* what() const throw();
        };
};