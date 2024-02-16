#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#define RESET "\033[0m"
#define RED "\033[1;31m"
#define PING "\033[38;5;206m"
#define YELLOW "\033[0;33m"
#define PURPLE "\033[0;35m"
#define CYAN "\033[0;36m"
#define GREEN "\033[0;32m"
#define BLUE "\033[0;34m"
#define WHITE "\033[0;37m"

#include <iostream>
#include <cstdlib>  // std::rand, std::srand
#include <ctime>    // std::time


class Zombie
{
    private:
        std::string _name;
    public:
        ~Zombie(void);
        void announce(void);
        void setName( std::string name );

};

Zombie* zombieHorde( int N, std::string name );

#endif
