/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:44:09 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/04/05 15:44:33 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

AMateria *floorMateria[50];

MateriaSource::MateriaSource() 
{
	for (int i = 0; i < 4; i++)
		_learning[i] = NULL;
	return ;
	std::cout << "MateriaSource constructor called" <<std::endl;
}

MateriaSource::~MateriaSource() 
{
	for (int i = 0; i < 4; i++)
	{
		if (_learning[i] != NULL)
		{
			delete _learning[i];
			_learning[i] = NULL;
		}
	}
	std::cout << "MateriaSource destroyed" <<std::endl;
	return ;
}

MateriaSource::MateriaSource( const MateriaSource& other ) 
{ 
	for (int i = 0; i < 4; i++)
		_learning[i] = other._learning[i];
	return ;
	//std::cout << "MateriaSource copy constructor called" <<std::endl;
}

MateriaSource& MateriaSource::operator=( const MateriaSource& other ) 
{
	for (int i = 0; i < 4; i++)
	{
		if(_learning[i] != NULL)
			{
				delete _learning[i];
				_learning[i] = NULL;
                if (other._learning[i] != NULL)
				        _learning[i] = other._learning[i]->clone();
			}
	}
	std::cout << "MateriaSource copied" <<std::endl;
	return (*this);
}

void	MateriaSource::learnMateria( AMateria* materia ) 
{
	for (int i = 0; i < 4 && materia != NULL; i++)
	{
		if (_learning[i] == NULL) 
        {
			_learning[i] = materia;
			std::cout << "New materia learned: " << _learning[i]->getType() << std::endl;
			return ;
		}
	}
	std::cout << "Memory full or non existent materia!" << std::endl;
	delete materia;
	return ;
}

AMateria* MateriaSource::createMateria( std::string const & type ) {
	for (int i = 0; i < 4; i++)
	{
		if (_learning[i] != NULL && _learning[i]->getType() == type)
		{
			std::cout << "Materia " << type << " created" << std::endl;
			return (_learning[i]->clone());
		}
	}
	std::cout << type << ": materia type not found" << std::endl;
	return 0;
}

void	dropMateria(AMateria *m)
{
	static unsigned int i;

	if (floorMateria[i % 50])
		delete floorMateria[i % 50];
	floorMateria[i % 50] = m;
	i++;
}

void	cleanFloor( void )
{
	int	i = 0;
	if (floorMateria[0])
	{
		while (i < 50 && floorMateria[i])
		delete floorMateria[i++];
	}
    std::cout << "The floor has been cleaned." << std::endl;
}