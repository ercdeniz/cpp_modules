#include "Harl.hpp"

static std::string trim(const std::string& str) {
	if (str.empty())
		return str;
	size_t firstNonSpace = str.find_first_not_of(" \t\n\r\f\v\"\'"); // boşlukları atladıktan sontaki ilk karakterin indexini bulur
	size_t lastNonSpace = str.find_last_not_of(" \t\n\r\f\v\"\'"); // sondan bakar
	if (firstNonSpace == std::string::npos || lastNonSpace == std::string::npos)
		return "";
	return str.substr(firstNonSpace, lastNonSpace - firstNonSpace + 1);
}

int main(int ac, char **av)
{
    if(ac == 2)
    {
        Harl harl;
        int lvl= -1;
        std::string trimmedInput = trim(av[1]);
        std::string values[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };
        for (int i = 0; i < 4; i++) {
            if (trimmedInput == values[i]) {
                lvl = i;
                break;
            }
        }
        harl.complain(lvl);
    }
    else
    {
        std::cout << RED << "Geçersiz argüman!" << RESET << std::endl;
        for (int i = 1; i < ac; i++)
            std::cout << RED << "~>" <<av[i] << RESET << std::endl;
    }
    return 0;
}
