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
    if(ac == 1)
    {
        Harl harl;
        std::string userInput;
        int lvl= -1;
        std::string values[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };

        std::cout <<YELLOW<< "Log seviyesini girin (DEBUG, INFO, WARNING, ERROR): "<< RESET;
        std::getline(std::cin, userInput);
        userInput = trim(userInput);

        for (int i = 0; i < 4; i++) {
            if (userInput == values[i]) {
                lvl = i;
                break;
            }
        }
        harl.complain(lvl);
    }
    else
    {
        std::cout <<RED<< "Geçersiz argüman!" <<RESET<< std::endl;
        for (int i = 1; i < ac; i++)
            std::cout <<RED<< "~>" << YELLOW <<av[i] <<RESET<< std::endl;
    }
    return 0;
}
