/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:31:20 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/01/30 16:34:22 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
  return;
}

Contact::~Contact(void)
{
  return;
}

Contact    _newcontact(void)
{
  Contact newc;
  
  return (newc);
}

void  Contact::_printcontactinfo(void) const
{
  std::cout << "First name: " << this->_first << std::endl;
  std::cout << "Last name: " << this->_last << std::endl;
  std::cout << "Nickname: "<< this->_nick << std::endl;
  std::cout << "Phone number: "<< this->_phone << std::endl;
  std::cout << "Darkest secret: "<< this->_secret << std::endl;
}