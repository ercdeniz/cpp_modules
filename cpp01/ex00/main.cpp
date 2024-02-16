#include <iostream>
#include "Zombie.hpp"
int main(int ac, char **av)
{
    if(ac == 1){
        Zombie zombie1("first");
        zombie1.announce();
        Zombie *zombie2 = newZombie("second");
        zombie2->announce();
        delete zombie2; // yer ayırdığımız zombie2'yi siliyoruz
        randomChump("third");
        return 0;
    }else{
        std::cout <<RED<< "Geçersiz argüman!" <<RESET<< std::endl;
        for (int i = 1; i < ac; i++)
            std::cout <<RED<< "~>" << YELLOW <<av[i] <<RESET<< std::endl;
    }
}
