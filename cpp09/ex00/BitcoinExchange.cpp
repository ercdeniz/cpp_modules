#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string filename)
{
    _inputFile = filename;
}

BitcoinExchange::~BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    *this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    _inputFile = other._inputFile;
    return *this;
}

void BitcoinExchange::readAndParseInputFile()
{
    std::ifstream file(_inputFile.c_str());
    if (!file.is_open())
        throw std::ios_base::failure("could not open file '" + _inputFile + "'");

    std::string line;
    std::getline(file, line); // skip first line
    while (std::getline(file, line))
    {
        std::pair<std::string, std::string> mapline;
        size_t pos = line.find("|");
        if (pos == std::string::npos)
            mapline = std::make_pair(INVALIDTEXT, line);
        else
            mapline = std::make_pair(line.substr(0, pos), line.substr(pos + 1));

        if (mapline.first == INVALIDTEXT || !isValidDate(mapline.first) || atof(mapline.second.c_str()) < 0)
            PRINTRED(mapline.first + " => " + mapline.second);
        else
            PRINTGREEN(mapline.first + " => " + mapline.second);
    }
    file.close();
}
