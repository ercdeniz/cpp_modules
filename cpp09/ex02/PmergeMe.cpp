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
	{
		this->_arr = other._arr;
		this->_inputArgs = other._inputArgs;
	}
	return *this;
}

std::vector<std::string> PmergeMe::getInputArgs() const
{
	return _inputArgs;
}

std::vector<unsigned int> PmergeMe::getArr() const
{
	return _arr;
}

ValidationResult PmergeMe::argCheck(std::vector<std::string> args)
{
	if (args.size() < 2)
		return LOWARGUMENTS;
	for (size_t i = 0; i < args.size(); i++)
	{
		if (!isDigit(args[i]))
			return NOTDIGIT;
		int temp = atoi(args[i].c_str());
		if (temp < 0)
			return NEGATIVENUMBER;
		if (i != 0 && std::find(args.begin(), args.begin() + i, toStr(temp)) != args.begin() + i)
			return REPEATEDNUMBER;
		_arr.push_back(temp);
	}
	return VALID;
}

bool PmergeMe::checkAndSort(int ac, char **av)
{
	while (--ac)
		_inputArgs.push_back(*++av);
	for (size_t i = 0; i < _inputArgs.size(); i++)
		if (std::find(_inputArgs[i].begin(), _inputArgs[i].end(), ' ') != _inputArgs[i].end())
		{
			std::vector<std::string> temp = split(_inputArgs[i]);
			_inputArgs.erase(_inputArgs.begin() + i);
			_inputArgs.insert(_inputArgs.begin() + i, temp.begin(), temp.end());
		}
	switch (argCheck(_inputArgs))
	{
		case LOWARGUMENTS:
			PRINTRED("Error: Low arguments");
			return false;
		case NOTDIGIT:
			PRINTRED("Error: Not a digit");
			return false;
		case REPEATEDNUMBER:
			PRINTRED("Error: Repeated number");
			return false;
		case NEGATIVENUMBER:
			PRINTRED("Error: Negative number");
			return false;
		default:
			break;
	}
	return true;
}
