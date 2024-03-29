/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:31:35 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/02/16 13:58:32 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <string>
#include <iostream> 
#include <cmath>

class Fixed
{
    public:
        Fixed(void);
        ~Fixed(void);
        Fixed(const int i);
        Fixed(const float f);
        Fixed(const Fixed & f);
        Fixed & operator=(const Fixed & f);
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        float toFloat( void ) const;
        int toInt( void ) const;
        
    private:
        int _value;
        static const int _fracbits;
};

std::ostream & operator <<(std::ostream &o, Fixed const &f);

#endif
