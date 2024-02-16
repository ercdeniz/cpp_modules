#include "Zombie.hpp"

int main(int ac, char **av)
{
    if(ac==1)
    {
        std::string input;
        int size;

        std::srand(std::time(0));
        std::cout << GREEN << "Enter the number of zombies you want to create(min: 1 max: INT_MAX): " << RESET;
        std::getline(std::cin, input);
        size = std::atoi(input.c_str());//char pointera çevir
        if (size <= 0 || size > INT_MAX)
            return(std::cout << RED << "Invalid number of zombies" << RESET << std::endl, 1);
        Zombie *zhorde;
        zhorde = zombieHorde(size, "ercdeniz");
        for (int i = 0; i < size; i++) zhorde[i].announce();
        delete[] zhorde;
    }
    else
    {
        std::cout <<RED<< "Geçersiz argüman!" <<RESET<< std::endl;
        for (int i = 1; i < ac; i++)
            std::cout <<RED<< "~>" << YELLOW <<av[i] <<RESET<< std::endl;
    }
}
