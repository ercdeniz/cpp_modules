#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
    try
    {
        Bureaucrat bureaucrat("John", 5);
        
        PresidentialPardonForm presidentialForm("John's Pardon Form");
        ShrubberyCreationForm shrubberyForm("John's_Shrubbery_Form");
        RobotomyRequestForm robotomyForm("John's Robotomy Form");
        
        std::cout << CYAN << "--------------presidentialForm--------------" << RESET << std::endl;
        bureaucrat.signAForm(presidentialForm);
        bureaucrat.executeForm(presidentialForm);
        
        std::cout << CYAN << "--------------robotomyForm--------------" << RESET << std::endl;
        bureaucrat.signAForm(robotomyForm);
        bureaucrat.executeForm(robotomyForm);

        std::cout << CYAN << "--------------shrubberyForm--------------" << RESET << std::endl;
        bureaucrat.signAForm(shrubberyForm);
        bureaucrat.executeForm(shrubberyForm);
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << e.what() << RESET << '\n';
    }
    
    return (0);
}
