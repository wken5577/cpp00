#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <string>

class Contact
{
private:
	std::string	firstName;
	std::string	lastName;
	std::string	nickname;
	std::string	phoneNumber;

public :
	Contact(std::string	firstName, std::string	lastName, \
		std::string	nickname, std::string	phoneNumber);
	std::string	getFirstName();
	std::string	getLastName();
	std::string	getNickname();
	std::string getPhoneNumber();
	void		print();
};

#endif