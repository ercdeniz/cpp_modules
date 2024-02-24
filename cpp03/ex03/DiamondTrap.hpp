#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
    private:
        std::string _name;
        DiamondTrap();
    public:
        DiamondTrap(const std::string name);
        DiamondTrap(const DiamondTrap& other);
        ~DiamondTrap();
        DiamondTrap& operator=(const DiamondTrap& other);
        void attack(const std::string& target);
        void whoAmI();

        const std::string& getDiamondName() const;
        void setDiamondName(const std::string& name);
};

#endif // DIAMONDTRAP_HPP