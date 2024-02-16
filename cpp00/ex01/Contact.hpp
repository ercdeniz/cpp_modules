#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

class Contact
{
    private:
        std::string _firstName;
        std::string _lastName;
        std::string _nickname;
        std::string _phoneNumber;
        std::string _darkestSecret;

    public:
        Contact();
        const std::string& getFirstName() const;
        const std::string& getLastName() const;
        const std::string& getNickname() const;
        const std::string& getPhoneNumber() const;
        const std::string& getDarkestSecret() const;

        void setFirstName(const std::string firstName);
        void setLastName(const std::string lastName);
        void setNickname(const std::string nickname);
        void setPhoneNumber(const std::string phoneNumber);
        void setDarkestSecret(const std::string darkestSecret);
};

#endif
