/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:44:09 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/03/04 18:42:04 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
    std::cout << "Default WrongAnimal constructor called" << std::endl;
    return;
}

WrongAnimal::WrongAnimal(std::string stype): type(stype)
{
    std::cout << "WrongAnimal constructor called for " << type << std::endl;
    return;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
    *this = other;
    std::cout << "Copy WrongWrongAnimal constructor called" <<std::endl;
    return;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructor called" <<std::endl;
    return;
}

WrongAnimal & WrongAnimal::operator=(const WrongAnimal &other)
{
    if (this != &other)
        this->type = other.type;
    return(*this);    
}

void WrongAnimal::makeSound() const
{
    if (this->type[0])
        std::cout << "This " << type << " does not have a specific sound!" <<std::endl;
    else
        std::cout << "This WrongAnimal does not have a specific sound!" <<std::endl;
}

std::string WrongAnimal::getType() const
{
    return(this->type);
}
