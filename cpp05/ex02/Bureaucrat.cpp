#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("Default"), _grade(150) {}

Bureaucrat::~Bureaucrat(void) {}

Bureaucrat::Bureaucrat(std::string name) : _name(name), _grade(150) {}

Bureaucrat::Bureaucrat(std::string name, size_t grade) : _name(name) {
    setGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy) : _name(copy.getName()) {
    *this = copy;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat& copy) {
    if (this == &copy)
        return *this;
    _grade = copy._grade;
    return *this;
}

std::string Bureaucrat::getName(void) const {
    return this->_name;
}

size_t Bureaucrat::getGrade(void) const {
    return this->_grade;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Bureaucrat: Grade Too High";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Bureaucrat: Grade Too Low";
}

void Bureaucrat::signAForm(AForm& f) {
    try {
        f.beSigned(*this);
        std::cout << this->getName() << " signed " << f.getName() << std::endl;
    } catch (std::exception &e) {
        std::cout << this->getName() << " couldn't sign " << f.getName() << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const & form) {
    try {
        form.execute(*this);
    } catch (std::exception &e) {
        std::cout << _name << " ,couldn't execute form becauese " << e.what() << std::endl;
    }
}

void Bureaucrat::increaseGrade(void) {
    setGrade(getGrade() - 1);
}

void Bureaucrat::decreaseGrade(void) {
    setGrade(getGrade() + 1);
}

void Bureaucrat::setGrade(int n) {
    if (n < 1)
        throw GradeTooHighException();
    else if (n > 150)
        throw GradeTooLowException();
    _grade = n;
}

std::ostream& operator<<(std::ostream& o, const Bureaucrat& b) {
    o << b.getName() << ", bureaucrat grade " << b.getGrade();
    return o;
}
