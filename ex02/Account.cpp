/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 11:38:15 by jvarila           #+#    #+#             */
/*   Updated: 2025/05/26 12:45:30 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <iostream>
#include "Account.hpp"

// ----------------------------------------------------- static member variables

// Static member variables must be declared and defined outside of the class

int	Account:: _nbAccounts = 0;
int	Account:: _totalAmount = 0;
int	Account:: _totalNbDeposits = 0;
int	Account:: _totalNbWithdrawals = 0;
//
// ----------------------------------------------------- static member functions

// Static member functions are similar to static variables in that they are not
// specific to any instance of that class, but belong to the class itself. Thus
// you can't use the this keyword inside them, as that would be a pointer to a
// particular instance.
//
// You can't write static here though as that would be a different type of
// static, namely a static function local only to this file.

int Account:: getNbAccounts( void ) {
	return Account::_nbAccounts;
}

int Account:: getTotalAmount( void ) {
	return Account::_totalAmount;
}

int Account:: getNbDeposits( void ) {
	return Account::_totalNbDeposits;
}

int Account:: getNbWithdrawals( void ) {
	return Account::_totalNbWithdrawals;
}

void	Account:: displayAccountsInfos( void ) {

	time_t		timestamp = time(NULL);
	struct tm	datetime = *localtime(&timestamp);

	char buffer[100];
	std::strftime(buffer, 100, "[%Y%m%d_%H%M%S] ", &datetime);

    std::cout
		<< buffer
		<< "accounts:" << Account::getNbAccounts()
		<< ";total:" << Account::getTotalAmount()
		<< ";deposits:" << Account::getNbDeposits()
		<< ";withdrawals:" << Account::getNbWithdrawals()
		<< std::endl;
}

// ----------------------------------------------------------------- constructor

Account:: Account( int initial_deposit ) {

	this->_accountIndex = Account::_nbAccounts;
	this->_amount = initial_deposit;

	++Account::_nbAccounts;
	Account::_totalAmount += initial_deposit;

	time_t		timestamp = time(NULL);
	struct tm	datetime = *localtime(&timestamp);

	char buffer[100];
	std::strftime(buffer, 100, "[%Y%m%d_%H%M%S] ", &datetime);

    std::cout
		<< buffer
		<< "index:" << this->_accountIndex
		<< ";amount:" << this->checkAmount()
		<< ";created" << std::endl;
}

// ------------------------------------------------------------------ destructor

Account:: ~Account( void ) {

	time_t		timestamp = time(NULL);
	struct tm	datetime = *localtime(&timestamp);

	char buffer[100];
	strftime(buffer, 100, "[%Y%m%d_%H%M%S] ", &datetime);

    std::cout
		<< buffer
		<< "index:" << this->_accountIndex
		<< ";amount:" << this->checkAmount()
		<< ";closed" << std::endl;
}

// ------------------------------------------------------------ member functions

void Account:: makeDeposit( int deposit ) {

	time_t		timestamp = time(NULL);
	struct tm	datetime = *localtime(&timestamp);

	char buffer[100];
	strftime(buffer, 100, "[%Y%m%d_%H%M%S] ", &datetime);

    std::cout
		<< buffer
		<< "index:" << this->_accountIndex
		<< ";p_amount:" << this->checkAmount()
		<< ";deposit:" << deposit;

	this->_amount += deposit;
	++(this->_nbDeposits);

	Account::_totalAmount += deposit;
	++Account::_totalNbDeposits;
    std::cout
		<< ";amount:" << this->checkAmount()
		<< ";nb_deposits:" << this->_nbDeposits
		<< std::endl;
}

bool Account:: makeWithdrawal( int withdrawal ) {

	time_t		timestamp = time(NULL);
	struct tm	datetime = *localtime(&timestamp);

	char buffer[100];
	strftime(buffer, 100, "[%Y%m%d_%H%M%S] ", &datetime);

    std::cout
		<< buffer
		<< "index:" << this->_accountIndex
		<< ";p_amount:" << this->checkAmount()
		<< ";withdrawal:";
	if (this->_amount < withdrawal) {
		std::cout << "refused" << std::endl;
		return false;
	}
	std::cout << withdrawal;

	this->_amount -= withdrawal;
	++(this->_nbWithdrawals);
	Account::_totalAmount -= withdrawal;
	++Account::_totalNbWithdrawals;

    std::cout
		<< ";amount:" << this->checkAmount()
		<< ";nb_withdrawals:" << this->_nbWithdrawals
		<< std::endl;

	return true;
}

// Non static member function returns the amount of that account instance's money.
// A bit weird that the amount gets its own function but the deposits and withdrawals dont.
int Account:: checkAmount( void ) const {
	return this->_amount;
}

void Account:: displayStatus( void ) const {

	time_t		timestamp = time(NULL);
	struct tm	datetime = *localtime(&timestamp);

	char buffer[100];
	strftime(buffer, 100, "[%Y%m%d_%H%M%S] ", &datetime);

    std::cout
		<< buffer
		<< "index:" << this->_accountIndex
		<< ";amount:" << this->checkAmount()
		<< ";deposits:" << this->_nbDeposits
		<< ";withdrawals:" << this->_nbWithdrawals
		<< std::endl;
}
