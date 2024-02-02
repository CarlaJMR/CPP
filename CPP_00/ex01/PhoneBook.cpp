/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:31:20 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/02/01 16:43:22 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <cstdlib>

PhoneBook::PhoneBook(void)
{
  std::cout << "Wellcome to my awesome PhoneBook!!" << std::endl;
  std::cout << std::endl;
  this->_nb_cont = 0;
  this->_next_cont = 0;
  return;
}

PhoneBook::~PhoneBook(void)
{
  return;
}

void  PhoneBook::SearchContact(void) const
{
  std::string index;
  
  std::cout << std::setfill ('*') << std::setw (45) << "*" << std::setfill (' ') << std::endl;
  std::cout << "|     Index|First name| Last name|  Nickname|" << std::endl;
  for (int i = 0; i < _nb_cont; i++)
  {
    std::cout << "|         " << i + 1 << "|";
    this->_list[i].printcontactline();
  }
  std::cout << std::setfill ('*') << std::setw (45) << "*" << std::endl;
  std::cout << std::endl;
  std::cout << "Select an index to see full information: ";
  std::getline(std::cin, index);
  std::cout << std::endl;
  this->_list[std::atoi(index.c_str()) -1].printsinglecontact();
  return;
}

void  PhoneBook::AddContact()
{
  std::string first;
  std::string last;
  std::string nick;
  std::string phone;
  std::string secret;
  
  if (_next_cont == 8) 
    _next_cont = 0;
  first = _get_field_contact(first, "First name: ");
	last = _get_field_contact(last, "Last name: ");
	nick = _get_field_contact(nick, "Nickname: ");
	phone = _get_field_contact(phone, "Phone number: ");
	secret = _get_field_contact(secret, "Darkest secret: ");
  std::cout << std::endl;
	this->_list[_next_cont].newcontact(first, last, nick, phone, secret);
  _next_cont++;
  if (_nb_cont < 8) 
    _nb_cont++;
  return;
}

std::string		PhoneBook::_get_field_contact(std::string field, std::string prompt)
{
  std::cout << prompt;
	std::getline(std::cin, field);
	while (field.empty())
	{
		std::cout << prompt;
		std::getline(std::cin, field);
	}
	return (field);
}