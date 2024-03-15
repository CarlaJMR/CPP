/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:44:09 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/03/04 19:05:24 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
    this->type = "WrongCat";
    std::cout << "Default WrongCat constructor called" << std::endl;
    return;
}

WrongCat::WrongCat(const WrongCat &other): WrongAnimal()
{
    *this = other;
    std::cout << "Copy WrongCat constructor called" <<std::endl;
    return;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor called" <<std::endl;
    return;
}

WrongCat & WrongCat::operator=(const WrongCat &other)
{
    if (this != &other)
        this->type = other.type;
    return(*this);    
}

void WrongCat::makeSound() const
{
    std::cout << "Miaow, miaow,... , miaow..." <<std::endl;
}
