#include "Contact.hpp"

Contact::Contact()
{
	this->_firstName = "";
	this->_lastName = "";
	this->_nickname = "";
	this->_phoneNumber = "";
	this->_darkestSecret = "";
}

const std::string& Contact::getFirstName() const
{
	return (this->_firstName);
}

const std::string& Contact::getLastName() const
{
	return (this->_lastName);
}

const std::string& Contact::getNickname() const
{
	return (this->_nickname);
}

const std::string& Contact::getPhoneNumber() const
{
	return (this->_phoneNumber);
}

const std::string& Contact::getDarkestSecret() const
{
	return (this->_darkestSecret);
}

void Contact::setFirstName(const std::string firstName)
{
	this->_firstName = firstName;
}

void Contact::setLastName(const std::string lastName)
{
	this->_lastName = lastName;
}

void Contact::setNickname(const std::string nickName)
{
	this->_nickname = nickName;
}

void Contact::setPhoneNumber(const std::string phoneNumber)
{
	this->_phoneNumber = phoneNumber;
}

void Contact::setDarkestSecret(const std::string darkestSecret)
{
	this->_darkestSecret = darkestSecret;
}
