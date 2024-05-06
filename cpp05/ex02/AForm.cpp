#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("Default AForm"),
                 _isSigned(false),
                 _requiredGradeToSign(150),
                 _requiredGradeToExecute(150) {}

AForm::~AForm(void) {}

AForm::AForm(std::string name) : _name(name),
                                 _isSigned(false),
                                 _requiredGradeToSign(150),
                                 _requiredGradeToExecute(150) {}

AForm::AForm(std::string name, int reqGtoSign, int reqGtoExec) : _name(name),
                                                                 _isSigned(false),
                                                                 _requiredGradeToSign(reqGtoSign),
                                                                 _requiredGradeToExecute(reqGtoExec)
{
    if (reqGtoExec < 1 || reqGtoSign < 1)
        throw GradeTooHighException();
    else if (reqGtoExec > 150 || reqGtoSign > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm &copy) : _name(copy.getName()),
                                  _requiredGradeToSign(getGradeToSign()),
                                  _requiredGradeToExecute(getGradeToExec())
{
    *this = copy;
}

AForm &AForm::operator=(const AForm &copy)
{
    if (this == &copy)
        return *this;
    _isSigned = copy._isSigned;
    return *this;
}

std::string AForm::getName(void) const
{
    return _name;
}

size_t AForm::getGradeToSign(void) const
{
    return _requiredGradeToSign;
}

size_t AForm::getGradeToExec(void) const
{
    return _requiredGradeToExecute;
}

std::string AForm::getIsSigned(void) const
{
    if (_isSigned == false)
        return "false";
    return "true";
}

void AForm::beSigned(Bureaucrat &b)
{
    if (b.getGrade() <= this->getGradeToSign())
        this->_isSigned = true;
}

void AForm::execute(const Bureaucrat &executor) const
{
    if (!_isSigned)
        throw FormNotSignedException();
    if (executor.getGrade() >= _requiredGradeToExecute)
        throw GradeTooLowException();
    std::cout << executor.getName() << " executed " << _name << std::endl;
    specificExecute();       
}

const char *AForm::FormNotSignedException::what() const throw()
{
    return "AForm: Form not signed!";
};

const char *AForm::GradeTooHighException::what() const throw()
{
    return "AForm: Grade Too High";
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "AForm: Grade Too Low";
}

std::ostream &operator<<(std::ostream &o, AForm &f)
{
    o << f.getName() << ", requried grade to sign " << f.getGradeToSign()
      << ", required grade to execute " << f.getGradeToExec() << ", is signed " << f.getIsSigned() << std::endl;
    return o;
}
