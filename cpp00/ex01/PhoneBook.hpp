#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#define RESET "\033[0m"
#define RED "\033[1;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define CYAN "\033[0;36m"
#define PURPLE "\033[0;35m"

# include "Contact.hpp"

class PhoneBook
{
	private:
		Contact _contact[8];
		int _indexCheck;
	public:
		PhoneBook(){
			_indexCheck = 0;
		}
		void addContact();
		void searchContact();
		void formatter(PhoneBook *phonebook);
		void print_phonebook(PhoneBook *phonebook);
		bool isdigit(std::string str);
		int str_to_int(std::string str);
};
#endif
