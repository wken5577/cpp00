#include "Contact.hpp"
#include <iostream>

Contact::Contact(std::string firstName, std::string	lastName, \
		std::string nickname, std::string phoneNumber, std::string darkestSecret)
{
	this->firstName = firstName;
	this->lastName = lastName;
	this->nickname = nickname;
	this->phoneNumber = phoneNumber;
	this->darkestSecret = darkestSecret;
}

std::string Contact::getFirstName()
{
	return this->firstName;
}

std::string Contact::getLastName()
{
	return this->lastName;
}

std::string Contact::getNickname()
{
	return this->nickname;
}

std::string Contact::getPhoneNumber()
{
	return this->phoneNumber;
}

void	Contact::print()
{
	std::cout << "firstName : ";
	std::cout << this->firstName << std::endl;
	std::cout << "lastName : ";
	std::cout << this->lastName << std::endl;
	std::cout << "nickname : ";
	std::cout << this->nickname << std::endl;
	std::cout << "phoneNumber : ";
	std::cout << this->phoneNumber << std::endl;
	std::cout << "darkestSecret : ";
	std::cout << this->darkestSecret << std::endl;
}
