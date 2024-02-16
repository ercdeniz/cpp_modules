#include "HumanA.hpp"

void HumanA::attack() const {
	std::cout << CYAN << this->_name <<RED<< " attacks with his " <<PURPLE<< this->_weapon.getType() << RESET << std::endl;
}