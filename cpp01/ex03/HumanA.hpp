#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA {
private:
    Weapon& _weapon;// referans initlenmek zorunda olduğu için humanA referans humanB pointer olmalı
    std::string _name;

public:
    HumanA(std::string name, Weapon &weapon): _weapon(weapon), _name(name) {}
    void attack() const;
};

#endif
