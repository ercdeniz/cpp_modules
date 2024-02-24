#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
    private:
        FragTrap(void);
    public:
        FragTrap(std::string name);
        FragTrap(const FragTrap &src);
        ~FragTrap(void);
        FragTrap &operator=(const FragTrap &src);
        void attack(std::string const & target);
        void highFivesGuys(void);
};

#endif // FRAGTRAP_HPP