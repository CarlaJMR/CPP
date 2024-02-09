/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:31:35 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/02/09 11:58:16 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp" 
 
Weapon::Weapon(std::string type): _type (type)
{
    return;
}

Weapon::~Weapon()
{
    return;
}

std::string Weapon::getType( void ) const
{
    return (this->_type);
}

void Weapon::setType( std::string t )
{
    this->_type = t;
    return;
}
 
