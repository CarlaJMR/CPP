/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:44:09 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/03/22 16:28:30 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void)
{
    this->type = "AMateria";
    std::cout << "Default AMateria constructor called" << std::endl;
    return;
}

AMateria::AMateria(const AMateria &other): Animal()
{
     _brain = new Brain;
    *this = other;
    std::cout << "Copy AMateria constructor called" <<std::endl;
    return;
}

AMateria::~AMateria()
{
    delete _brain;
    std::cout << "AMateria destructor called" <<std::endl;
    return;
}

AMateria & AMateria::operator=(const AMateria &other)
{
    if (this != &other)
    {
        this->type = other.type;
        *_brain = *(other._brain);
    }
    return(*this);    
}

void AMateria::makeSound() const
{
    std::cout << "Miaow, miaow,... , miaow..." <<std::endl;
}
