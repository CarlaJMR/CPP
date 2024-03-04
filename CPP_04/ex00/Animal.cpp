/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:44:09 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/03/04 18:42:04 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void)
{
    std::cout << "Default Animal constructor called" << std::endl;
    return;
}

Animal::Animal(std::string stype): type(stype)
{
    std::cout << "Animal constructor called for " << type << std::endl;
    return;
}

Animal::Animal(const Animal &other)
{
    *this = other;
    std::cout << "Copy Animal constructor called" <<std::endl;
    return;
}

Animal::~Animal()
{
    std::cout << "Animal destructor called" <<std::endl;
    return;
}

Animal & Animal::operator=(const Animal &other)
{
    if (this != &other)
        this->type = other.type;
    return(*this);    
}

void Animal::makeSound() const
{
    std::cout << "This Animal does not have a specific sound!" <<std::endl;
}

std::string Animal::getType() const
{
    return(this->type);
}
