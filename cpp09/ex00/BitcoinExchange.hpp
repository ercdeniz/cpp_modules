#pragma once

#include <iostream>
#include <algorithm>
#include <fstream>
#include <set>
#include <ctime>
#include <sstream>
#include <utility>
#include <cstdlib>

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
	std::cerr << RED "Usage: " YELLOW << av[0] << " <filename>" RESET << std::endl; \
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
	INVALIDDATE,
	NOTDIGIT,
	OUTOFBOUNDS,
	NOTPOSITIVE
};

class BitcoinExchange
{
	private:
		BitcoinExchange();
		std::string _inputFile;
		time_t _ltm;
		time_t _thresholdDate;
		std::set<std::pair<int, float> > _data;

	public:
		BitcoinExchange(std::string filename);
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);

		void readAndParseDataFile();
		void readAndParseInputFile();
		void inputCalculator(std::pair<std::string, std::string> mapline);
		void dataCalculator(std::pair<std::string, std::string> mapline);

		// UTILS
		ValidationResult isValidDateAndValue(std::pair<std::string, std::string> mapline);
		std::string trim(const std::string &str);
		std::string toStr(float value);
		std::tm parseDate(const std::string &dateStr);
		int calcualteDayDiff(std::string date, time_t thresholdDate);
		float strtod(const std::string &str);
};
