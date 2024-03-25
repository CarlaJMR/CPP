/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:44:09 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/03/25 11:33:22 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void)
{
    std::cout << "Default AMateria constructor called" << std::endl;
    return;
}

AMateria::AMateria(std::string const & t)
{
    type = t;
    std::cout << "Parametric AMateria constructor called" << std::endl;
    return;
}

AMateria::AMateria(const AMateria &other)
{
    *this = other;
    std::cout << "Copy AMateria constructor called" <<std::endl;
    return;
}

AMateria::~AMateria()
{
    std::cout << "AMateria destructor called" <<std::endl;
    return;
}

AMateria & AMateria::operator=(const AMateria &other)
{
    if (this != &other)
        this->type = other.type;
    return(*this);    
}

std::string const & AMateria::getType() const
{
    return(this->type);
}

void AMateria::use(ICharacter& target)
{
    (void)target;
}