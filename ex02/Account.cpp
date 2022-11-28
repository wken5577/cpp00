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
	Account::_totalAmount += initial_deposit;
	this->_accountIndex = Account::_nbAccounts;
	Account::_nbAccounts++;
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << \
	";amount:" << this->_amount << ";created" << std::endl;

}

Account::~Account()
{
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << \
	";amount:" << this->_amount << ";closed" << std::endl;
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
	_displayTimestamp();

	std::cout << " accounts:8" << ";total:" << Account::getTotalAmount() \
	<< ";deposits:" << Account::getNbDeposits() << \
	";withdrawals:" << Account::getNbWithdrawals() <<std::endl;
}

void Account::displayStatus() const
{
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << \
		";amount:" << this->_amount << ";deposits:" << this->_nbDeposits << \
		";withdrawals:" << this->_nbWithdrawals << std::endl;
}

void Account::makeDeposit(int deposit)
{
	Account::_totalNbDeposits++;
	this->_nbDeposits = 1;
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << \
	";p_amount:" << this->_amount << ";deposit:" << deposit << \
	 ";amount:" << this->_amount + deposit << \
	 ";nb_deposits:" << this->_nbDeposits << std::endl;
	Account::_totalAmount -= this->_amount;
	this->_amount += deposit;
	Account::_totalAmount += this->_amount;
}

int		Account::checkAmount() const
{
	return this->_amount;
}	

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();

	std::cout << " index:" << this->_accountIndex << \
	 ";p_amount:" << this->_amount;
	if (this->checkAmount() - withdrawal < 0)
	{
		std::cout << ";withdrawal:refused" << std::endl;
		return false;
	}
	Account::_totalAmount -= this->_amount;
	this->_amount -= withdrawal;
	Account::_totalAmount += this->_amount;
	this->_nbWithdrawals = 1;
	Account::_totalNbWithdrawals++;
	std::cout << ";withdrawal:" << withdrawal << \
	";amount:" << this->_amount << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return true;
}