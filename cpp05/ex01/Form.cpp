#include "Bureaucrat.hpp"

Form::Form() : _name("Default Form"), _signed(false), _requiredToSign(150), _requiredToExecute(150) {}

Form::~Form(void) {}

Form::Form(std::string name): _name(name), _signed(false), _requiredToSign(150), _requiredToExecute(150) {}

Form::Form(std::string name, int reqGtoSign, int reqGtoExec) : _name(name), _signed(false), _requiredToSign(reqGtoSign), _requiredToExecute(reqGtoExec)
{
    if (reqGtoExec < 1 || reqGtoSign < 1)
        throw GradeTooHighException();
    else if (reqGtoExec > 150 || reqGtoSign > 150)
        throw GradeTooLowException();
}

Form::Form(const Form& copy) : _name(copy.getName()), _requiredToSign(getToSign()), _requiredToExecute(getToExec()) {
    *this = copy;
}

Form &Form::operator=(const Form& copy) {
    if (this == &copy)
        return *this;
    _signed = copy._signed;
    return *this;
}

std::string Form::getName(void) const {
    return _name;
}

int Form::getToSign(void) const {
    return _requiredToSign;
}

int Form::getToExec(void) const {
    return _requiredToExecute;
}

std::string Form::getIsSigned(void) const {
    if (_signed == false)
        return "false";
    return "true";
}

void Form::beSigned(Bureaucrat &b) {
    if (b.getGrade() <= this->getToSign())
        this->_signed = true;
    else
        throw Form::GradeTooLowException();
}

const char* Form::GradeTooHighException::what() const throw() {
    return "Form: Grade Too High";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Form: Grade Too Low";
}

std::ostream &operator<<(std::ostream& out, Form& form ) {
    out << I_BLUE <<  form.getName() << ", requried grade to sign: " << form.getToSign()
    << "\nrequired grade to execute: " <<form.getToExec()
    << "\nis signed: " <<  form.getIsSigned() << RESET << std::endl;
    return out;
}
