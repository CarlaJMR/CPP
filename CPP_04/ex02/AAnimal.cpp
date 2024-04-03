/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:44:09 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/04/03 18:06:59 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(void)
{
    std::cout << "Default Animal constructor called" << std::endl;
    return;
}

AAnimal::AAnimal(std::string stype): type(stype)
{
    std::cout << "Animal constructor called for " << type << std::endl;
    return;
}

AAnimal::AAnimal(const AAnimal &other)
{
    *this = other;
    std::cout << "Copy Animal constructor called" <<std::endl;
    return;
}

AAnimal::~AAnimal()
{
    std::cout << "Animal destructor called" <<std::endl;
    return;
}

AAnimal & AAnimal::operator=(const AAnimal &other)
{
    if (this != &other)
        this->type = other.type;
    return(*this);    
}

void AAnimal::makeSound() const
{
    if (this->type[0])
        std::cout << "This " << type << " does not have a specific sound!" <<std::endl;
    else
        std::cout << "This Animal does not have a specific sound!" <<std::endl;
}

std::string AAnimal::getType() const
{
    return(this->type);
}
