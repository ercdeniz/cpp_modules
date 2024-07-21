#include "BitcoinExchange.hpp"

static std::string trim(const std::string& str) {
	if (str.empty())
		return str;
	size_t firstNonSpace = str.find_first_not_of(" \t\n\r\f\v\"\'"); // boşlukları atladıktan sontaki ilk karakterin indexini bulur
	size_t lastNonSpace = str.find_last_not_of(" \t\n\r\f\v\"\'"); // sondan bakar
	if (firstNonSpace == std::string::npos || lastNonSpace == std::string::npos)
		return "";
	return str.substr(firstNonSpace, lastNonSpace - firstNonSpace + 1);
}


void splitDate(const std::string& date, char delimiter, std::string result[DATE_PARTS]) {
	int partIndex = 0;
	std::string::size_type start = 0;
	std::string::size_type end = date.find(delimiter);

	while (end != std::string::npos && partIndex < DATE_PARTS) {
		result[partIndex++] = date.substr(start, end - start);
		start = end + 1;
		end = date.find(delimiter, start);
	}
	if (partIndex < DATE_PARTS)
		result[partIndex] = date.substr(start);
}

bool BitcoinExchange::isValidDate(const std::string& date) {
	std::string parts[DATE_PARTS];
	splitDate(date, '-', parts);
	for (int i = 0; i < DATE_PARTS; i++)
		parts[i] = trim(parts[i]);
	for (int i = 0; i < DATE_PARTS; i++){
		for (size_t j = 0; j < parts[i].length(); j++) 
			if (!isdigit(parts[i][j]))
				return false;
		parts[i] = std::to_string(std::atoi(parts[i].c_str()));
	}
	
	return true;
}