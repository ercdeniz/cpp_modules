#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#define RESET "\033[0m"
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define CYAN "\033[0;36m"
#define YELLOW "\033[1;33m"

#include <iostream>

class Zombie
{
    private:
        std::string _name;
    public:
        Zombie(std::string name);
        ~Zombie(void);
        void announce(void);
};

void randomChump(std::string name);
Zombie *newZombie(std::string name);

#endif
