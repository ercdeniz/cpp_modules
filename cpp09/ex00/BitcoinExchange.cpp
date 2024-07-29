#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string filename) : _inputFile(filename)
{
	// get current time
	time_t now = time(0);
	if (now == -1)
		throw std::runtime_error("failed to get time");
	tm *ltm = localtime(&now);
	if (!ltm)
		throw std::runtime_error("failed to get local time");
	ltm->tm_year += 1900;
	ltm->tm_mon += 1;
	_ltm = mktime(ltm);
	if (_ltm == -1)
		throw std::runtime_error("failed to convert time");

	// set threshold date
	tm tm = parseDate("2009-01-02");
	if (tm.tm_year == -1)
		throw std::runtime_error("failed to parse date");
	_thresholdDate = mktime(&tm);
	if (_thresholdDate == -1)
		throw std::runtime_error("failed to convert time");
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	*this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
	{
		_inputFile = other._inputFile;
		_ltm = other._ltm;
		_thresholdDate = other._thresholdDate;
		_data = other._data;
	}
	return *this;
}

void BitcoinExchange::dataCalculator(std::pair<std::string, std::string> mapline)
{
	if (std::find(mapline.second.begin(), mapline.second.end(), '.') != mapline.second.end()
		&& std::count(mapline.second.begin(), mapline.second.end(), '.') != 1)
		throw std::ios_base::failure("Invalid data format");

	std::tm tm = parseDate(mapline.first);
	time_t t = mktime(&tm);
	if (t == -1)
		throw std::runtime_error("failed to convert time");

	double diff = difftime(t, _thresholdDate) / (86400.0); // (60 * 60 * 24)
	if (diff < 0)
		throw std::runtime_error("Invalid date");
	std::pair<int, float> data = std::make_pair(static_cast<int>(diff), atof(mapline.second.c_str()));
	_data.insert(data);
}

void BitcoinExchange::readAndParseDataFile()
{
	std::ifstream file("data.csv");
	if (!file.is_open())
		throw std::ios_base::failure("could not open file 'data.csv'");
	if (file.peek() == std::ifstream::traits_type::eof())
		throw std::ios_base::failure("file is empty");

	std::string line;
	std::getline(file, line); // skip first line

	while (std::getline(file, line))
	{
		std::pair<std::string, std::string> mapline;
		size_t pos = line.find(",");
		if (pos == std::string::npos)
			throw std::ios_base::failure("Invalid data format");
		else
			mapline = std::make_pair(trim(line.substr(0, pos)), trim(line.substr(pos + 1)));
		dataCalculator(mapline);
	}
	file.close();
}

void BitcoinExchange::inputCalculator(std::pair<std::string, std::string> mapline)
{
	switch (isValidDateAndValue(mapline))
	{
		case ::INVALIDDATE:
			PRINTRED("Error: Invalid date => " + mapline.first);
			break;
		case ::NOTDIGIT:
			PRINTRED("Error: Not digit => " + mapline.second);
			break;
		case ::OUTOFBOUNDS:
			PRINTRED("Error: Out of bounds => " + mapline.second);
			break;
		case ::NOTPOSITIVE:
			PRINTRED("Error: Not positive => " + mapline.second);
			break;
		default:
			int dayDiff = calcualteDayDiff(mapline.first, _thresholdDate);
			double amount = 0;
			for (std::set<std::pair<int, float> >::iterator it = _data.begin(); it != _data.end(); ++it)
			{
				if (it->first == dayDiff)
				{
					amount = it->second * atof(mapline.second.c_str());
					break;
				}
				else if (it->first > dayDiff)
				{
					it--;
					amount = it->second * atof(mapline.second.c_str());
					break;
				}
				else if (it == --_data.end())
				{
					amount = it->second * atof(mapline.second.c_str());
					break;
				}
			}
			std::ostringstream out;
			out << std::setprecision(std::numeric_limits<float>::digits10 + 1) << amount;
			PRINTGREEN("On " + mapline.first + ", " + mapline.second + " btc is worth " + out.str() + " usd");
	}
}

void BitcoinExchange::readAndParseInputFile()
{
	std::ifstream file(_inputFile.c_str());
	if (!file.is_open())
		throw std::ios_base::failure("could not open file '" + _inputFile + "'");
	if (file.peek() == std::ifstream::traits_type::eof())
		throw std::ios_base::failure("file is empty");

	std::string line;
	std::getline(file, line); // skip first line
	if (line != "date | value")
		throw std::ios_base::failure("Invalid input format");
	while (std::getline(file, line))
	{
		std::pair<std::string, std::string> mapline;
		size_t pos = line.find("|");
		if (pos == std::string::npos)
		{
			PRINTRED("Error: Bad input => " + line);
			continue;
		}
		else
			mapline = std::make_pair(trim(line.substr(0, pos)), trim(line.substr(pos + 1)));
		inputCalculator(mapline);
	}
	file.close();
}
