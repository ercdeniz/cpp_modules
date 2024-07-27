#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	if (ac >= 2)
	{
		try
		{
			PmergeMe p;
			std::vector<std::string> args;
			while (--ac)
				args.push_back(*++av);
			for (size_t i = 0; i < args.size(); i++)
				if (std::find(args[i].begin(), args[i].end(), ' ') != args[i].end())
				{
					std::vector<std::string> temp = p.split(args[i]);
					args.erase(args.begin() + i);
					args.insert(args.begin() + i, temp.begin(), temp.end());
				}
			switch (p.argCheck(args))
			{
				case NOTDIGIT:
					PRINTRED("Error: Not a digit");
					return 1;
				case REPEATEDNUMBER:
					PRINTRED("Error: Repeated number");
					return 1;
				case NEGATIVENUMBER:
					PRINTRED("Error: Negative number");
					return 1;
				default:
					std::vector<unsigned int> arr = p.getArr();
					p.fordJohnsonSort(arr.begin(), arr.end());
					for (size_t i = 0; i < arr.size(); i++)
						std::cout << arr[i] << " ";
			}
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