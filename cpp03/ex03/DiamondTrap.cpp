#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(""), ScavTrap(""), FragTrap(""), _name("") {
    std::cout << GREEN << "DiamondTrap default constructor called!" << RESET << std::endl;
}

DiamondTrap::DiamondTrap(const std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name) {
    this->_name = name;
    setHitPoints(100);
    setEnergyPoints(50);
    setAttackDamage(30);
    std::cout << GREEN << "DiamondTrap " << _name << " is created!" << RESET << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), ScavTrap(other), FragTrap(other){
    *this = other;
    std::cout << GREEN << "DiamondTrap " << _name << " is copied!" << RESET << std::endl;
}

DiamondTrap::~DiamondTrap() {
    std::cout << RED << "DiamondTrap " << _name << " is destroyed!" << RESET << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
    if (this != &other) {
        this->_name = other.getDiamondName();
        this->ClapTrap::operator=(other);
    }
    return *this;
}

void DiamondTrap::attack(const std::string& target) {
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {
    std::cout << CYAN << "Diamond name: " << _name << ", ClapTrap name: "
        << getName() << RESET << std::endl;
}

const std::string& DiamondTrap::getDiamondName() const {
    return this->_name;
}

void DiamondTrap::setDiamondName(const std::string& name) {
    _name = name;
}