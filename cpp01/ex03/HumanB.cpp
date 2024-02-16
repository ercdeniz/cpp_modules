#include "HumanB.hpp"

void HumanB::attack() const {
	if (_weapon != NULL)
		std::cout <<YELLOW<< this->_name <<RED<< " attacks with his " << PURPLE<< this->_weapon->getType() <<RESET<< std::endl;
	else
		std::cout <<YELLOW<< this->_name <<RED<< " doesn't have a weapon to attack." <<RESET<< std::endl;
}

void HumanB::setWeapon(const Weapon &weapon) {
    this->_weapon = (Weapon*)&weapon;
}