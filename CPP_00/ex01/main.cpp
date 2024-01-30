/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:31:20 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/01/30 16:54:51 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PhoneBook.hpp"

int main()
{
  PhoneBook my_book;
  std::string cmd;
  
  while (1)
  {
    std::cout << "Enter a command\n[ADD]/[SEARCH]/[EXIT]: ";
    std::getline(std::cin, cmd);
    std::cout << std::endl;
    if (cmd == "EXIT" || std::cin.eof())
      break;
    else if (cmd == "ADD")
      my_book._AddContact();
    else if (cmd == "SEARCH")
      my_book._SearchContact();
  }
  return (0);
}
