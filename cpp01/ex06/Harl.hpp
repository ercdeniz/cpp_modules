#ifndef HARL_HPP
#define HARL_HPP

#define RESET "\033[0m"
#define RED "\033[1;31m"
#define PING "\033[38;5;206m"
#define YELLOW "\033[0;33m"
#define PURPLE "\033[0;35m"
#define CYAN "\033[0;36m"

#include <iostream>

class Harl
{
private:
    void debug(void);
    void info(void);
    void warning(void);
    void error(void);

public:
    void complain(int level);
};

#endif
