#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
    std::cout << GREEN << "A new zombie has been created" << RESET << std::endl;
    this->_name = name;
}

Zombie::~Zombie()
{
    std::cout << RED << this->_name << ": has been slain" << RESET << std::endl;
}

void Zombie::announce(void)
{
    std::cout << CYAN << this->_name << ": BraiiiiiiinnnzzzZ..." << RESET << std::endl;
}

