#include "Bureaucrat.hpp"

int main()
{
    try {
        Bureaucrat rte("tayyip", 1);
        std::cout << rte << std::endl;
        rte.gradeDown();
        std::cout << rte << std::endl;
        
        Bureaucrat kk("bay kemal", 150);
        std::cout << kk << std::endl;
        kk.gradeDown();
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return(1);
    }
    return 0;
}