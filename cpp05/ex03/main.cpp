#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main()
{
    Intern someRandomIntern;
    AForm* form = NULL;
    try {
        form = someRandomIntern.makeForm("shrubbery creation", "kumburgazlı_şaban");
        
        Bureaucrat b("rte", 1);
        b.signAForm(*form);
        b.executeForm(*form);
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    if (form)
        delete form;
}
