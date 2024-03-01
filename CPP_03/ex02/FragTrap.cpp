/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:44:09 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/03/01 11:08:24 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
    this->_hitpoints = 100;
    this->_energypoints = 100;
    this->_damage = 30;
    std::cout << "Default FragTrap constructor called" << std::endl;
    return;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    this->_hitpoints = 100;
    this->_energypoints = 100;
    this->_damage = 30;
    std::cout << "FragTrap constructor called for " << name << std::endl;
    return;
}

FragTrap::FragTrap( const FragTrap& st) : ClapTrap(st)
{
    *this = st;
    std::cout << "Copy FragTrap constructor called for " << this->_name <<std::endl;
    return;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap destructor called for " << this->_name <<std::endl;
    return;
}

FragTrap & FragTrap::operator=(const FragTrap& st)
{
    if (this != &st)
    {
        this->_name = st._name;
        this->_hitpoints = st._hitpoints;
        this->_energypoints = st._energypoints;
        this->_damage = st._damage;
    }
    //std::cout << "Copy assignment FragTrap operator called for " << this->_name <<std::endl;
    return(*this);    
}

void	FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << this->_name << " wants to high five you." << std::endl;
    return;
}