#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap("")
{
    std::cout << GREEN << "FragTrap default constructor" << RESET << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    setHitPoints(100);
    setEnergyPoints(100);
    setAttackDamage(30);
    std::cout << GREEN << "FragTrap " << name << " is born!" << RESET << std::endl;
}

FragTrap::FragTrap(const FragTrap &src) : ClapTrap(src)
{
    *this = src;
    std::cout << GREEN << "CopyFragTrap " << getName() << RESET << " is born!" << std::endl;
}

FragTrap::~FragTrap(void)
{
    std::cout << RED << "FragTrap " << getName() << RESET << " is destroyed!" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &src)
{
    setHitPoints(src.getHitPoints());
    setEnergyPoints(src.getEnergyPoints());
    setAttackDamage(src.getAttackDamage());
    return *this;
}

void FragTrap::attack(std::string const &target)
{
    if(getAttackDamage() > 0){
        if (getHitPoints() > 0){
            std::cout << YELLOW << "FragTrap " << getName() << PURPLE << " attacks " << target 
                << ", causing " << getAttackDamage() << " points of damage!" << RESET << std::endl;
            setEnergyPoints(getEnergyPoints() - 1);
        }
        else
            std::cout << BOLD PURPLE << "FragTrap " << getName() 
                << " can't attack. Not enough hit points or energy points!" << RESET << std::endl;
    }
    else
        std::cout << BOLD PURPLE << "FragTrap " << getName() << " can't attack. Attack damage is 0!" << RESET << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    if(getEnergyPoints() > 0)
        std::cout << PURPLE << "FragTrap " << getName() << " says: Gimme five!" << RESET << std::endl;
    else
        std::cout << BOLD PURPLE << "FragTrap " << getName() << " can't give high five. No energy points!" << RESET << std::endl;
}