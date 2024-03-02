#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    std::cout << GREEN << "WrongCat default constructor called" << RESET << std::endl;
    _type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &wrongCat)
{
    std::cout << YELLOW << "WrongCat copy constructor called" << RESET << std::endl;
    *this = wrongCat;
}

WrongCat::~WrongCat()
{
    std::cout << RED << "WrongCat destructor called" << RESET << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &wrongCat)
{
    std::cout << PURPLE << "WrongCat assignation operator called" << RESET << std::endl;
    if (this != &wrongCat)
        this->setType(wrongCat.getType());
    return *this;
}

void WrongCat::makeSound() const
{
    std::cout << "WrongCat sound "<< std::endl;
}