/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:31:20 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/02/06 12:12:19 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;


Account::Account(int initial_deposit):_amount (initial_deposit)
{
  this->_accountIndex = _nbAccounts;
  _nbAccounts++;
  _totalAmount += initial_deposit;
  this->_nbDeposits = 0;
  this->_nbWithdrawals = 0;
  _displayTimestamp();
  std::cout << "index:" << this->_accountIndex << ";";
  std::cout << "amount:" << this->_amount << ";created" << std::endl;
  return;
}


Account::~Account(void)
{
  _nbAccounts--;
  _totalAmount -= this->_amount;
  _displayTimestamp();
  std::cout << "index:" << this->_accountIndex << ";";
  std::cout << "amount:" << this->_amount << ";closed" << std::endl;
  return;
}


int	Account::getNbAccounts( void )
{
  return Account::_nbAccounts;
}


int	Account::getTotalAmount( void )
{
  return Account::_totalAmount;
}


int	Account::getNbDeposits( void )
{
  return Account::_totalNbDeposits;
}


int	Account::getNbWithdrawals( void )
{
  return Account::_totalNbWithdrawals;
}


int	Account::checkAmount( void ) const
{
	return (this->_amount);
}


void	Account::displayAccountsInfos( void )
{
  _displayTimestamp();
  std::cout << "accounts:" << getNbAccounts() << ";";
  std::cout << "total:" << getTotalAmount() << ";";
  std::cout << "deposits:" << getNbDeposits() << ";";
  std::cout << "withdrawals:" << getNbWithdrawals() << std::endl;
}

void	Account::displayStatus( void ) const
{
  _displayTimestamp();
  std::cout << "index:" << this->_accountIndex << ";amount:" << checkAmount();
  std::cout << ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}


void	Account::makeDeposit( int deposit )
{
  this->_nbDeposits++;
   _totalNbDeposits++;
   _totalAmount += deposit;
  _displayTimestamp();
  std::cout << "index:" << this->_accountIndex << ";p_amount:" << checkAmount();
  this->_amount += deposit;
  std::cout << ";deposit:" << deposit << ";amount:" << checkAmount();
  std::cout << ";nb_deposits:"<< this->_nbDeposits << std::endl;
}


bool	Account::makeWithdrawal( int withdrawal )
{
  _displayTimestamp();
  std::cout << "index:" << this->_accountIndex << ";p_amount:" << checkAmount();
  if (withdrawal <= checkAmount())
  {
   this->_amount -= withdrawal;
   _totalAmount -= withdrawal;
   this->_nbWithdrawals++;
   _totalNbWithdrawals++;
   std::cout << ";withdrawal:" << withdrawal << ";amount:" << checkAmount();
   std::cout << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
   return (true);
  }
  std::cout << ";withdrawal:refused" << std::endl;
  return (false);
}


void Account::_displayTimestamp() {
    std::time_t now = time(0);
    tm *gmtm = gmtime(&now);
    std::cout << "[" << gmtm->tm_year + 1900 \
    << std::setfill('0') <<  std::setw(2) << gmtm->tm_mon \
    << std::setfill('0') <<  std::setw(2) << gmtm->tm_mday << "_" \
    << std::setfill('0') <<  std::setw(2) << gmtm->tm_hour \
    << std::setfill('0') <<  std::setw(2) << gmtm->tm_min
    << std::setfill('0') <<  std::setw(2) << gmtm->tm_sec << "] ";
    // std::cout << "[19920104_091532] ";
}

