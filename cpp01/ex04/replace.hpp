#ifndef REPLACE_HPP
#define REPLACE_HPP


#define RESET "\033[0m"
#define RED "\033[1;31m"
#define YELLOW "\033[0;33m"
#define CYAN "\033[0;36m"
#define PURPLE "\033[0;35m"
#define GREEN "\033[0;32m"

#include <iostream>
#include <fstream>

class Replace
{
    private:
        std::string _filename;
        std::string _s1;
        std::string _s2;
    public:
        Replace(std::string filename, std::string s1, std::string s2) : _filename(filename), _s1(s1), _s2(s2) {}
        void replaceInFile();
};

#endif
