/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:44:09 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/03/25 11:16:36 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
    this->type = "Dog";
    _brain = new Brain;
    std::cout << "Default Dog constructor called" << std::endl;
    return;
}

Dog::Dog(const Dog &other) : Animal()
{
    _brain = new Brain;
    *this = other;
    std::cout << "Copy Dog constructor called" <<std::endl;
    return;
}

Dog::~Dog()
{
    delete _brain;
    std::cout << "Dog destructor called" <<std::endl;
    return;
}

Dog & Dog::operator=(const Dog &other)
{
    if (this != &other)
    {
        this->type = other.type;
        *_brain = *(other._brain);
    }
    std::cout << "Dog assigment operator called" <<std::endl;
    return(*this);    
}

void Dog::makeSound() const
{
    std::cout << "Woof, woof,... , woof..." <<std::endl;
}
