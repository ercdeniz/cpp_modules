#include "RPN.hpp"

int main(int ac, char **av)
{
    if (ac == 2)
    {
        try
        {
            RPN rpn(av[1]);
            rpn.calculateRPN();
            return 0;
        }
        catch (std::exception &e)
        {
            EXCEPTERROR
        }
    }
    USAGEERROR
}