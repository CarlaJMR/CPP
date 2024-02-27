/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:44:09 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/02/27 15:05:41 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::Diamond(void): ScavTrap(), FragTrap()
{
    std::cout << "Default DiamondTrap constructor called" << std::endl;
    return;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name"), FragTrap(), ScavTrap(), _name(name)
{
    FragTrap::_hitpoints = 100;
    ScavTrap::_energypoints = 50;
    FragTrap::_damage = 30;
    std::cout << "DiamondTrap constructor called for " << name << std::endl;
    return;
}

DiamondTrap::DiamondTrap(const DiamondTrap &ct)
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
    std::cout << "Copy assignment DiamondTrap operator called for " << this->_name <<std::endl;
    return(*this);    
}

void DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
    return;
}

void    DiamondTrap::whoAmI( void )
{
    std::cout << "Who am I?" << std::endl;
    std::cout << "My name is " << this->_name << std::endl;
    std::cout << "My ClapTrap name is " << this->ClapTrap::_name << std::endl;
}