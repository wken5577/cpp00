#include "Account.hpp"
#include <iostream>
#include <time.h>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts()
{
	return Account::_nbAccounts;
}

int Account::getTotalAmount()
{
	return Account::_totalAmount;
}

int Account::getNbDeposits()
{
	return Account::_totalNbDeposits;
}

int Account::getNbWithdrawals()
{
	return Account::_totalNbWithdrawals;
}

Account::Account()
{}

Account::Account(int initial_deposit)
	:_amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
	Account::_nbAccounts++;
	Account::_totalAmount += initial_deposit;
	this->_accountIndex = Account::_nbAccounts;
	std::cout << "./19920104_091532.log: line " << Account::_nbAccounts << ": ";
	_displayTimestamp();
	std::cout << ": command not found" << std::endl;

	std::cout << "./19920104_091532.log: line " << Account::_nbAccounts << ": ";
	std::cout << "amount:" << initial_deposit << ": command not found" << std::endl;

	std::cout << "./19920104_091532.log: line " << Account::_nbAccounts << ": ";
	std::cout << "created: command not found" << std::endl;
}

Account::~Account()
{
	Account::_nbAccounts++;
	std::cout << "./19920104_091532.log: line " << Account::_nbAccounts << ": ";
	_displayTimestamp();
	std::cout << ": command not found" << std::endl;

	std::cout << "./19920104_091532.log: line " << Account::_nbAccounts << ": ";
	std::cout << "amount:" << this->_amount << ": command not found" << std::endl;

	std::cout << "./19920104_091532.log: line " << Account::_nbAccounts << ": ";
	std::cout << "closed: command not found" << std::endl;
}


void Account::_displayTimestamp(void)
{
	time_t curTime = time(NULL);
	struct tm *pLocal = localtime(&curTime);

	std::cout << "[" << pLocal->tm_year + 1900 << pLocal->tm_mon + 1 << pLocal->tm_mday << "_"
		<< pLocal->tm_hour << pLocal->tm_min << pLocal->tm_sec << "]";
}

void Account::displayAccountsInfos()
{
	Account::_nbAccounts++;
	std::cout << "./19920104_091532.log: line " << Account::_nbAccounts << ": ";
	_displayTimestamp();
	std::cout << ": command not found" << std::endl;

	std::cout << "./19920104_091532.log: line " << Account::_nbAccounts << ": ";
	std::cout << "total:" << Account::getTotalAmount() << ": command not found" << std::endl;

	std::cout << "./19920104_091532.log: line " << Account::_nbAccounts << ": ";
	std::cout << "deposits:" << Account::getNbDeposits() << ": command not found" << std::endl;

	std::cout << "./19920104_091532.log: line " << Account::_nbAccounts << ": ";
	std::cout << "withdrawals:" << Account::getNbWithdrawals() << ": command not found" << std::endl;
}

void Account::displayStatus() const
{
	Account::_nbAccounts++;
	std::cout << "./19920104_091532.log: line " << Account::_nbAccounts << ": ";
	_displayTimestamp();
	std::cout << ": command not found" << std::endl;

	std::cout << "./19920104_091532.log: line " << Account::_nbAccounts << ": ";
	std::cout << "amount:" << this->_amount << ": command not found" << std::endl;

	std::cout << "./19920104_091532.log: line " << Account::_nbAccounts << ": ";
	std::cout << "deposits:" << this->_nbDeposits << ": command not found" << std::endl;

	std::cout << "./19920104_091532.log: line " << Account::_nbAccounts << ": ";
	std::cout << "withdrawals:" << this->_nbWithdrawals << ": command not found" << std::endl;
}

void Account::makeDeposit(int deposit)
{
	Account::_nbAccounts++;
	Account::_totalNbDeposits++;
	this->_nbDeposits = 1;
	std::cout << "./19920104_091532.log: line " << Account::_nbAccounts << ": ";
	_displayTimestamp();
	std::cout << ": command not found" << std::endl;

	std::cout << "./19920104_091532.log: line " << Account::_nbAccounts << ": ";
	std::cout << "p_amount:" << this->_amount << ": command not found" << std::endl;

	std::cout << "./19920104_091532.log: line " << Account::_nbAccounts << ": ";
	std::cout << "deposit:" << deposit << ": command not found" << std::endl;

	std::cout << "./19920104_091532.log: line " << Account::_nbAccounts << ": ";
	std::cout << "amount:" << this->_amount + deposit << ": command not found" << std::endl;

	std::cout << "./19920104_091532.log: line " << Account::_nbAccounts << ": ";
	std::cout << "nb_deposits:" << this->_nbDeposits << ": command not found" << std::endl;

	Account::_totalAmount -= this->_amount;
	this->_amount += deposit;
	Account::_totalAmount += this->_amount;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	Account::_nbAccounts++;

	std::cout << "./19920104_091532.log: line " << Account::_nbAccounts << ": ";
	_displayTimestamp();
	std::cout << ": command not found" << std::endl;

	std::cout << "./19920104_091532.log: line " << Account::_nbAccounts << ": ";
	std::cout << "p_amount:" << this->_amount << ": command not found" << std::endl;

	std::cout << "./19920104_091532.log: line " << Account::_nbAccounts << ": ";
	if (this->_amount - withdrawal < 0)
	{
		std::cout << "withdrawal:refused: command not found" << std::endl;
		return false;
	}
	Account::_totalAmount -= this->_amount;
	this->_amount -= withdrawal;
	Account::_totalAmount += this->_amount;
	this->_nbWithdrawals = 1;
	Account::_totalNbWithdrawals++;
	std::cout << "withdrawal:" << withdrawal << ": command not found" << std::endl;

	std::cout << "./19920104_091532.log: line " << Account::_nbAccounts << ": ";
	std::cout << "amount:" << this->_amount << ": command not found" << std::endl;

	std::cout << "./19920104_091532.log: line " << Account::_nbAccounts << ": ";
	std::cout << "nb_withdrawals:" << this->_nbWithdrawals << ": command not found" << std::endl;
	return true;
}