# ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public AAnimal
{
    private:
        Brain *_brain;
    public:
        Cat();
        Cat(const Cat &cat);
        Cat &operator=(const Cat &cat);
        ~Cat();

        void makeSound() const;
        
        Brain *getBrain() const;
};

# endif // CAT_HPP