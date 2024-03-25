/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:44:09 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/03/25 16:16:44 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() 
{
	for (int i = 0; i < 4; i++)
		_learning[i] = NULL;
	return ;
}

MateriaSource::~MateriaSource() 
{
	for (int i = 0; i < 4; i++)
		if (_learning[i] != NULL)
			delete _learning[i];
	return ;
}

MateriaSource::MateriaSource( const MateriaSource& other ) 
{ 
	for (int i = 0; i < 4; i++)
		_learning[i] = other._learning[i];
	return ;
}

MateriaSource& MateriaSource::operator=( const MateriaSource& other ) 
{
	for (int i = 0; i < 4; i++)
	{
		delete _learning[i];
        _learning[i] = other._learning[i];
	}
	return (*this);
}

void	MateriaSource::learnMateria( AMateria* materia ) 
{
	for (int i = 0; i < 4 && materia != NULL; i++)
	{
		if (_learning[i] == NULL) 
        {
			_learning[i] = materia;
			std::cout << "New materia learned" << std::endl;
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
