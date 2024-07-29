#include "PmergeMe.hpp"

PmergeMe p;

template <typename Iterator>
double stopWatch(Iterator begin, Iterator end)
{
	std::clock_t start;
	std::clock_t stop;

	start = std::clock();
	p.fordJohnsonSort(begin, end);
	stop = std::clock();
	return static_cast<double>(stop - start) / CLOCKS_PER_SEC * 1000;
}

int main(int ac, char **av)
{
	if (ac >= 2)
	{
		try
		{
			if (!p.checkAndSort(ac, av))
				return 1;
			std::cout << CYAN << "Original vector: ";
			std::vector<std::string> inputArgs = p.getInputArgs();
			PRINTARR(inputArgs, BLUE);
			std::cout << std::endl;

			// Set vector and deque
			std::vector<unsigned int> vec = p.getArr();
			std::deque<unsigned int> deq(vec.begin(), vec.end());

			// Sort vector and deque
			double vecTime = stopWatch(vec.begin(), vec.end());
			double deqTime = stopWatch(deq.begin(), deq.end());

			// Print sorted vector and deque
			std::cout << MAGENTA << "Sorted vector: ";
			PRINTARR(vec, YELLOW);
			std::cout << MAGENTA << "Sorted deque: ";
			PRINTARR(deq, YELLOW);

			// Print time to process
			std::cout << std::endl
			<< CYAN << "Time to process a range of " << vec.size() << " elements with std::vector : " << vecTime << " us" << std::endl
			<< CYAN << "Time to process a range of " << deq.size() << " elements with std::deque : " << deqTime << " us" << std::endl;
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
