/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:31:20 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/02/06 12:02:53 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <cstdlib>
#include <ctype.h>

std::string	get_field_contact(std::string field, std::string prompt);
bool all_digit(std::string s);

PhoneBook::PhoneBook(void)
{
  std::cout << "\nWellcome to my awesome PhoneBook!!" << std::endl;
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
  
  if (_nb_cont == 0)
  {
    std::cout << "Your contact list is empty." << std::endl << std::endl;
    return;
  }
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
  if (std::cin.eof())
        return;
  if (!all_digit(index) || index.empty())
    std::cout << "You should have entered an integer." << std::endl << std::endl;
  else if (stoi(index) < 1 || stoi(index) > _nb_cont)
    std::cout << "You should have entered an index between 1 and " << _nb_cont << std::endl << std::endl;
  else
    this->_list[stoi(index) -1].printsinglecontact();
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
  first = get_field_contact(first, "First name: ");
	last = get_field_contact(last, "Last name: ");
	nick = get_field_contact(nick, "Nickname: ");
	phone = get_field_contact(phone, "Phone number: ");
	secret = get_field_contact(secret, "Darkest secret: ");
  std::cout << std::endl;
	this->_list[_next_cont].newcontact(first, last, nick, phone, secret);
  _next_cont++;
  if (_nb_cont < 8) 
    _nb_cont++;
  return;
}

bool all_digit(std::string s)
{
  for (int i = 0; i < s.size(); i++)
  {
    if (!isdigit(s[i]))
      return (false);
  }
  return (true);
}

std::string		get_field_contact(std::string field, std::string prompt)
{
    while (field.empty())
    {
      if (std::cin.eof())
        break;
      std::cout << prompt;
      std::getline(std::cin, field);
    }
	return (field);
}