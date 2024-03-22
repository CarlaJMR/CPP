/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:44:09 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/03/04 19:19:00 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
    std::cout << "Brain constructor called" << std::endl;
    return;
}

Brain::Brain(const Brain &other)
{
    *this = other;
    std::cout << "Copy Brain constructor called" <<std::endl;
    return;
}

Brain::~Brain()
{
    std::cout << "Brain destructor called" <<std::endl;
    return;
}

Brain & Brain::operator=(const Brain &other)
{
    if (this != &other)
    {
        for (int i = 0; i < 100; i++)
        this->ideas[i] = other.ideas[i];
    }
    return(*this);    
}

