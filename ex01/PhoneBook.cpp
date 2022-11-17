#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>

PhoneBook::PhoneBook()
{
	this->idx = 0;
	for(int i = 0; i < 8; i++)
	{
		this->arr[i] = NULL;
	}
}

PhoneBook::~PhoneBook()
{
	for(int i = 0; i < this->idx; i++)
	{
		delete this->arr[i];
	}
}

void PhoneBook::addData(Contact* data)
{
	if (this->idx == 8)
	{
		removeFirstData();
		this->arr[7] = data;
	}
	else
	{
		this->arr[this->idx] = data;
		this->idx += 1;
	}
}

Contact* PhoneBook::search(int idx)
{
	if (idx < 0 || idx > 7 || idx >= this->idx)
		return (NULL);
	return (this->arr[idx]);
}

void PhoneBook::removeFirstData()
{
	delete this->arr[0];
	for(int i = 1; i < 8; i++)
	{
		this->arr[i - 1] = this->arr[i];
	}
}

void	PhoneBook::printOneString(std::string str)
{
	if (str.size() <= 10)
	{
		int spaseSize = 10 - str.size();
		for(int i = 0; i < spaseSize; i++)
			std::cout << " ";
		std::cout << str;
	}
	else
	{
		for(int i = 0; i < 10; i++)
		{
			if (i != 9)
				std::cout << str[i];
			else
				std::cout << ".";
		}
	}
	std::cout << " | ";
}

void	PhoneBook::print()
{
	printOneString("idx");
	printOneString("firstname");
	printOneString("lastname");
	printOneString("nickname");
	std::cout << std::endl;
	std::cout << "====================================================" << std::endl;
	for(int i = 0; i < this->idx; i++)
	{
		Contact *tar = this->arr[i];
		printOneString(std::to_string(i));
		printOneString(tar->getFirstName());
		printOneString(tar->getLastName());
		printOneString(tar->getNickname());
		std::cout << std::endl;
	}
}