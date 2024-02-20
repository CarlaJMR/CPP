/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:31:35 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/02/20 12:42:01 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : _x (0) , _y (0)
{
    //std::cout << "Point default constructor called" << std::endl;
    return;
}

Point::~Point(void)
{
    //std::cout << "Point destructor called" << std::endl;
    return;
}

Point::Point(Fixed const x, Fixed const y) : _x (x) , _y (y)
{
    //std::cout << "Point parametric constructor called" << std::endl;
    return;
}

Point::Point(const Point & p)
{
    //std::cout << "Point copy constructor called" << std::endl;
    *this = p;
    return;
}

Point & Point::operator=(const Point & p)
{
    //std::cout << "Point copy assignment operator called" << std::endl;
    if (this != &p)
    {
        (Fixed &)this->_x = p.getX();
        (Fixed &)this->_y = p.getY();
    }
	return (*this);
}

Fixed Point::getX( void ) const
{
    return (this->_x);
}

Fixed Point::getY( void ) const
{
    return (this->_y);
}

bool	bsp( Point const a, Point const b, Point const c, Point const Point);