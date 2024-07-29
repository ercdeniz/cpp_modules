#include "RPN.hpp"

int main(int ac, char **av)
{
	if (ac == 2)
	{
		RPN rpn(av[1]);
		try
		{
			rpn.calculateRPN();
			return 0;
		}
		catch (std::exception &e)
		{
			EXCEPTERROR
			if(std::string(e.what()) == "stack size != 1")
			{
				std::stack<int> stack = rpn.getStack();
				std::cout << RED << "Stack Content: ";
				while (stack.size() != 1)
				{
					std::cout << stack.top() << ", ";
					stack.pop();
				}
				std::cout << stack.top() << RESET << std::endl;
			}
			return 1;
		}
	}
	USAGEERROR
}
