/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:44:09 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/03/01 18:40:10 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"


DiamondTrap::DiamondTrap( void ) 
{
	std::cout << "Default DiamondTrap constructor called" << std::endl;
    return;
}

DiamondTrap::DiamondTrap(std::string name)
{
    _energypoints = 50;
    _name = name;
    ClapTrap::_name = name + "_clap_name";
   
    std::cout << "DiamondTrap constructor called for " << name << std::endl;
    return;
}

DiamondTrap::DiamondTrap(const DiamondTrap &ct) : ClapTrap(ct), ScavTrap(), FragTrap()
{
    *this = ct;
    std::cout << "Copy DiamondTrap constructor called for " << this->_name <<std::endl;
    return;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap destructor called for " << this->_name <<std::endl;
    return;
}

DiamondTrap & DiamondTrap::operator=(const DiamondTrap &ct)
{
    if (this != &ct)
    {
        this->_name = ct._name;
        this->_hitpoints = ct._hitpoints;
        this->_energypoints = ct._energypoints;
        this->_damage = ct._damage;
    }
    //std::cout << "Copy assignment DiamondTrap operator called for " << this->_name <<std::endl;
    return(*this);    
}

void    DiamondTrap::whoAmI( void )
{
    std::cout << "Who am I?" << " My DiamondTrap name is " << this->_name;
    std::cout << ". My ClapTrap name is " << this->ClapTrap::_name << std::endl;
}