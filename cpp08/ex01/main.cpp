#include "Span.hpp"

int main()
{
	try
	{
		int len = 10;
		Span span = Span(len);

		srand(time(0));
		for (int i = 0; i < len; i++)
			span.addNumber(span.getRandomNumber());

		std::cout << YELLOW << "Array contents: " << MAGENTA;
		for (int i = 0; i < len; i++)
			std::cout << span.getArr()[i] << ((len - 1) == i ? "" : ", ");
		std::cout << std::endl
				  << CYAN << "Shortest span " << span.shortestSpan() << std::endl
				  << BLUE << "Longest span " << span.longestSpan() << RESET << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	return 0;
}