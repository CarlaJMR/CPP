/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:31:35 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/02/09 18:13:01 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
 

const int Fixed::_fracbits = 8;

Fixed::Fixed(void) : _value (0)
{
    std::cout << "Default constructor called" << std::endl;
    return;
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
    return;
}

Fixed::Fixed(const Fixed & f)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = f;
    return;
}

Fixed & Fixed::operator=(const Fixed & f)
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->_value = f.getRawBits();
	return (*this);
}

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_value);
}

void Fixed::setRawBits( int const raw )
{
    //std::cout << "setRawBits member function called" << std::endl;
    this->_value = raw;
}