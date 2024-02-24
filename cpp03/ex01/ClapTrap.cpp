#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string& name) : _name(name), _hitPoints(10), _energyPoints(10){
    std::cout << GREEN << "ClapTrap " << _name << " is born!" << RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) : _name(other._name), _hitPoints(other._hitPoints), _energyPoints(other._energyPoints), _attackDamage(other._attackDamage) {
    std::cout << GREEN << "CopyClapTrap " << _name << " is born!" << RESET << std::endl;
}

ClapTrap::~ClapTrap() {
    std::cout << RED << "ClapTrap " << _name << " is destroyed!" << RESET << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    _name = other._name;
    _hitPoints = other._hitPoints;
    _energyPoints = other._energyPoints;
    _attackDamage = other._attackDamage;
    return *this;
}

void ClapTrap::attack(const std::string& target) {
    if(this->_attackDamage > 0){
        if (_hitPoints > 0 && _energyPoints > 0) {
            std::cout << YELLOW << "ClapTrap " << _name << PURPLE << " attacks " << target <<", causing " << _attackDamage << " points of damage!" << RESET << std::endl;
            _energyPoints--;
        } else 
            std::cout << BOLD PURPLE << "ClapTrap " << _name << " can't attack. Not enough hit points or energy points!" << RESET << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount) {
    if(amount > 0){
        if (_hitPoints > 0 && _energyPoints > 0) {
            std::cout << YELLOW << "ClapTrap " << _name << RED << " takes " << amount << " points of damage!" << RESET << std::endl;
            _hitPoints -= amount;
            if (_hitPoints < 0)
                _hitPoints = 0;
        } else {
            std::cout << BOLD RED << "ClapTrap " << _name << " no energy or is already destroyed!" << RESET << std::endl;
        }
    }
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (amount > 0){
        if (_hitPoints > 0 && _energyPoints > 0) {
            std::cout << YELLOW << "ClapTrap " << _name << GREEN << " exchange for one energy " << amount << " points repaired" << RESET << std::endl;
            _hitPoints += amount;
            _energyPoints--;
            if (_hitPoints < 0)
                _hitPoints = 0;
        } else {
            std::cout << BOLD RED << "ClapTrap " << _name << " it can't be repaired! The energy has run out or has already been destroyed" << RESET << std::endl;
        }
    }
}

std::string ClapTrap::getName() const {
    return _name;
}

void ClapTrap::setName(const std::string& name) {
    this->_name = name;
}

int ClapTrap::getEnergyPoints() const {
    return _energyPoints;
}

void ClapTrap::setEnergyPoints(int amount) {
    this->_energyPoints = amount;
}

int ClapTrap::getHitPoints() const {
    return _hitPoints;
}

void ClapTrap::setHitPoints(int amount) {
    this->_hitPoints = amount;
}

int ClapTrap::getAttackDamage() const {
    return _attackDamage;
}

void ClapTrap::setAttackDamage(int amount) {
    this->_attackDamage = amount;
}
