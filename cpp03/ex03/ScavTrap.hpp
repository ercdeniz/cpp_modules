#ifndef SCARVTRAP_HPP
#define SCARVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
    private:
        ScavTrap();
    public:
        ScavTrap(std::string name);
        ScavTrap(const ScavTrap &scavTrap);
        ~ScavTrap();
        ScavTrap &operator=(const ScavTrap &scavTrap);
        void attack(std::string const & target);
        void guardGate();
};

#endif // SCARVTRAP_HPP