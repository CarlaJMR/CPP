/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:44:09 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/03/04 19:05:24 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
    this->type = "Cat";
    std::cout << "Default Cat constructor called" << std::endl;
    return;
}

Cat::Cat(const Cat &other): Animal()
{
    *this = other;
    std::cout << "Copy Cat constructor called" <<std::endl;
    return;
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" <<std::endl;
    return;
}

Cat & Cat::operator=(const Cat &other)
{
    if (this != &other)
        this->type = other.type;
    return(*this);    
}

void Cat::makeSound() const
{
    std::cout << "Miaow, miaow,... , miaow..." <<std::endl;
}
