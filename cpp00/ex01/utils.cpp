#include "PhoneBook.hpp"

static std::string shortner(std::string str)
{
    std::string new_str;

    for(int i = 0; i < 9; i++)
        new_str += str[i];
    new_str += '.';
    return (new_str);
}

static std::string fill_str(std::string str)
{
    std::string new_str;
    int space_count;

    space_count = 10 - str.length();
    for (int i = 0; i < space_count; i++)
        new_str += " ";
    new_str += str;
    return (new_str);
}
int PhoneBook::str_to_int(std::string str)
{
    int num = 0;

    if(str.length() == 0)
        return (-1);
    for (size_t i = 0; i < (str.length()); i++)
        if(str[i] >= '0' && str[i] <= '9')
            num = num * 10 + (str[i] - '0');
        else
            return (-1);
    return (num);
}
bool PhoneBook::isdigit(std::string str)
{
    for (size_t i = 0; i < (str.length()); i++)
        if (str[i] < '0' || str[i] > '9')
            return (false);
    return (true);
}

void PhoneBook::print_phonebook(PhoneBook *phonebook)
{
    std::cout << BLUE
        << "-------------------------------------------" << std::endl
        << "     index|" << "      name|" << "   surname|" << "  nickname" << std::endl
        << "-------------------------------------------" << RESET << std::endl;
    for(int i = 0; i < (*phonebook)._indexCheck; i++)
    {
        std::cout << BLUE
            << "         " << i << "|" << (*phonebook)._contact[i].getFirstName()
            << "|" << (*phonebook)._contact[i].getLastName() << "|" << (*phonebook)._contact[i].getNickname()
            << std::endl << "-------------------------------------------" << RESET<<  std::endl;
    }
}

void PhoneBook::formatter(PhoneBook *phonebook)
{
    std::string new_str;

    for(int i = 0; i < (*phonebook)._indexCheck; i++)
    {
        if ((*phonebook)._contact[i].getFirstName().length() > 10)
        {
            new_str = shortner((*phonebook)._contact[i].getFirstName());
            (*phonebook)._contact[i].setFirstName(new_str);
        }
        else
        {
            new_str = fill_str((*phonebook)._contact[i].getFirstName());
            (*phonebook)._contact[i].setFirstName(new_str);
        }

        if ((*phonebook)._contact[i].getLastName().length() > 10)
        {
            new_str = shortner((*phonebook)._contact[i].getLastName());
            (*phonebook)._contact[i].setLastName(new_str);
        }
        else
        {
            new_str = fill_str((*phonebook)._contact[i].getLastName());
            (*phonebook)._contact[i].setLastName(new_str);
        }

        if ((*phonebook)._contact[i].getNickname().length() > 10)
        {
            new_str = shortner((*phonebook)._contact[i].getNickname());
            (*phonebook)._contact[i].setNickname(new_str);
        }
        else
        {
            new_str = fill_str((*phonebook)._contact[i].getNickname());
            (*phonebook)._contact[i].setNickname(new_str);
        }

        if ((*phonebook)._contact[i].getPhoneNumber().length() > 10)
        {
            new_str = shortner((*phonebook)._contact[i].getPhoneNumber());
            (*phonebook)._contact[i].setPhoneNumber(new_str);
        }
        else
        {
            new_str = fill_str((*phonebook)._contact[i].getPhoneNumber());
            (*phonebook)._contact[i].setPhoneNumber(new_str);
        }

        if ((*phonebook)._contact[i].getDarkestSecret().length() > 10)
        {
            new_str = shortner((*phonebook)._contact[i].getDarkestSecret());
            (*phonebook)._contact[i].setDarkestSecret(new_str);
        }
        else
        {
            new_str = fill_str((*phonebook)._contact[i].getDarkestSecret());
            (*phonebook)._contact[i].setDarkestSecret(new_str);
        }
    }
}
