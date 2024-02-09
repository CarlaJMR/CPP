/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:31:35 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/02/06 15:07:00 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp" 
 
Zombie::Zombie()
{
    std::cout << "A zombie was born. He still doesn't have a name." << std::endl;
    return;
}

Zombie::~Zombie()
{
    std::cout << "Zombie " << this->_name << " died." << std::endl;
    return;
}

void Zombie::announce( void )
{
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
    return;
}
 
void Zombie::setName(std::string name)
{
    this->_name = name;
    std::cout << "A zombie got its name: " << this->_name << std::endl;
}
