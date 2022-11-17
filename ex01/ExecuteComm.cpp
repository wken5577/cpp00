#include "PhoneBook.hpp"
#include <iostream>

#define ERR_NAME_MSG "accept only alphabet!!"
#define ERR_NUM_MSG "accept only number!!"
#define ERR_INVALID_IDX_MSG "invalid idx!!!"

static bool	validationName(std::string name)
{
	for(unsigned int i = 0; i < name.length(); i++)
	{
		if (!std::isalpha(name.at(i)))
		{
			std::cout << ERR_NAME_MSG << std::endl;
			return false;
		}
	}
	return true;
}

static std::string	getName(std::string display)
{
	std::string	name;
	while (1)
	{
		std::cout << display << " : ";
		std::getline(std::cin, name);
		if (validationName(name))
			break;
	}
	return name;
}

static bool	validationNumber(std::string number)
{
	for(unsigned int i = 0; i < number.length(); i++)
	{
		if (!std::isdigit(number.at(i)))
		{
			std::cout << ERR_NUM_MSG << std::endl;
			return false;
		}
	}
	return true;
}

static std::string	getNumber()
{
	std::string	number;
	while (1)
	{
		std::cout << "phoneNumber : ";
		std::getline(std::cin, number);
		if (validationNumber(number))
			break;
	}
	return number;
}

static Contact	*getData()
{
	std::string	firstName;
	std::string	lastName;
	std::string	nickname;
	std::string	phoneNumber;

	firstName = getName("firstName");
	lastName = getName("lastName");
	nickname = getName("nickname");
	phoneNumber = getNumber();
	return new Contact(firstName, lastName, nickname, phoneNumber);
}

void	executeAdd(PhoneBook *pb)
{
	Contact	*data = getData();
	pb->addData(data);
}

static int getTargetIdx()
{
	std::string	idx;
	int 		result;


	std::cout << "target id : ";
	std::getline(std::cin, idx);
	result = std::atoi(idx.data());
	if (idx.length() != 1 || !std::isdigit(idx[0]) || \
		!(0 <= result && result <= 7))
	{
		std::cout << ERR_INVALID_IDX_MSG << std::endl;
		return -1;
	}
	return result;
}

void	executeSearch(PhoneBook *pb)
{
	int 	idx;
	Contact *data;

	pb->print();
	idx = getTargetIdx();
	if (idx == -1)
		return;
	data = pb->search(idx);
	if (!data)
		std::cout << ERR_INVALID_IDX_MSG << std::endl;
	else
		data->print();
}
