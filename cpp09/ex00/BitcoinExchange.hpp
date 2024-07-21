#pragma once

#include <iostream>
#include <fstream>
#include <ios>
#include <map>


//COLORS
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define RESET "\033[0m"

//MACROS
#define USAGEERROR std::cerr << RED "Usage: " YELLOW << av[0] << " <filename>" RESET << std::endl; return 1;
#define EXCEPTERROR std::cerr << RED "Error: " << e.what() << RESET << std::endl; return 1;
#define PRINT(value) std::cout << value << std::endl
#define PRINTGREEN(value) std::cout << GREEN << value << RESET << std::endl
#define PRINTRED(value) std::cout << RED << value << RESET << std::endl
#define INVALIDTEXT "Invalid input format"
#define DATE_PARTS 3

class BitcoinExchange
{
    private:
        std::string _inputFile;
    public:
        BitcoinExchange(std::string filename);
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange &operator=(const BitcoinExchange &other);
        void readAndParseInputFile();

        //UTILS
        bool isValidDate(const std::string& date);
};