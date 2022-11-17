#include "PhoneBook.hpp"
#include <iostream>

void	executeAdd(PhoneBook *pb);
void	executeSearch(PhoneBook *pb);

typedef enum COMM_TYPE
{
	COMM_ADD = 0,
	COMM_SEARCH,
	COMM_EXIT,
	COMM_IGN
} COMM_TYPE;

COMM_TYPE readCommand()
{
	std::string comm;

	std::cout << "command : ADD, SEARCH, EXIT" << std::endl;
	std::getline(std::cin, comm);
	if (comm.compare("EXIT") == 0)
		return COMM_EXIT;
	else if (comm.compare("ADD") == 0)
		return COMM_ADD;
	else if (comm.compare("SEARCH") == 0)
		return COMM_SEARCH;
	else
		return COMM_IGN;
}

int main()
{
	PhoneBook *pb = new PhoneBook();
	COMM_TYPE commType;
	while (1)
	{
		commType = readCommand();
		if (commType == COMM_EXIT)
			break ;
		else if (commType == COMM_ADD)
			executeAdd(pb);
		else if(commType == COMM_SEARCH)
			executeSearch(pb);
	}
	delete pb;
}