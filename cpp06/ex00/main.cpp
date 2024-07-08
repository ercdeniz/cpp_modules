#include "ScalarConverter.hpp"
#include <cerrno>
#include <cstring>

int main(int argc, char* argv[]) {
	if (argc == 2) {
		ScalarConverter::converter(std::string(argv[1]));
		return 0;
	}
	std::cout << RED << "Error: " << strerror(EINVAL) << CYAN
		<< "\nUsage: " << GREEN << "./convert [input]" << RESET << std::endl;
	return 1;
}

