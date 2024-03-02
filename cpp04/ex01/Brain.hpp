#ifndef BRAIN_HPP
#define BRAIN_HPP

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

class Brain
{
    private:
        std::string ideas[100];
    public:
        Brain();
        Brain(const Brain &brain);
        ~Brain();
        Brain &operator=(const Brain &brain);
        
        std::string getIdea(int index) const;
        void setIdea(int index, std::string idea);
};

#endif // BRAIN_HPP