/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:44:09 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/03/04 19:19:00 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
    this->type = "Dog";
    std::cout << "Default Dog constructor called" << std::endl;
    return;
}

Dog::Dog(const Dog &other) : Animal()
{
    *this = other;
    std::cout << "Copy Dog constructor called" <<std::endl;
    return;
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" <<std::endl;
    return;
}

Dog & Dog::operator=(const Dog &other)
{
    if (this != &other)
        this->type = other.type;
    return(*this);    
}

void Dog::makeSound() const
{
    std::cout << "Woof, woof,... , woof..." <<std::endl;
}
