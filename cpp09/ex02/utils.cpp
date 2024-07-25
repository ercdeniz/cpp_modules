#include "PmergeMe.hpp"

bool PmergeMe::isDigit(const std::string &str)
{
	char *endptr;
	strtol(str.c_str(), &endptr, 10);
	if (*endptr != '\0')
		return false;
    return true;
}

std::vector<std::string> PmergeMe::split(const std::string& str) {
    std::vector<std::string> result;
    std::istringstream iss(str);
    std::string token;
    while (iss >> token)
        result.push_back(token);
    return result;
}

std::string PmergeMe::toStr(int value)
{
	std::stringstream ss;
	ss << value;
	return ss.str();
}

