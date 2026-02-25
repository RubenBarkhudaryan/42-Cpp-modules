#include <ctime>
#include <iostream>
#include <iomanip>
#include "./Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

/*-----Account ctor/dtor-----*/

Account::Account(void)
{}

Account::Account(int initial_deposit)
{
	_displayTimestamp();

	this->_accountIndex = Account::_nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	
	++(Account::_nbAccounts);
	Account::_totalAmount += initial_deposit;

	std::cout << "index:" << this->_accountIndex
			<< ";amount:" << this->_amount
			<< ";created" << std::endl;
}

Account::~Account(void)
{
	--(Account::_nbAccounts);
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
			<< ";amount:" << this->_amount
			<< ";closed" << std::endl;
}

/*-----Account statics-----*/

int	Account::getNbAccounts(void)
{
	return	(Account::_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return	(Account::_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return	(Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return	(Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:"<< Account::_nbAccounts
			<< ";total:" << Account::_totalAmount
			<< ";deposits:" << Account::_totalNbDeposits
			<< ";withdrawals:" << Account::_totalNbWithdrawals
			<< std::endl;
}

void	Account::_displayTimestamp(void)
{
	std::time_t	now = std::time(0);
	std::tm		*timeinfo = std::localtime(&now);

	std::cout << "[" << (timeinfo->tm_year + 1900)
			  << std::setfill('0') << std::setw(2) << (timeinfo->tm_mon + 1)
			  << std::setfill('0') << std::setw(2) << timeinfo->tm_mday
			  << "_"
			  << std::setfill('0') << std::setw(2) << timeinfo->tm_hour
			  << std::setfill('0') << std::setw(2) << timeinfo->tm_min
			  << std::setfill('0') << std::setw(2) << timeinfo->tm_sec
			  << "] ";
}

/*-----Account methods-----*/

void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
			<< ";p_amount:" << this->_amount
			<< ";deposit:" << deposit;

	this->_amount += deposit;
	++(this->_nbDeposits);

	Account::_totalAmount += deposit;
	++(Account::_totalNbDeposits);

	std::cout << ";amount:" << this->_amount
			<< ";nb_deposits:" << this->_nbDeposits
			<< std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
			<< ";p_amount:" << this->_amount
			<< ";withdrawal:";

	if (withdrawal > this->_amount)
	{
		std::cout << "refused" << std::endl;
		return (false);
	}

	this->_amount -= withdrawal;
	this->_nbWithdrawals++;
	Account::_totalAmount -= withdrawal;
	Account::_totalNbWithdrawals++;

	std::cout << withdrawal
			<< ";amount:" << this->_amount
			<< ";nb_withdrawals:" << this->_nbWithdrawals
			<< std::endl;

	return (true);
}

int	Account::checkAmount(void) const
{
	return (this->_amount);
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
			<< ";amount:" << this->_amount
			<< ";deposits:" << this->_nbDeposits 
			<< ";withdrawals:" << this->_nbWithdrawals
			<< std::endl;
}
