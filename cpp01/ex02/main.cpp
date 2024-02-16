#include <iostream>

int main(int ac, char **av)
{
    const std::string RESET = "\033[0m";
    const std::string YELLOW = "\033[93m";
    const std::string CYAN = "\033[96m";
    const std::string PURPLE = "\033[95m";
    const std::string RED = "\033[91m";

    if(ac==1){
        std::string String = "HI THIS IS BRAIN";
        std::string* stringPTR = &String;
        std::string& stringREF = String;

        std::cout << PURPLE << "String değişkeninin bellek adresi: " << YELLOW <<  &String  <<  std::endl
            << PURPLE << "StringPTR pointer değişkeninin bellek adresi: " << YELLOW <<  stringPTR <<  std::endl
            << PURPLE << "StringREF referans değişkeninin bellek adresi: "<< YELLOW << &stringREF <<  std::endl
            << CYAN <<"-----------------------------------------" << std::endl
            << RED << "String değişkeninin değeri: " << YELLOW <<  String << std::endl
            << RED << "StringPTR pointer değişkeninin değeri: " << YELLOW <<  *stringPTR<< std::endl
            << RED << "StringREF referans değişkeninin değeri: " << YELLOW << stringREF << RESET << std::endl;
    return 0;
    }else{
        std::cout <<RED<< "Geçersiz argüman!" <<RESET<< std::endl;
        for (int i = 1; i < ac; i++)
            std::cout <<RED<< "~>" << YELLOW <<av[i] <<RESET<< std::endl;
    }
}
