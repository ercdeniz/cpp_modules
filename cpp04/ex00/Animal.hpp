#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#define RED "\033[0;31m"
#define GREEN "\033[1;32m"
#define CYAN "\033[0;36m"
#define YELLOW "\033[1;33m"
#define PURPLE "\033[0;35m"
#define RESET "\033[0m"

# define S_RED "\033[2;31m"
# define S_GREEN "\033[2;32m"
# define S_YELLOW "\033[2;33m"
# define S_BLUE "\033[2;34m"
# define S_MAGENTA "\033[2;35m"
# define S_CYAN "\033[2;36m"
# define S_WHITE "\033[2;37m"

#include <iostream>

class Animal
{
    protected:
        std::string _type;
    public:
        Animal();
        Animal(std::string type);
        Animal(const Animal &animal);
        virtual ~Animal();
        Animal &operator=(const Animal &animal);
        std::string getType() const;
        void setType(std::string type);
        virtual void makeSound() const;
};

#endif // ANIMAL_HPP