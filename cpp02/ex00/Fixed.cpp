#include "Fixed.hpp"

Fixed::Fixed() : rawBits(0){
	std::cout << GREEN << "Default constructor called" << RESET << std::endl;
}

Fixed::Fixed(const Fixed &fixed){
	std::cout << PURPLE << "Copy constructor called" << RESET << std::endl;
	*this = fixed;
}

Fixed& Fixed::operator=(const Fixed &fixed){
	std::cout << BLUE << "Assignation operator called" << RESET << std::endl;
	this->rawBits = fixed.getRawBits();
	return (*this);
}

Fixed::~Fixed(){
	std::cout << RED << "Default destructor called" << RESET << std::endl;
}

int	Fixed::getRawBits(void) const{
	std::cout << YELLOW << "getRawBits member function called" << RESET << std::endl;
	return (this->rawBits);
}

void Fixed::setRawBits(int const raw){
	std::cout << YELLOW << "setRawBits member function called" << RESET << std::endl;
	this->rawBits = raw;
}


