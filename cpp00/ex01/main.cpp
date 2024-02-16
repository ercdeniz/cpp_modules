#include "PhoneBook.hpp"

static std::string trim(const std::string& str) {
	if (str.empty())
		return str;
	size_t firstNonSpace = str.find_first_not_of(" \t\n\r\f\v\"\'"); // boşlukları atladıktan sontaki ilk karakterin indexini bulur
	size_t lastNonSpace = str.find_last_not_of(" \t\n\r\f\v\"\'"); // sondan bakar
	if (firstNonSpace == std::string::npos || lastNonSpace == std::string::npos)
		return "";
	return str.substr(firstNonSpace, lastNonSpace - firstNonSpace + 1);
}

void introduction()
{
	std::cout << CYAN << "--------------------------------------------------------" << std::endl;
	std::cout << RED << "	      📞Welcome to the phonebook📔"<< std::endl;
	std::cout << BLUE << "	    You can use the following commands:"<< std::endl;
	std::cout << YELLOW << "		  ADD: add a new contact"<< std::endl;
	std::cout << YELLOW << "	       SEARCH: search for a contact"<< std::endl;
	std::cout << YELLOW << "		 EXIT: exit the phonebook"<< std::endl;
	std::cout << PURPLE << "		 Please enter a command:"<< std::endl;
	std::cout << CYAN << "--------------------------------------------------------" << RESET << std::endl;
}
int main(void) {

	std::string input="";
	Contact contact;
	PhoneBook phonebook;

	introduction();
	while(input.compare("EXIT"))
	{
		if(!input.compare("ADD"))
			phonebook.addContact();
		else if (!input.compare("SEARCH"))
			phonebook.searchContact();
		else if(!input.find_first_not_of(" "))
			std::cout << RED << "!!! invalid command !!!" << RESET << std::endl;
		std::cout << CYAN<< "> " << RESET<< std:: flush;
		std::getline(std::cin, input);
		input = trim(input);
	}
	return 0;
}
