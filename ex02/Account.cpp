#include <iostream>

#include "Account.hpp"

int Account::getNbAccounts( void )
{
	return Account::_nbAccounts;
}

int Account::getTotalAmount( void )
{
	return Account::_totalAmount;
}

int Account::getNbDeposits( void )
{
	return Account::_totalNbDeposits;
}

int Account::getNbWithdrawals( void )
{
	return Account::_totalNbWithdrawals;
}

void Account::displayAccountsInfos( void )
{
	Account::_displayTimestamp();
	std::cout	<< "accounts:" << getNbAccounts()
				<< ";total:" << getTotalAmount()
				<< ";deposits:" << getNbDeposits()
				<< ";withdrawals:" << getNbWithdrawals() << std::endl;
}

Account::Account( int initial_deposit ) : _amount(initial_deposit)
{
	Account::_displayTimestamp();
	this->_accountIndex = Account::_nbAccounts;
	std::cout	<< "index:" << this->_accountIndex
				<< ";amount:" << this->checkAmount()
				<< ";created" << std::endl;
	this->_totalAmount += initial_deposit;
	Account::_nbAccounts += 1;
}

Account::~Account( void )
{
	Account::_displayTimestamp();
	std::cout	<< "index:" << this->_accountIndex
				<< ";amount:" << this->checkAmount()
				<< ";closed" << std::endl;
	Account::_nbAccounts -= 1;
}

void Account::makeDeposit( int deposit )
{
	Account::_displayTimestamp();
	std::cout	<< "index:" << this->_accountIndex
				<< ";p_amount:" << this->checkAmount()
				<< ";deposit:";
	this->_amount += deposit;
	this->_nbDeposits += 1;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits += 1;
	std::cout	<< deposit
				<< ";amount:" << this->checkAmount()
				<< ";nb_deposits:" << this->_nbDeposits
				<< std::endl;
}

bool Account::makeWithdrawal( int withdrawal )
{
	Account::_displayTimestamp();
	std::cout	<< "index:" << this->_accountIndex
				<< ";p_amount:" << this->checkAmount()
				<< ";withdrawal:";
	if (this->checkAmount() < withdrawal)
	{
		std::cout << "refused" << std::endl;
		return false;
	}
	else
	{
		this->_amount -= withdrawal;
		this->_nbWithdrawals += 1;
		Account::_totalAmount -= withdrawal;
		Account::_totalNbWithdrawals += 1;
	}
	std::cout	<< withdrawal
				<< ";amount:" << this->checkAmount()
				<< ";nb_withdrawals:" << this->_nbWithdrawals
				<< std::endl;
	return true;
}

int  Account::checkAmount( void ) const
{
	return this->_amount;
}

void Account::displayStatus( void ) const
{
	Account::_displayTimestamp();
	std::cout	<< "index:" << this->_accountIndex
				<< ";amount:" << this->checkAmount()
				<< ";deposits:" << this->_nbDeposits
				<< ";withdrawals:"<< this->_nbWithdrawals
				<< std::endl;
}

void Account::_displayTimestamp( void )
{
	time_t	timestamp;
	char	formated[16];

	time(&timestamp);
	strftime(formated, sizeof(formated), "%Y%m%d_%H%M%S", localtime(&timestamp));
	std::cout << "[" << formated << "] ";
}

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;
