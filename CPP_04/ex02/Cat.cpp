/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:44:09 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/04/03 18:09:16 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
    this->type = "Cat";
    _brain = new Brain;
    std::cout << "Default Cat constructor called" << std::endl;
    return;
}

Cat::Cat(const Cat &other): AAnimal()
{
    _brain = new Brain;
    *this = other;
    std::cout << "Copy Cat constructor called" <<std::endl;
    return;
}

Cat::~Cat()
{
    delete _brain;
    std::cout << "Cat destructor called" <<std::endl;
    return;
}

Cat & Cat::operator=(const Cat &other)
{
    if (this != &other)
    {
        this->type = other.type;
        *_brain = *(other._brain);
    }
    std::cout << "Cat assignment operator called" <<std::endl;
    return(*this);    
}

void Cat::makeSound() const
{
    std::cout << "Miaow, miaow,... , miaow..." <<std::endl;
}

Brain* Cat::getBrain(void) const
{
	return (_brain);
}