#pragma once

#include <iostream>

// Colors
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
#define MAGENTA "\033[1;35m"
#define CYAN "\033[1;36m"
#define RESET "\033[0m"

class ScalarConverter
{
	private:
		static std::string _input;
		static char _char;
		static int _int;
		static float _float;
		static double _double;
		static int _status[4]; // 0: char, 1: int, 2: float, 3: double
		/*
			char: 0: impossible, 1: non displayable, other: possible
			int: 0: impossible, other: possible
			float: 0: -inf, 1: +inf, 2: nan, 3: impossible, other: possible
			double: 0: -inf, 1: +inf, 2: nan, 3: impossible, other: possible
		*/
		// Canonical form
		ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter &operator=(const ScalarConverter &other);
		~ScalarConverter();

	public:
		// Convert functions
		static void converter(const std::string &input);
		static void convertChar();
		static void convertInt();
		static void convertFloat();
		static void convertDouble();

		// Member functions
		static bool checkForScience();
		static void printConversions();
};

