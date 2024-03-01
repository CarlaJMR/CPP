/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:44:09 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/03/01 10:35:44 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void): _hitpoints (10), _energypoints (10), _damage (0)
{
    std::cout << "Default ClapTrap constructor called" << std::endl;
    return;
}

ClapTrap::ClapTrap(std::string name): _name (name), _hitpoints (10), _energypoints (10), _damage (0)
{
    std::cout << "ClapTrap constructor called for " << name << std::endl;
    return;
}

ClapTrap::ClapTrap(const ClapTrap &ct)
{
    *this = ct;
    std::cout << "Copy ClapTrap constructor called for " << this->_name <<std::endl;
    return;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap destructor called for " << this->_name <<std::endl;
    return;
}

ClapTrap & ClapTrap::operator=(const ClapTrap &ct)
{
    if (this != &ct)
    {
        this->_name = ct._name;
        this->_hitpoints = ct._hitpoints;
        this->_energypoints = ct._energypoints;
        this->_damage = ct._damage;
    }
    std::cout << "Copy assignment ClapTrap operator called for " << this->_name <<std::endl;
    return(*this);    
}

void ClapTrap::attack(const std::string& target)
{
    if (_hitpoints <= 0)
        std::cout << "ClapTrap " << this->_name << " didn\'t attack because  it\'s DEAD!" <<std::endl;
    else if (!_energypoints)
        std::cout << "ClapTrap " << this->_name << " doesn\'t have enough energy to attack!" <<std::endl;
    else
    {
        _energypoints--;
        std::cout << "ClapTrap " << this->_name << " attacks " << target << " causing " << _damage << " points of damage!" <<std::endl;
        std::cout << "Now " << _name << " has "<< _energypoints << " energy points left." << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (_hitpoints < 0)
        std::cout << "ClapTrap " << _name << " can\'t be damaged because  it\'s DEAD!" << std::endl;
    else
    {
        _hitpoints -= amount;
        if (_hitpoints > 0)
            std::cout << "ClapTrap " << _name << " took " << amount << " points of damage and now has " << _hitpoints << " hitpoints of health." << std::endl;
        else
            std::cout << "ClapTrap " << _name << " took " << amount << " points of damage and died!" << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (_hitpoints <= 0)
        std::cout << "ClapTrap " << this->_name << " can\'t be repaired because is DEAD!" <<std::endl;
    else if (!_energypoints)
        std::cout << "ClapTrap " << this->_name << " doesn\'t have enough energy to repair itself!" <<std::endl;
    else
    {
        _energypoints--;
        _hitpoints += amount;
        std::cout << "ClapTrap " << _name << " was repaired with " << amount << " points, and now has " << _hitpoints << " hitpoints of health." << std::endl;
        std::cout << "Now " << _name << " has "<< _energypoints << " energy points left." << std::endl;
    }
}
