/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:31:35 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/02/09 12:48:33 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp" 
 
HumanB::HumanB(std::string name): _name (name)
{
    this->_wep = NULL;
    return;
}

HumanB::~HumanB()
{
    return;
}

void HumanB::setWeapon( Weapon &w )
{
    this->_wep = &w;
    return;
}

void HumanB::attack( void ) const
{
    if (this->_wep)
        std::cout << this->_name << " attacks with their " << this->_wep->getType() << std::endl;
    else
        std::cout << this->_name << " has no weapon to attack " << std::endl;
    return;
}
 