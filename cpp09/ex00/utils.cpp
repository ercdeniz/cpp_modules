#include "BitcoinExchange.hpp"
#include <cmath>

static void splitDate(const std::string &date, std::string result[3], char delimiter)
{
	int partIndex = 0;
	std::string::size_type start = 0;
	std::string::size_type end = date.find(delimiter);

	while (end != std::string::npos && partIndex < 3)
	{
		result[partIndex++] = date.substr(start, end - start);
		start = end + 1;
		end = date.find(delimiter, start);
	}
	if (partIndex < 3)
		result[partIndex] = date.substr(start);
}

ValidationResult  BitcoinExchange::isValidDateAndValue(const std::pair<std::string, std::string> mapline)
{
	std::string parts[4];
	splitDate(mapline.first, parts, '-');
	parts[3] = mapline.second;
	for (int i = 0; i < 4; i++)
		parts[i] = trim(parts[i]);
	try
	{
		std::tm pdate = parseDate(mapline.first);
		time_t pdateTime = mktime(&pdate);
		if (pdateTime == -1 || difftime(pdateTime, _ltm) > 0 || difftime(pdateTime, _thresholdDate) < 0)
			return INVALIDDATE;
	}
	catch (const std::invalid_argument &e)
	{
		return INVALIDDATE;
	}
	if (parts[3].empty() || std::count(mapline.second.begin(), mapline.second.end(), '.') > 1
		|| parts[3].find_first_not_of("0123456789.-") != std::string::npos)
		return NOTDIGIT;
	if (parts[3][0] == '-')
		return NOTPOSITIVE;
	float value = atof(parts[3].c_str());
	if (parts[3].size() > 4 || 1000 < value || value < 0)
		return OUTOFBOUNDS;
	return VALID;
}

std::string BitcoinExchange::trim(const std::string &str)
{
	if (str.empty())
		return str;
	size_t firstNonSpace = str.find_first_not_of(" \t\n\r\f\v\"\'");
	size_t lastNonSpace = str.find_last_not_of(" \t\n\r\f\v\"\'");
	if (firstNonSpace == std::string::npos || lastNonSpace == std::string::npos)
		return "";
	return str.substr(firstNonSpace, lastNonSpace - firstNonSpace + 1);
}

std::tm BitcoinExchange::parseDate(const std::string &dateStr)
{
	std::tm tm = {};
	std::istringstream ss(dateStr);
	char delim1, delim2;

	ss >> tm.tm_year >> delim1 >> tm.tm_mon >> delim2 >> tm.tm_mday;
	if (ss.fail() || delim1 != '-' || delim2 != '-'
		|| (tm.tm_year % 4 == 0 && tm.tm_mon == 2 && tm.tm_mday > 29) // leap year
		|| (tm.tm_year % 4 != 0 && tm.tm_mon == 2 && tm.tm_mday > 28) // non-leap year
		|| ((tm.tm_mon == 4 || tm.tm_mon == 6 || tm.tm_mon == 9 || tm.tm_mon == 11) && tm.tm_mday > 30) // 30 days
		|| (tm.tm_mon < 1 || tm.tm_mon > 12 || tm.tm_mday < 1 || tm.tm_mday > 31)
		)
		throw std::invalid_argument("Invalid date");
	return tm;
}

std::string BitcoinExchange::toStr(float value)
{
	std::stringstream ss;
	ss << value;
	return ss.str();
}

int BitcoinExchange::calcualteDayDiff(std::string date, time_t thresholdDate)
{
	std::tm tm = parseDate(date);
	time_t t = mktime(&tm);
	if (t == -1)
		throw std::runtime_error("failed to convert time");
	double diff = difftime(t, thresholdDate) / (60 * 60 * 24);
	return static_cast<int>(diff);
}