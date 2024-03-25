/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:44:09 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/03/25 16:13:30 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(): AMateria("cure") {}

Cure::~Cure(){}

Cure::Cure (const Cure& other): AMateria("cure") 
{
	*this = other;
}

Cure& Cure::operator=( const Cure& other ) 
{
	(void) other;
	return (*this);
}

AMateria* Cure::clone() const 
{
	return (new Cure);
}

void	Cure::use( ICharacter& target) 
{
	std::cout << "* heals " << target.getName() << "\'s wounds *" << std::endl;
}
