#pragma once

#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <iterator>
#include <cctype>
#include <sstream>

// COLORS
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define RESET "\033[0m"

// MACROS
#define USAGEERROR                                                               \
	std::cerr << RED "Usage: " YELLOW << av[0] << " numbers" RESET << std::endl; \
	return 1;
#define EXCEPTERROR                                               \
	std::cerr << RED "Error: " << e.what() << RESET << std::endl; \
	return 1;
#define PRINTARR(arr, color)                \
	for (size_t i = 0; i < arr.size(); i++)  \
		std::cout << color << arr[i] << " "; \
	std::cout << RESET << std::endl
#define PRINTGREEN(value) std::cout << GREEN << value << RESET << std::endl
#define PRINTRED(value) std::cout << RED << value << RESET << std::endl

// ENUMS
enum ValidationResult
{
	VALID,
	LOWARGUMENTS,
	NOTDIGIT,
	NEGATIVENUMBER,
	REPEATEDNUMBER
};

class PmergeMe
{
	private:
		std::vector<std::string> _inputArgs;
		std::vector<unsigned int> _arr;

	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);

		// GETTERS
		std::vector<std::string> getInputArgs() const;
		std::vector<unsigned int> getArr() const;

		// MEMBER FUNCTIONS
		ValidationResult argCheck(std::vector<std::string> args);
		bool checkAndSort(int ac, char **av);

		// TEMPLATE
		template <typename Iterator>
		void fordJohnsonSort(Iterator begin, Iterator end);

		// UTILS
		bool isDigit(const std::string &str);
		std::vector<std::string> split(const std::string &str);
		std::string toStr(int value);
};

#include "PmergeMe.tpp"
