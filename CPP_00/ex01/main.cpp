/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:31:20 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/01/19 17:25:26 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PhoneBook.hpp"
#include <iostream>

int main()
{
  PhoneBook my_book;
  std::string cmd;
  
  while (1)
  {
    std::cout << "Enter a command\n[ADD]/[SEARCH]/[EXIT]: ";
    std::cin >> cmd;
    std::cout << std::endl;
    if (cmd == "EXIT" || std::cin.eof())
      break;
    else if (cmd == "ADD")
      _AddContact();
    else if (cmd == "SEARCH")
      _SearchContact();
  }
  return (0);
}
