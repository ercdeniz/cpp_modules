#include "ScalarConverter.hpp"
#include <limits>
#include <cstdlib>
#include <cmath>

// because of the static variables, we need to define them outside the class. Why? Damn subject.pdf.
std::string ScalarConverter::_input = "";
char ScalarConverter::_char;
int ScalarConverter::_int;
float ScalarConverter::_float;
double ScalarConverter::_double;
int ScalarConverter::_status[4] = {2, 2, 4, 4};

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {
    *this = other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
    if (this != &other){
        _input = other._input;
        _char = other._char;
        _int = other._int;
        _float = other._float;
        _double = other._double;
    }
    return *this;
}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::converter(const std::string &input) {
    _input = input;
    convertChar();
    convertInt();
    convertFloat();
    convertDouble();
    printConversions();
}

bool ScalarConverter::checkForScience() {
    const char* checkList[] = {"-inff", "+inff", "nanf", "-inf", "+inf", "nan", "inf", "inff"};
    for (int i = 0; i < 8; i++)
        if (_input == std::string(checkList[i]))
            return true;
    return false;
}

void ScalarConverter::convertChar() {
	if(_input.size() == 1 && !isdigit(_input[0]))
	{
		_char = _input[0];
		return;
	}
	char c = static_cast<char>(std::atoi(_input.c_str()));
    if (checkForScience())
        _status[0] = 0;
    else if (std::isprint(c))
        _char = c;
    else
        _status[0] = 1;
}

void ScalarConverter::convertInt() {
    if (checkForScience())
        _status[1] = 0;
    else {
        int i = std::atoi(_input.c_str());
        if (_input != "0" && ((i <= 0 && _input[0] != '-') || (i >= 0 && _input[0] == '-')))
            _status[1] = 0;
        else
            _int = i;
    }
}

void ScalarConverter::convertFloat() {
    float f = std::atof(_input.c_str());
    if (f == std::numeric_limits<float>::infinity())
        _status[2] = 1;
    else if (f == -std::numeric_limits<float>::infinity())
        _status[2] = 0;
    else if (std::isnan(f))
        _status[2] = 2;
    else if (_input != "0" && ((f <= 0 && _input[0] != '-') || (f >= 0 && _input[0] == '-')))
        _status[2] = 3;
    else
        _float = f;
}

void ScalarConverter::convertDouble() {
    double d = std::atof(_input.c_str());
    if (d == std::numeric_limits<double>::infinity())
        _status[3] = 1;
    else if (d == -std::numeric_limits<double>::infinity())
        _status[3] = 0;
    else if (std::isnan(d))
        _status[3] = 2;
    else if (_input != "0" && ((d <= 0 && _input[0] != '-') || (d >= 0 && _input[0] == '-')))
        _status[3] = 3;
    else
        _double = d;
}

void ScalarConverter::printConversions(){
    std::cout << CYAN << "char: ";
    switch (_status[0]) {
        case 0:
            std::cout << RED << "impossible" << std::endl;
            break;
        case 1:
            std::cout << MAGENTA << "Non displayable" << std::endl;
            break;
        default:
            std::cout << GREEN << "'" << _char << "'" << std::endl;
            break;
    }
    std::cout << CYAN << "int: ";
    switch (_status[1]) {
        case 0:
            std::cout << RED << "impossible" << std::endl;
            break;
        default:
            std::cout << GREEN << _int << std::endl;
            break;
    }
    std::cout << CYAN << "float: ";
    switch (_status[2]) {
        case 0:
            std::cout << YELLOW << "-inff" << std::endl;
            break;
        case 1:
            std::cout << YELLOW << "+inff" << std::endl;
            break;
        case 2:
            std::cout << YELLOW << "nanf" << std::endl;
            break;
        case 3:
            std::cout << RED << "impossible" << std::endl;
            break;
        default:
            std::cout << GREEN << _float << "f" << std::endl;
            break;
    }

    std::cout << CYAN << "double: ";
    switch (_status[3]) {
        case 0:
            std::cout << YELLOW << "-inf" << std::endl;
            break;
        case 1:
            std::cout << YELLOW << "+inf" << std::endl;
            break;
        case 2:
            std::cout << YELLOW << "nan" << std::endl;
            break;
        case 3:
            std::cout << RED << "impossible" << std::endl;
            break;
        default:
            std::cout << GREEN << _double << std::endl;
            break;
    }
    std::cout << RESET;
}
