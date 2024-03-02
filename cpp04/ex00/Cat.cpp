#include "Cat.hpp"

Cat::Cat()
{
    std::cout << GREEN << "Cat default constructor called" << RESET << std::endl;
    _type = "Cat";
}

Cat::Cat(const Cat &cat)
{
    std::cout << YELLOW << "Cat copy constructor called" << RESET << std::endl;
    *this = cat;
}

Cat::~Cat()
{
    std::cout << RED << "Cat destructor called" << RESET << std::endl;
}

Cat &Cat::operator=(const Cat &cat)
{
    std::cout << PURPLE << "Cat assignation operator called" << RESET << std::endl;
    if (this != &cat)
        this->setType(cat.getType());
    return *this;
}

void Cat::makeSound() const
{
    std::cout << CYAN << "Meow Meow" << RESET << std::endl;
}