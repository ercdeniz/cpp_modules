#include "PhoneBook.hpp"

void PhoneBook::addContact()
{
    static int i;
    std::string name = "",surname = "", nickname = "", number = "", secret = "";

    if (i == 8)
        i = 0;
    std::cout << YELLOW <<  "Enter Name: " << RESET;
    getline(std::cin, name, '\n');
    while (name.length() == 0)
    {
        std::cout << RED << "This space cannot be EMPTY! Please enter a value." << RESET <<  std::endl;
        std::cout << YELLOW <<  "Enter Name: " << RESET;
        getline(std::cin, name, '\n');
    }

    std::cout << YELLOW <<  "Enter Surname: " << RESET;
    getline(std::cin, surname);
    while (surname.length() == 0)
    {
        std::cout << RED << "This space cannot be EMPTY! Please enter a value" << RESET <<  std::endl;
        std::cout << YELLOW <<  "Enter Surname: " << RESET;
        getline(std::cin, surname, '\n');
    }

    std::cout << YELLOW <<  "Enter Nickname: " << RESET;
    getline(std::cin, nickname);
    while (nickname.length() == 0)
    {
        std::cout << RED << "This space cannot be EMPTY! Please enter a value" << RESET <<  std::endl;
        std::cout << YELLOW <<  "Enter Nickname: " << RESET;
        getline(std::cin, nickname, '\n');
    }

    std::cout << YELLOW <<  "Enter Number: " << RESET;
    getline(std::cin, number);
    while (number.length() == 0 || isdigit(number) == false)
    {
        std::cout << RED << "Don't forget, it's a NUMBERS only zone!" << RESET <<  std::endl;
        std::cout << YELLOW <<  "Enter Number: " << RESET;
        getline(std::cin, number, '\n');
    }
    std::cout << YELLOW <<  "Enter Darkest Secret: " << RESET;
    getline(std::cin, secret);
    while (secret.length() == 0)
    {
        std::cout << RED << "This space cannot be EMPTY! Please enter a value" << RESET <<  std::endl;
        std::cout << YELLOW <<  "Enter Darkest Secret: " << RESET;
        getline(std::cin, secret, '\n');
    }

    this->_contact[i].setFirstName(name);
    this->_contact[i].setLastName(surname);
    this->_contact[i].setNickname(nickname);
    this->_contact[i].setPhoneNumber(number);
    this->_contact[i].setDarkestSecret(secret);
    i++;
    if (this->_indexCheck < 8)
        this->_indexCheck++;
    std::cout << GREEN <<"Person has been added!" << RESET << std::endl;
}

void PhoneBook::searchContact()
{
    int searchedIndex;
    std::string strIndex="";
    PhoneBook tmp;

    tmp = *this;
    formatter(&tmp);
    print_phonebook(&tmp);

    std::cout << PURPLE <<"Enter row that you want to search... " << RESET;
    getline(std::cin, strIndex);
    searchedIndex = str_to_int(strIndex);
    if (searchedIndex == -1)
    {
        std::cout << RED "str_to_int-> Error: Invalid input." << RESET << std::endl;
        return ;
    }
    if (searchedIndex > this->_indexCheck - 1 || searchedIndex < 0)
    {
        std::cout << RED << "There is NOBODY on this number!" << RESET << std::endl;
        return ;
    }
    std::cout << BLUE
        << "Name:             |" <<this->_contact[searchedIndex].getFirstName() << std::endl
        << "-----------------------------------------------------------------" << std::endl
        << "Surname:          |" <<this->_contact[searchedIndex].getLastName() << std::endl
        << "-----------------------------------------------------------------" << std::endl
        << "Nick:             |" <<this->_contact[searchedIndex].getNickname() << std::endl
        << "-----------------------------------------------------------------" << std::endl
        << "Phone Number:     |" <<this->_contact[searchedIndex].getPhoneNumber()<< std::endl
        << "-----------------------------------------------------------------" << std::endl
        << "Darkest Secret:   |" <<this->_contact[searchedIndex].getDarkestSecret() << std::endl
        << "-----------------------------------------------------------------" << RESET << std::endl;
}
