/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 01:53:00 by edelage           #+#    #+#             */
/*   Updated: 2023/05/18 01:53:00 by edelage          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "Account.hpp"
#include <iostream>
#include <iomanip>

int	Account::_nbAccounts;
int	Account::_totalAmount;
int	Account::_totalNbDeposits;
int	Account::_totalNbWithdrawals;

int Account::getNbAccounts() {
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount() {
	return (Account::_totalAmount);
}

int Account::getNbDeposits() {
	return (Account::_totalNbDeposits);
}

int Account::getNbWithdrawals() {
	return (Account::_totalNbWithdrawals);
}

void Account::displayAccountsInfos() {
	_displayTimestamp();
	std::cout << " accounts:" << Account::_nbAccounts << ';'
	<< "total:" << Account::_totalAmount << ';'
	<< "deposits:" << Account::_totalNbDeposits << ';'
	<< "withdrawals:" << Account::_totalNbWithdrawals
	<< std::endl;
}

Account::Account(int initial_deposit) {
	this->_accountIndex = _nbAccounts;
	this->_nbAccounts++;
	this->_amount = initial_deposit;
	this->_totalAmount += initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ';'
			  << "amount:" << this->_amount << ';'
			  << "created" << std::endl;
}

Account::~Account() {
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ';'
			<< "amount:" << this->_amount << ';'
			<< "closed" << std::endl;
}

void	Account::makeDeposit(int deposit) {
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ';'
			<< "p_amount:" << this->_amount << ';'
			<< "deposit:" << deposit << ';';
	this->_nbDeposits++;
	this->_totalNbDeposits++;
	this->_amount += deposit;
	std::cout << "amount:" << this->_amount << ';'
			<< "nb_deposits:" << this->_nbDeposits
			<< std::endl;
	this->_totalAmount += deposit;
}

bool	Account::makeWithdrawal(int withdrawal) {
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ';'
			<< "p_amount:" << this->_amount << ';'
			<< "withdrawal:";
	if (this->_amount - withdrawal < 0)
	{
		std::cout << "refused" << std::endl;
		return (false);
	}
	this->_nbWithdrawals++;
	this->_totalNbWithdrawals++;
	this->_amount -= withdrawal;
	this->_totalAmount -= withdrawal;
	std::cout << withdrawal << ';'
			<< "amount:" << this->_amount << ';'
			<< "nb_withdrawals:" << this->_nbWithdrawals
			<< std::endl;
	return (true);
}

int	Account::checkAmount() const {
	return (this->_amount);
}

void Account::displayStatus() const {
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ';'
			<< "amount:" << this->_amount << ';'
			<< "deposits:" << this->_nbDeposits << ';'
			<< "withdrawals:" << this->_nbWithdrawals
			<< std::endl;
}

Account::Account() {
	this->_accountIndex = this->_nbAccounts;
	this->_nbAccounts++;
	this->_amount = 0;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ';'
			<< "amount:" << this->_amount << ';'
			<< "created" << std::endl;
}

void	Account::_displayTimestamp() {
	time_t	current_time;
	std::tm	*timeinfo;

	time(&current_time);
	timeinfo = localtime(&current_time);
	std::cout << '['
			<< std::setfill('0') << std::setw(4) << timeinfo->tm_year + 1900
			<< std::setfill('0') << std::setw(2) << timeinfo->tm_mon + 1
			<< std::setfill('0') << std::setw(2) << timeinfo->tm_mday
			<< '_'
			<< std::setfill('0') << std::setw(2) << timeinfo->tm_hour
			<< std::setfill('0') << std::setw(2) << timeinfo->tm_min
			<< std::setfill('0') << std::setw(2) << timeinfo->tm_sec
			<< ']';
}
