#include "Base.hpp"

int main(void)
{
	try
	{
		Base* p = generate();
		if (!p)
			throw std::runtime_error("NULL pointer!");

		identify(p);
		identify(*p);
		delete p;
	}
	catch (const std::exception& e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
	return (0);
}