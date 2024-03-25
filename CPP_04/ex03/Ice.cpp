/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:44:09 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/03/25 16:13:04 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(): AMateria("ice") {}

Ice::~Ice(){}

Ice::Ice (const Ice& other): AMateria("ice") 
{
	*this = other;
}

Ice& Ice::operator=( const Ice& other ) 
{
	(void) other;
	return (*this);
}

AMateria* Ice::clone() const 
{
	return (new Ice);
}

void	Ice::use( ICharacter& target) 
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
