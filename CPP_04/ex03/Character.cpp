/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:44:09 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/04/05 16:18:41 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void)
{
    _name = "";
    for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
    std::cout << "Default Character constructor called" << std::endl;
    return;
}

Character::Character(std::string const & n): _name(n)
{
    for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
    std::cout << "Parametric Character constructor called" << std::endl;
    return;
}

Character::Character(const Character &other)
{
    for (int i = 0; i < 4; i++) 
	_inventory[i] = NULL;
    *this = other;
    std::cout << "Copy Character constructor called" <<std::endl;
    return;
}

Character::~Character()
{
    for (int i = 0; i < 4; i++)
    {
	if (_inventory[i] != NULL)
        {
             delete (_inventory[i]);
             _inventory[i] = NULL;   
        }	
    }
    std::cout << getName() << ": character destroyed." << std::endl;
    return;
}

Character & Character::operator=(const Character &other)
{
        {
	if (this != &other){
		for (int i = 0; i < 4; i++)
                {
                        if (this->_inventory[i])
                        {
			        delete this->_inventory[i];
			        this->_inventory[i] = NULL;
		        }
                }
		_name = other.getName();
		for (int i = 0; i < 4; i++)
		{
			if (other._inventory[i])
				this->_inventory[i] = other._inventory[i]->clone();
			else 
				this->_inventory[i] = NULL;
		}
	}
	return *this;
}
}

std::string const & Character::getName() const
{
    return(this->_name);
}

void Character::equip(AMateria* m)
{
        for (int i = 0; i < 4 && m != NULL; i++)
        {
                if (_inventory[i] == NULL) 
                {
                        _inventory[i] = m;
                        std::cout << "Materia equiped: " << m->getType() << std::endl;
                        return ;
                }
        }
        std::cout << "Inventory full or non existent materia!" << std::endl;
        delete m;
}

void Character::unequip(int idx)
{
        if (idx < 0 || idx >= 4)
                std::cout << "Invalid slot number!" << std::endl;
        else
        {
                if (_inventory[idx] == NULL)
                        std::cout << "Empty slot!" << std::endl;
                else
                {
                        std::cout << "Materia unequiped: " << _inventory[idx]->getType()<< std::endl;
                        dropMateria(_inventory[idx]);
                        _inventory[idx] = NULL;
                }
        }
}

void Character::use(int idx, ICharacter& target)
{
        if (idx < 0 || idx >= 4)
                std::cout << "Invalid slot number!" << std::endl;
        else if (_inventory[idx] != NULL)
                _inventory[idx]->use(target);
        else
                std::cout << "Empty slot!" << std::endl;
}
