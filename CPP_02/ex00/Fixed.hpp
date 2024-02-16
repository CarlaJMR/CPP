/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:31:35 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/02/16 13:23:58 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <string>
#include <iostream>
 
class Fixed
{
    public:
        Fixed(void);
        ~Fixed(void);
        Fixed(const Fixed & f);
        Fixed & operator=(const Fixed & f);
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        
    private:
        int _value;
        static const int _fracbits;
};

#endif
