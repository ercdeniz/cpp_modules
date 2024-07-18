#include "MutantStack.hpp"

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << BLUE << "Top: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << YELLOW << "Size: " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator end = mstack.end();

	while (it != end)
	{
		std::cout << CYAN << "Iterator value: " << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack); // This transformation shows that MutantStack is compatible with std::stack.
	return 0;
}
