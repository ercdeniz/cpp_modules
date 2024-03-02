#include "Brain.hpp"

Brain::Brain()
{
    std::cout << GREEN << "Brain default constructor called" << RESET << std::endl;
    for (int i = 0; i < 100; i++)
        this->ideas[i] = "No idea";
}

Brain::Brain(const Brain &brain)
{
    std::cout << YELLOW << "Brain copy constructor called" << RESET << std::endl;
    *this = brain;
}

Brain::~Brain()
{
    std::cout << RED << "Brain destructor called" << RESET << std::endl;
}

Brain &Brain::operator=(const Brain &brain)
{
    std::cout << PURPLE << "Brain assignation operator called" << RESET << std::endl;
    if (this != &brain)
    {
        for (int i = 0; i < 100; i++)
            this->ideas[i] = brain.ideas[i];
    }
    return *this;
}

std::string Brain::getIdea(int index) const
{
    return this->ideas[index];
}

void Brain::setIdea(int index, std::string idea)
{
    this->ideas[index] = idea;
}