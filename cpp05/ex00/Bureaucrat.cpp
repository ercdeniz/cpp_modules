#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name)
{
    if (grade < MAX_GRADE)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > MIN_GRADE)
        throw Bureaucrat::GradeTooLowException();
    _grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &other) : _name(other._name)
{
    *this = other;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other)
{
	if (this == &other)
		return *this;
	if(other._grade < MAX_GRADE)
		throw Bureaucrat::GradeTooHighException();
	else if(other._grade > MIN_GRADE)
		throw Bureaucrat::GradeTooLowException();
	_grade = other._grade;
	return *this;
}

Bureaucrat::~Bureaucrat()
{
}

std::string Bureaucrat::getName() const
{
	return _name;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

void Bureaucrat::gradeUp()
{
	if (_grade - 1 < MAX_GRADE)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
}

void Bureaucrat::gradeDown()
{
	if (_grade + 1 > MIN_GRADE)
		throw Bureaucrat::GradeTooLowException();
	_grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return RED "Grade is too high!" RESET;
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return RED "Grade is too low!" RESET;
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat)
{
	out << I_BLUE << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << RESET;
	return out;
}