/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:31:20 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/02/01 16:16:52 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
  return;
}

Contact::~Contact(void)
{
  return;
}

void    Contact::newcontact(std::string first, std::string last, std::string nick, std::string phone, std::string secret)
{
  this->_first = first;
  this->_last = last;
  this->_nick = nick;
  this->_phone = phone;
  this->_secret = secret;
  return;
}

void    Contact::printcontactline(void) const
{
  if (this->_first.size() <= 10)
    std::cout << std::setw(10) << this->_first << "|";
  else
    std::cout << this->_first.substr(0, 9) << ".|";
  if (this->_last.size() <= 10)
    std::cout << std::setw(10) << this->_last << "|";
  else
    std::cout << this->_last.substr(0, 9) << ".|";
  if (this->_nick.size() <= 10)
    std::cout << std::setw(10) << this->_nick << "|";
  else
    std::cout << this->_nick.substr(0, 9) << ".|";
  std::cout << std::endl;
}

void  Contact::printsinglecontact(void) const
{
  std::cout << "First name: " << this->_first << std::endl;
  std::cout << "Last name: " << this->_last << std::endl;
  std::cout << "Nickname: "<< this->_nick << std::endl;
  std::cout << "Phone number: "<< this->_phone << std::endl;
  std::cout << "Darkest secret: "<< this->_secret << std::endl;
}