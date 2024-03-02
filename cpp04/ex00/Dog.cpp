#include "Dog.hpp"

Dog::Dog()
{
    std::cout << GREEN << "Dog default constructor called" << RESET << std::endl;
    _type = "Dog";
}

Dog::Dog(const Dog &dog)
{
    std::cout << YELLOW << "Dog copy constructor called" << RESET << std::endl;
    *this = dog;
}

Dog::~Dog()
{
    std::cout << RED << "Dog destructor called" << RESET << std::endl;
}

Dog &Dog::operator=(const Dog &dog)
{
    std::cout << PURPLE << "Dog assignation operator called" << RESET << std::endl;
    if (this != &dog)
        this->setType(dog.getType());
    return *this;
}

void Dog::makeSound() const
{
    std::cout << CYAN << "Woff Woff" << RESET << std::endl;
}