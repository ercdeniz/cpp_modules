#include "replace.hpp"

int main(int ac, char** av) {
    if (ac != 4) {
        std::cerr << RED << "UPS, Try Again!\nUsage: "<< YELLOW << av[0] << " <filename> <s1> <s2>" << RESET << std::endl;
        return 1;
    }
    Replace replace(av[1], av[2], av[3]);
    replace.replaceInFile();
    return 0;
}
