/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:31:35 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/02/20 12:40:49 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
    public:
        Point(void);
        ~Point(void);
        Point(Fixed const x, Fixed const y);
        Point(const Point & p);
        Point & operator=(const Point & p);
        
        Fixed getX( void ) const;
        Fixed getY( void ) const;
        
    private:
        Fixed const _x;
        Fixed const _y;
};


#endif
