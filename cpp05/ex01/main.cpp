#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat rte("rte", 10);
        std::cout << rte << std::endl;

        Form Form1("Form 1", 9, 10);
        std::cout << Form1 << std::endl; // henüz imzalanmamış

        rte.signForm(Form1);
        std::cout << Form1 << std::endl; // imzalandı
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return (0);
}
