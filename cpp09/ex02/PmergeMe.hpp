#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <algorithm>
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
#define PRINTGREEN(value) std::cout << GREEN << value << RESET << std::endl
#define PRINTRED(value) std::cout << RED << value << RESET << std::endl

// ENUMS
enum ValidationResult
{
    VALID,
    NOTDIGIT,
    NEGATIVENUMBER,
    REPEATEDNUMBER
};

class PmergeMe
{
    private:
        std::vector<unsigned int> _arr;
    public:
        PmergeMe();
        ~PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);

        // GETTERS
        std::vector<unsigned int> getArr() const { return _arr; }
        ValidationResult argCheck(std::vector<std::string> args);

        template <typename T>
        void mergeSort(T &arr);

        //UTILS
        bool isDigit(const std::string &str);
        std::vector<std::string> split(const std::string& str);
        std::string toStr(int value);

};

#include "PmergeMe.tpp"