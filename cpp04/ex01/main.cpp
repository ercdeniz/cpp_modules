#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    const Animal *j = new Dog();
    const Animal *i = new Cat();
    j->makeSound();
    i->makeSound();
    Cat c;
    Dog d;
    c.getBrain()->setIdea(0, "I am a cat");
    c.getBrain()->setIdea(100, "I am 100. cat");
    d.getBrain()->setIdea(0, "I am not a cat");
    std::cout << S_MAGENTA << (c.getBrain()->getIdea(0)) << RESET << std::endl;
    std::cout << S_MAGENTA << (c.getBrain()->getIdea(100)) << RESET << std::endl;
    std::cout << S_MAGENTA << (d.getBrain()->getIdea(0)) << RESET << std::endl;
    delete j; // should not create a leak
    delete i;
    return 0;
}