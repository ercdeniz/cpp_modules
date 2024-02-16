#ifndef WEAPON_HPP
# define WEAPON_HPP

#define RESET "\033[0m"
#define RED "\033[1;31m"
#define YELLOW "\033[0;33m"
#define CYAN "\033[0;36m"
#define PURPLE "\033[0;35m"

#include <iostream>

class Weapon {
private:
    std::string _type;

public:
    Weapon(std::string type): _type(type) {}//burada kullanılan  iki noktadan sonraki sözdizimi init listesi
    const std::string& getType() const;
    void setType(const std::string& newType);
};

#endif
