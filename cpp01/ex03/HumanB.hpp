#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB {
	private:
		Weapon* _weapon;
		std::string _name;
	public:
		HumanB(std::string name): _weapon(0), _name(name) {}//init listesinin sırası private değişkenlerin sırası ile aynı olmalı.
		void attack() const;
		void setWeapon(const Weapon &weapon);
};

#endif
