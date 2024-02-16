#include "Point.hpp"

Point	getPointInput(const std::string& prompt) {
	int x, y;
	std::cout << prompt << BOLD_UNDERLINE << "x coordinate:" << RESET << " ";
	std::cin >> x;

	if(std::cin.fail()) {
		std::cout << RED << "Invalid input" << RESET << std::endl;
		exit(1);
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	std::cout << prompt << BOLD_UNDERLINE << "y coordinate:" << RESET << " ";
	std::cin >> y;

	if(std::cin.fail()) {
		std::cout << RED << "Invalid input" << RESET << std::endl;
		exit(1);
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	return Point(x, y);
}

int main ( void ) {

	Point A = getPointInput( YELLOW "Enter the first point's	");
	Point B = getPointInput( YELLOW "Enter the second point's	");
	Point C = getPointInput( YELLOW "Enter the third point's	");
	Point P = getPointInput( YELLOW "Enter the point to check	");

	if ( bsp( A, B, C, P) == true ) {
			std::cout << GREEN
			<< "----------------------------------------\n"
			<< "|                                      |\n"
			<< "|       Point is in the triangle       |\n"
			<< "|                                      |\n"
			<< "----------------------------------------\n"
			<< RESET;
	} else {
			std::cout << RED
			<< "----------------------------------------\n"
			<< "|                                      |\n"
			<< "|      Point is not in the triangle    |\n"
			<< "|                                      |\n"
			<< "----------------------------------------\n"
			<< RESET;
}
	return 0;
}
