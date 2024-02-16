#include "Zombie.hpp"

Zombie::~Zombie(void)
{
    std::string colors[] = {RED, GREEN, BLUE, WHITE, PURPLE, CYAN, YELLOW, PING};
    int randomColor = rand() % 8;
    std::cout << colors[randomColor] << this->_name << " died" << RESET<< std::endl;
}

void Zombie::announce(void)
{
    std::string colors[] = {RED, GREEN, YELLOW, WHITE, PURPLE, CYAN, PING, BLUE};
    int randomColor = rand() % 8;
    std::cout << colors[randomColor] << this->_name << ": BraiiiiiiinnnzzzZ..." << RESET << std::endl;
}

void    Zombie::setName( std::string name )
{
     this->_name = name;
}
