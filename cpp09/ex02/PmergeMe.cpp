#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	*this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
		this->_arr = other._arr;
	return *this;
}

ValidationResult PmergeMe::argCheck(std::vector<std::string> args)
{
	for (size_t i = 0; i < args.size(); i++)
	{
		if (!isDigit(args[i]))
			return NOTDIGIT;
		int temp = atoi(args[i].c_str());
		if (temp < 0)
			return NEGATIVENUMBER;
		if (i != 0 && std::find(args.begin(), args.begin() + i , toStr(temp)) != args.begin() + i)
			return REPEATEDNUMBER;
		_arr.push_back(temp);
	}
	return VALID;
}


