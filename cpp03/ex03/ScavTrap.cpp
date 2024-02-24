#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("")
{
    std::cout << GREEN << "ScavTrap default constructor" << RESET << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    setHitPoints(100);
    setEnergyPoints(50);
    setAttackDamage(20);
    std::cout << GREEN << "ScavTrap " << name << " is born!" << RESET << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &scavTrap) : ClapTrap(scavTrap)
{
    *this = scavTrap;
    std::cout << GREEN << "CopyScavTrap " << getName() << " is born!" << RESET << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << RED << "ScavTrap " << getName() << " is destroyed!" << RESET << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &scavTrap)
{
    setHitPoints(scavTrap.getHitPoints());
    setEnergyPoints(scavTrap.getEnergyPoints());
    setAttackDamage(scavTrap.getAttackDamage());
    return *this;
}

void ScavTrap::guardGate()
{
    if(getEnergyPoints() <= 0)
        std::cout << PURPLE << "ScavTrap " << getName()
            << " Don't worry, they're just sleeping!" << RESET << std::endl;
    if(getHitPoints() > 0)
        std::cout << PURPLE << "ScavTrap " << getName()
            << " no one will be destroyed as long as is at the gate!" <<  RESET << std::endl;
    else
        std::cout << BOLD PURPLE << "ScavTrap " << getName() 
            << " don't worry, everyone is safe!" << RESET << std::endl;
}

void ScavTrap::attack(std::string const &target)
{
    if(this->getAttackDamage() > 0){
		if (this->getHitPoints() > 0){
			std::cout << YELLOW << "ScavTrap " << this->getName() << PURPLE << " attacks " << target 
				<< ", causing " << this->getAttackDamage() << " points of damage!" << RESET << std::endl;
            this->setEnergyPoints(this->getEnergyPoints() - 1);
		}
		else
			std::cout << BOLD PURPLE << "ScavTrap " << this->getName()
				<< " can't attack. Not enough hit points or energy points!" << RESET << std::endl;
	}
	else
		std::cout << BOLD PURPLE << "ScavTrap " << this->getName() 
			<< " can't attack. Not enough attack damage!" << RESET << std::endl;
}