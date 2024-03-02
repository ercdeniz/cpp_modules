#include "Animal.hpp"

AAnimal::AAnimal() : _type("Default AAnimal")
{
    std::cout << GREEN << "AAnimal default constructor called" << RESET << std::endl;
}

AAnimal::AAnimal(std::string _type) : _type(_type)
{
    std::cout << GREEN << "AAnimal type constructor called" << RESET << std::endl;
}

AAnimal::AAnimal(const AAnimal &AAnimal)
{
    std::cout << YELLOW << "AAnimal copy constructor called" << RESET << std::endl;
    *this = AAnimal;
}

AAnimal::~AAnimal()
{
    std::cout << RED << "AAnimal destructor called" << RESET << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &AAnimal)
{
    std::cout << PURPLE << "AAnimal assignation operator called" << RESET << std::endl;
    if (this != &AAnimal)
        this->_type = AAnimal._type;
    return *this;
}

std::string AAnimal::getType() const
{
    return this->_type;
}

void AAnimal::setType(std::string type)
{
    this->_type = type;
}
