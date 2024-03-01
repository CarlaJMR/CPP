/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:44:09 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/03/01 10:54:06 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
    this->_hitpoints = 100;
    this->_energypoints = 50;
    this->_damage = 20;
    std::cout << "Default ScavTrap constructor called" << std::endl;
    return;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    this->_hitpoints = 100;
    this->_energypoints = 50;
    this->_damage = 20;
    std::cout << "ScavTrap constructor called for " << name << std::endl;
    return;
}

ScavTrap::ScavTrap( const ScavTrap& st) : ClapTrap(st)
{
    *this = st;
    std::cout << "Copy ScavTrap constructor called for " << this->_name <<std::endl;
    return;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor called for " << this->_name <<std::endl;
    return;
}

ScavTrap & ScavTrap::operator=(const ScavTrap& st)
{
    if (this != &st)
    {
        this->_name = st._name;
        this->_hitpoints = st._hitpoints;
        this->_energypoints = st._energypoints;
        this->_damage = st._damage;
    }
    //std::cout << "Copy assignment ScavTrap operator called for " << this->_name <<std::endl;
    return(*this);    
}

void ScavTrap::attack(const std::string& target)
{
    if (_hitpoints <= 0)
        std::cout << "ScavTrap " << this->_name << " didn\'t attack because  it\'s DEAD!" <<std::endl;
    else if (!_energypoints)
        std::cout << "ScavTrap " << this->_name << " doesn\'t have enough energy to attack!" <<std::endl;
    else
    {
        _energypoints--;
        std::cout << "ScavTrap " << this->_name << " attacks " << target << " causing " << _damage << " points of damage!" <<std::endl;
        std::cout << "Now " << _name << " has "<< _energypoints << " energy points left." << std::endl;
    }
}

void	ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode." << std::endl;
    return;
}