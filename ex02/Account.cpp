#include <iostream>
#include <iomanip>
#include <ctime>

#include <Account.hpp>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts( void )
{
	return _nbAccounts;
}

int Account::getTotalAmount( void )
{
	return _totalAmount;
}

int Account::getNbDeposits( void )
{
	return _totalNbDeposits;
}

int Account::getNbWithdrawals( void )
{
	return _totalNbWithdrawals;
}

void Account::displayAccountsInfos( void )
{
	_displayTimestamp();

    std::cout
        << "accounts:" << getNbAccounts()
        << ";total:" << getTotalAmount()
        << ";deposits:" << getNbDeposits()
        << ";withdrawals:" << getNbWithdrawals()
        << std::endl;
}

Account::Account( int initial_deposit )
{
    _accountIndex = _nbAccounts;
    _amount = initial_deposit;
    _nbWithdrawals = 0;
    _nbDeposits = 0;
    _nbAccounts++;
    _totalAmount += initial_deposit;

    _displayTimestamp();

    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

Account::~Account( void )
{
    _displayTimestamp();

    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

void Account::makeDeposit( int deposit )
{
	_nbDeposits++;

    _displayTimestamp();

	std::cout
        << "index:" << _accountIndex
        << ";p_amount:" << _amount 
		<< ";deposit:" << deposit
        << ";amount:" << _amount + deposit
		<< ";nb_deposits:" << _nbDeposits
        << std::endl;

	_amount += deposit;

	_totalAmount += deposit;
	_totalNbDeposits++;
}

bool Account::makeWithdrawal( int withdrawal )
{
	Account::_displayTimestamp();

	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount;
        
	if (_amount - withdrawal < 0)
    {
	    std::cout << ";withdrawal:refused" << std::endl;

	    return false;
    }

    _amount -= withdrawal;
    _nbWithdrawals++;
    _totalNbWithdrawals++;
    _totalAmount -= withdrawal;

    std::cout
        << ";withdrawal:" << withdrawal
        << ";amount:" << _amount
        << ";nb_withdrawals:" << _nbWithdrawals
        << std::endl;

    return true;
}

int Account::checkAmount( void ) const
{
	return _amount;
}

void Account::displayStatus( void ) const
{
	_displayTimestamp();

    std::cout
        << "index:" << _accountIndex
        << ";amount:" << _amount
        << ";deposits:" << _nbDeposits
        << ";withdrawals:" << _nbWithdrawals
        << std::endl;
}

void Account::_displayTimestamp( void )
{
    std::time_t timer = std::time(NULL);
    std::tm *time = std::localtime(&timer);

    std::cout << "["
        << std::setw(4) << std::setfill('0') << 1900 + time->tm_year
        << std::setw(2) << std::setfill('0') << 1 + time->tm_mon
        << std::setw(2) << std::setfill('0') << time->tm_mday
        << "_"
        << std::setw(2) << std::setfill('0') << time->tm_hour
        << std::setw(2) << std::setfill('0') << time->tm_min
        << std::setw(2) << std::setfill('0') << time->tm_sec
        << "] ";
}