/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShallowCat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:44:09 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/03/04 19:05:24 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShallowCat.hpp"

ShallowCat::ShallowCat(void)
{
    this->type = "ShallowCat";
    for (int i = 0; i < 100; i++)
        (*_brain).getIdea(i) = "";
    std::cout << "Default ShallowCat constructor called" << std::endl;
    return;
}

ShallowCat::ShallowCat(const ShallowCat &other): Animal()
{
    _brain =other.getBrain();
    *this = other;
    std::cout << "Copy ShallowCat constructor called" <<std::endl;
    return;
}

ShallowCat::~ShallowCat()
{
    std::cout << "ShallowCat destructor called" <<std::endl;
    return;
}

ShallowCat & ShallowCat::operator=(const ShallowCat &other)
{
    if (this != &other)
    {
        this->type = other.type;
        _brain =other.getBrain();
    }
    std::cout << "ShallowCat assignment operator called" <<std::endl;
    return(*this);    
}

void ShallowCat::makeSound() const
{
    std::cout << "Miaow, miaow,... , miaow..." <<std::endl;
}

Brain* ShallowCat::getBrain(void) const
{
	return (_brain);
}
