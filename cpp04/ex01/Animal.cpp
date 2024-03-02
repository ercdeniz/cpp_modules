#include "Animal.hpp"

Animal::Animal() : _type("Default Animal")
{
    std::cout << GREEN << "Animal default constructor called" << RESET << std::endl;
}

Animal::Animal(std::string _type) : _type(_type)
{
    std::cout << GREEN << "Animal type constructor called" << RESET << std::endl;
}

Animal::Animal(const Animal &animal)
{
    std::cout << YELLOW << "Animal copy constructor called" << RESET << std::endl;
    *this = animal;
}

Animal::~Animal()
{
    std::cout << RED << "Animal destructor called" << RESET << std::endl;
}

Animal &Animal::operator=(const Animal &animal)
{
    std::cout << PURPLE << "Animal assignation operator called" << RESET << std::endl;
    if (this != &animal)
        this->_type = animal._type;
    return *this;
}

std::string Animal::getType() const
{
    return this->_type;
}

void Animal::setType(std::string type)
{
    this->_type = type;
}

void Animal::makeSound() const
{
    std::cout << S_WHITE << "Default Animal sound -> " << S_MAGENTA << getType() << RESET << std::endl;
}