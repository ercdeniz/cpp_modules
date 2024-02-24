#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#define RESET       "\033[0m"
#define RED         "\033[31m"
#define GREEN       "\033[32m"
#define YELLOW      "\033[33m"
#define CYAN        "\033[36m"
#define PURPLE      "\033[95m"
#define BOLD        "\033[1m"
#define UNDERLINE   "\033[4m"

#include <iostream>

class ClapTrap {
    private:
        std::string _name;
        int _hitPoints;
        int _energyPoints;
        int _attackDamage;

    public:
        ClapTrap(const std::string& name);
        ClapTrap(const ClapTrap& other);
        ~ClapTrap();
        ClapTrap& operator=(const ClapTrap& other);
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

        std::string getName() const;
        void setName(const std::string& name);
        int getAttackDamage() const;
        void setAttackDamage(int amount);
        int getEnergyPoints() const;
        void setEnergyPoints(int amount);
        int getHitPoints() const;
        void setHitPoints(int amount);
};

#endif