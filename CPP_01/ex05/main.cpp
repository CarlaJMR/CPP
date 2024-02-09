/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:31:35 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/02/09 15:25:15 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
    Harl annoying;

    std::string level;
  
  while (!std::cin.eof())
  {
    std::cout << "\nEnter a complain level\nOptions [DEBUG; INFO; WARNING; ERROR]: ";
    std::getline(std::cin, level);
    std::cout << std::endl;
    annoying.complain(level);
  }
  
return 0;
}

