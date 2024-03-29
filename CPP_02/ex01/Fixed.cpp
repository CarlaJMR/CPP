/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:31:35 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/02/16 17:24:16 by cjoao-me         ###   ########.fr       */
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

Fixed::Fixed(const int i) 
{
    std::cout << "Int constructor called" << std::endl;
    this->_value = (i <<_fracbits);
    return;
}

Fixed::Fixed(const float f) 
{
    std::cout << "Float constructor called" << std::endl;
    this->_value = roundf(f * ( 1 << _fracbits));
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
    if (this != &f)
        this->_value = f.getRawBits();
	return (*this);
}

int Fixed::getRawBits( void ) const
{
    //std::cout << "getRawBits member function called" << std::endl;
    return (this->_value);
}

void Fixed::setRawBits( int const raw )
{
    this->_value = raw;
}

float Fixed::toFloat( void ) const
{
    return (float)this->_value / (1 << _fracbits);
}

int Fixed::toInt( void ) const
{
    return roundf(this->_value >> _fracbits);
}

std::ostream & operator <<(std::ostream &o, Fixed const &f)
{
    o << f.toFloat();
    return o;
}