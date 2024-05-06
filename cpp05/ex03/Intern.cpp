#include "Intern.hpp"

Intern::Intern(void) {}

Intern::Intern(const Intern& copy) {
    *this = copy;
}

Intern &Intern::operator=(const Intern& copy) {
    (void)copy;
    return *this;
}

Intern::~Intern(void) {}

const char* Intern::FormNotFoundException::what() const throw() {
    return RED "Intern: Form Not Found" RESET;
}

AForm *Intern::makePresidentialPardon(std::string target) {
    std::cout << CYAN  << "Intern creates " << CYAN"Presidential Pardon" << RESET"Form"  << std::endl;
    return new PresidentialPardonForm(target);
}

AForm *Intern::makeRobotomyRequest(std::string target) {
    std::cout << "Intern creates " << CYAN"Robotomy Request" << RESET" Form" << std::endl;
    return new RobotomyRequestForm(target);
}

AForm *Intern::makeShrubberyCreation(std::string target) {
    std::cout << "Intern creates " << CYAN"Shrubbery Creation" << RESET" Form" << std::endl;
    return new ShrubberyCreationForm(target);
}

AForm *Intern::makeForm(std::string name, std::string target) {
    int i = 0;

    std::string names[3] = {
        "presidential pardon",
        "robotomy request",
        "shrubbery creation"
    };

    for (; i < 3; ++i) 
        if (names[i] == name)
            break;

    switch (i) {
        case 0:
            return makePresidentialPardon(target);
        case 1:
            return makeRobotomyRequest(target);
        case 2:
            return makeShrubberyCreation(target);
        default:
            std::cout << MAGENTA "Available forms:" RESET << std::endl;
            for (int j = 0; j < 3; ++j)
                std::cout << "  " + names[j] << std::endl;
            throw Intern::FormNotFoundException();
    }
}
