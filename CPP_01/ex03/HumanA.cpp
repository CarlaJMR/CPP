/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:31:35 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/02/16 13:05:55 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp" 
 
HumanA::HumanA(std::string name, Weapon &w): _name (name), _wep (w)
{
    return;
}

HumanA::~HumanA()
{
    return;
}

void HumanA::attack( void ) const
{
    std::cout << this->_name << " attacks with their " << this->_wep.getType() << std::endl;
    return;
}
 
