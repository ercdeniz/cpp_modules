#pragma once

#include <iostream>
#include <stack>
#include <sstream>
#include <string>
#include <cstdlib>
#include <climits>

// COLORS
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define RESET "\033[0m"

// MACROS
#define USAGEERROR                                                                  \
    std::cerr << RED "Usage: " YELLOW << av[0] << " \"expression\"" RESET << std::endl; \
    return 1;
#define EXCEPTERROR                                               \
    std::cerr << RED "Error: " << e.what() << RESET << std::endl; \
    return 1;
#define PRINTGREEN(value) std::cout << GREEN << value << RESET << std::endl
#define PRINTRED(value) std::cout << RED << value << RESET << std::endl

class RPN
{
    private:
        RPN();
        std::string _input;
        std::stack<int> _stack;

    public:
        RPN(std::string input);
        ~RPN();
        RPN(const RPN &other);
        RPN &operator=(const RPN &other);

        bool isOperator(const std::string &token) const;
        int applyOperation(int left, int right, const std::string &op);
        void calculateRPN();
};