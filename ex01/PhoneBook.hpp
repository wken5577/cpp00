
#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP

#include "Contact.hpp"

class PhoneBook 
{
private:
	Contact *arr[8];
	int 	idx;

public:
	PhoneBook();
	~PhoneBook();
	void	addData(Contact *data);
	Contact *search(int idx);
	void	print();
private:
	void	removeFirstData();
	void	printOneString(std::string str);
};

#endif