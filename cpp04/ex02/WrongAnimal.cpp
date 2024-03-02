#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal")
{
    std::cout << GREEN << "WrongAnimal default constructor called" << RESET << std::endl;
}

WrongAnimal::WrongAnimal(std::string _type) : _type(_type)
{
    std::cout << GREEN << "WrongAnimal type constructor called" << RESET << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &wrongAnimal)
{
    std::cout << YELLOW << "WrongAnimal copy constructor called" << RESET << std::endl;
    *this = wrongAnimal;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << RED << "WrongAnimal destructor called" << RESET << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &wrongAnimal)
{
    std::cout << PURPLE << "WrongAnimal assignation operator called" << RESET << std::endl;
    if (this != &wrongAnimal)
        this->_type = wrongAnimal._type;
    return *this;
}

std::string WrongAnimal::getType() const
{
    return this->_type;
}

void WrongAnimal::setType(std::string type)
{
    this->_type = type;
}

void WrongAnimal::makeSound() const
{
    std::cout << S_WHITE << "WrongAnimal sound -> " << S_MAGENTA << getType() << RESET << std::endl;
}