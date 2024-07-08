#include "Base.hpp"
#include <cstdlib>
#include <ctime>

Base::~Base() {}

Base*	generate(void)
{
	srand(time(NULL));

	unsigned char n = rand() % 3;
	if (n == 0)
		return (new A());
	else if (n == 1)
		return (new B());
	return (new C());
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p) != NULL)
	{
		std::cout << CYAN << "\'A\'" << YELLOW << " class was identified!" << RESET << std::endl;
		return ;
	}
	else if (dynamic_cast<B*>(p) != NULL)
	{
		std::cout << CYAN << "\'B\'" << YELLOW << " class was identified!" << RESET << std::endl;
		return ;
	}
	else if (dynamic_cast<C*>(p) != NULL)
	{
		std::cout << CYAN << "\'C\'" << YELLOW << " class was identified!" << RESET << std::endl;
		return ;
	}
	std::cout << "Can't identify the class!" << std::endl;
}

void	identify(Base& p)
{
	try
	{
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << CYAN << "\'A\'" << YELLOW << " class was identified!" << RESET << std::endl;
		return ;
	}
	catch (std::bad_cast &) {}

	try
	{
		B& b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << CYAN << "\'B\'" << YELLOW << " class was identified!" << RESET << std::endl;
		return ;
	}
	catch (std::bad_cast &) {}

	try
	{
		C& c = dynamic_cast<C&>(p);
		(void)c ;
		std::cout << CYAN << "\'C\'" << YELLOW << " class was identified!" << RESET << std::endl;
		return ;
	}
	catch (std::bad_cast &) {}

	std::cout << "Can't identify the class!" << std::endl;
}