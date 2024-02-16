#include "Harl.hpp"

void Harl::debug()
{
    std::cout << CYAN << "[ DEBUG ]\n"
        << "7XL-çift peynirli-üçlü turşu-özel-ketçaplı burgerime fazladan domuz pastırması yemeyi seviyorum.\nGerçekten seviyorum!"
        << RESET << std::endl << std::endl;
}

void Harl::info()
{
    std::cout << YELLOW << "[ INFO ]\n"
        << "Ekstra domuz pastırması eklemenin daha fazla paraya mal olduğuna inanamıyorum.\nBurgerime yeterince pastırma koymadınız!\nKoysaydınız, daha fazlasını istemezdim!"
        << RESET << std::endl << std::endl;
}

void Harl::warning()
{
    std::cout << PURPLE << "[ WARNING ]\n"
        << "Bence bedavaya fazladan pastırma yemeyi hak ediyorum.\nBen yıllardır geliyorum, sen ise geçen aydan beri burada çalışmaya başladın."
        << RESET << std::endl <<std::endl;
}

void Harl::error()
{
    std::cout << PING << "[ ERROR ]\n"
        <<"Bu kabul edilemez, şimdi müdürünle konuşmak istiyorum!"<<RESET<< std::endl << std::endl;
}

void Harl::complain(int level)
{
    switch (level)
    {
        case 0:
            debug();
            complain(1);
            break;
        case 1:
            info();
            complain(2);
            break;
        case 2:
            warning();
            complain(3);
            break;
        case 3:
            error();
            break;
        default:
            std::cout << RED << "Geçersiz girdi. Lütfen DEBUG, INFO, WARNING veya ERROR girin." << RESET << std::endl;
    }
}
