#include "Account.hpp"
#include <iostream>
#include <chrono>
#include "ctime"

#define INDEX_N_AMOUNT "index:" << _accountIndex << ";amount:"<< _amount
#define INDEX "index:" << _accountIndex

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account()
{
	this->_accountIndex = _nbAccounts;
	_nbAccounts++;
	_amount = 0;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
}

Account::Account(int initial_deposit) //this calls the default constructer first
{
	this->_accountIndex = _nbAccounts;
	_nbAccounts++;
	_nbDeposits = 0;
	_nbWithdrawals = 0;									  //constructer, delegation :3
	this->_amount = initial_deposit;
	_totalAmount += this->_amount;
	_displayTimestamp();
	std::cout << INDEX_N_AMOUNT << ";created\n";
}

Account::~Account()
{
	_displayTimestamp();
	std::cout << INDEX_N_AMOUNT << ";closed\n";
}


void	Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount \
				<< ";deposits:" << _totalNbDeposits << ";withdrawals:" \
				 << _totalNbWithdrawals << std::endl;

}

int	Account::getNbAccounts()
{
	return(_nbAccounts);
}

int	Account::getTotalAmount()
{
	return(_totalAmount);
}

int	Account::getNbDeposits()
{
	return(_totalNbDeposits);
}

int	Account::getNbWithdrawals()
{
	return(_totalNbWithdrawals);
}

void	Account::makeDeposit( int deposit )
{
	const int	p_amount = _amount;
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	_displayTimestamp();
	std::cout << INDEX << ";p_amount:" << p_amount \
				<< ";deposit:" << deposit << ";amount:" << _amount \
				<< ";nb_deposits:" << _nbDeposits << std::endl;
}



bool	Account::makeWithdrawal(int withdrawal)
{
	const int p_amount = _amount;
	_displayTimestamp();
	std::cout << INDEX << ";p_amount:" << p_amount << ";withdrawal:";
	if (_amount < withdrawal)
	{
		std::cout << "refused\n";
		return (false);
	}
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	std::cout << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" \
				<< _nbWithdrawals << std::endl;
	return (true);
}

int		Account::checkAmount( void ) const
{
	// _displayTimestamp();
	// std::cout << INDEX_N_AMOUNT << std::endl;
	return (_amount);
}

void	Account::displayStatus() const
{
	_displayTimestamp();
	std::cout << INDEX_N_AMOUNT << ";deposits:" << _nbDeposits \
				<< ";withdrawals:" << _nbWithdrawals << std::endl;
}


void	Account::_displayTimestamp()
{
	// auto now = std::chrono::system_clock::now();
	std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
	std::time_t time = std::chrono::system_clock::to_time_t(now);
	char	timestr[80];
	std::strftime(timestr, sizeof(timestr), "%Y%m%d_%H%M%S",\
					std::localtime(&time));
	std::cout << "[" << timestr << "] ";
}
