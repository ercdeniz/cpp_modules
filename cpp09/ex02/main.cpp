#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	if (ac >= 2)
	{
		try
		{
			PmergeMe p;
			if (!p.checkAndSort(ac, av))
				return 1;

			std::cout << CYAN << "Original vector: ";
			std::vector<std::string> inputArgs = p.getInputArgs();
			PIRINTARR(inputArgs, BLUE);
			std::cout << std::endl;

			std::vector<unsigned int> arr = p.getArr();
			p.fordJohnsonSort(arr.begin(), arr.end());
			std::cout << MAGENTA << "Sorted vector: ";
			PIRINTARR(arr, YELLOW);

			std::deque<unsigned int> deq(arr.begin(), arr.end());
			std::cout << MAGENTA << "Sorted deque: ";
			PIRINTARR(deq, YELLOW);
			return 0;
		}
		catch (std::exception &e)
		{
			EXCEPTERROR
		}
	}
	USAGEERROR
	return 0;
}