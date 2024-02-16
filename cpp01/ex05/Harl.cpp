#include "Harl.hpp"

void Harl::debug()
{
    std::cout << PURPLE << "7XL-çift peynirli-üçlü turşu-özel-ketçaplı burgerime fazladan domuz pastırması yemeyi seviyorum. Gerçekten seviyorum!" << RESET << std::endl;
}

void Harl::info()
{
    std::cout << PURPLE << "Ekstra domuz pastırması eklemenin daha fazla paraya mal olduğuna inanamıyorum. Burgerime yeterince pastırma koymadınız! Yapsaydınız, daha fazlasını istemezdim!" << RESET << std::endl;
}

void Harl::warning()
{
    std::cout << PURPLE << "Bence bedavaya fazladan pastırma yemeyi hak ediyorum. Ben yıllardır geliyorum, sen geçen aydan beri burada çalışmaya başladın." << RESET << std::endl;
}

void Harl::error()
{
    std::cout << PURPLE << "Bu kabul edilemez! Şimdi müdürle konuşmak istiyorum."<< RESET << std::endl;
}

void Harl::complain(int level)
{
    switch (level)
    {
    case 0:
        Harl::debug();
        break;
    case 1:
        Harl::info();
        break;
    case 2:
        Harl::warning();
        break;
    case 3:
        Harl::error();
        break;
    default:
        std::cout << RED << "Geçersiz girdi. Lütfen DEBUG, INFO, WARNING veya ERROR girin." << RESET << std::endl;
    }
}
