/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:31:35 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/02/20 11:35:15 by cjoao-me         ###   ########.fr       */
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
        
        Fixed operator+(Fixed const &fix) const;
        Fixed operator-(Fixed const &fix) const;
        Fixed operator*(Fixed const &fix) const;
        Fixed operator/(Fixed const &fix) const;
        
        bool operator>(const Fixed &other) const;
        bool operator<(const Fixed &other) const;
        bool operator>=(const Fixed &other) const;
        bool operator<=(const Fixed &other) const;
        bool operator==(const Fixed &other) const;
        bool operator!=(const Fixed &other) const;

        static Fixed &min(Fixed &a, Fixed &b);
        static const Fixed &min(const Fixed &a, const Fixed &b);
        static Fixed &max(Fixed &a, Fixed &b);
        static const Fixed &max(const Fixed &a, const Fixed &b);

        Fixed   operator++( );
        Fixed 	operator++( int );
        Fixed   operator--( );
        Fixed 	operator--( int );
        
    private:
        int _value;
        static const int _fracbits;
};

std::ostream & operator <<(std::ostream &o, Fixed const &f);

#endif
