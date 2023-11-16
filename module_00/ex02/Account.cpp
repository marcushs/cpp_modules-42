/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 07:16:06 by hleung            #+#    #+#             */
/*   Updated: 2023/11/16 07:16:07 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include "Account.hpp"

int	Account::getNbAccounts(void)
{
	return Account::_nbAccounts;
}

int	Account::getTotalAmount(void)
{
	return Account::_totalAmount;
}

int	Account::getNbDeposits(void)
{
	return Account::_totalNbDeposits;
}

int	Account::getNbWithdrawals(void)
{
	return Account::_totalNbWithdrawals;
}

void	Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account:: _nbAccounts << ";";
	std::cout << "total:" << Account:: _totalAmount << ";";
	std::cout << "deposits:" << Account:: _totalNbDeposits << ";";
	std::cout << "withdrawals:" << Account:: _totalNbWithdrawals;
	std::cout << std::endl;
	return ;
}

Account::Account(int initial_deposit) : _amount(initial_deposit)
{
	this->_displayTimestamp();
	this->_accountIndex = Account::_nbAccounts;
	std::cout << "index:" << Account::_nbAccounts << ";";
	std::cout << "amount:" << this->_amount << ";" << "created";
	std::cout << std::endl;
	Account::_totalAmount += this->_amount;
	Account::_nbAccounts++;
	return ;
}

Account::~Account(void)
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";" << "closed";
	std::cout << std::endl;
	return ;
}

void	Account::makeDeposit(int deposit)
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	std::cout << "deposit:" << deposit << ";";
	this->_amount += deposit;
	this->_nbDeposits++;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "nb_deposits:" << this->_nbDeposits;
	std::cout << std::endl;
	return ;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	if (withdrawal > this->_amount)
	{
		std::cout << "withdrawal:refused" << std::endl;
		return (false);
	}
	std::cout << "withdrawal:" << withdrawal << ";";
	this->_amount -= withdrawal;
	this->_nbWithdrawals++;
	Account::_totalAmount -= withdrawal;
	Account::_totalNbWithdrawals++;
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "nb_withdrawals:" << this->_nbWithdrawals;
	std::cout << std::endl;
	return (true);
}

void	Account::displayStatus(void) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "deposits:" << this->_nbDeposits << ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals;
	std::cout << std::endl;
	return ;
}

static void	formatTimestamp(int val)
{
	if (val < 10)
		std::cout << "0" << val;
	else
		std::cout << val;
}

void	Account::_displayTimestamp(void)
{
	std::time_t	rawtime;
	std::tm		*today;

	std::time(&rawtime);
	today = std::localtime(&rawtime);
	std::cout << "[";
	std::cout << today->tm_year + 1900;
	formatTimestamp(today->tm_mon + 1);
	formatTimestamp(today->tm_mday);
	std::cout << "_";
	formatTimestamp(today->tm_hour);
	formatTimestamp(today->tm_min);
	formatTimestamp(today->tm_sec);
	std::cout << "] ";
}

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;
