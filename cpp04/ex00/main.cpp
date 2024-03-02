#include "WrongCat.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    const Animal *meta = new Animal();
    const Animal *j = new Dog();
    const Animal *i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); // will output the cat sound! j->makeSound();
    meta->makeSound();

    std::cout << "----------------------------------------" << std::endl;
    
    WrongAnimal *wrongMeta = new WrongAnimal();
    WrongAnimal *wrongI = new WrongCat();
    wrongI->makeSound();
    wrongMeta->makeSound();
    delete meta;
    delete j;
    delete i;
    delete wrongMeta;
    delete wrongI;
    return 0;
}