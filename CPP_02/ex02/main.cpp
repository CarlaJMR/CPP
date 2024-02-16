/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:31:35 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/02/16 18:43:28 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main( void ) 
{
  Fixed a;
  Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
  
  std::cout << a << std::endl;
  std::cout << ++a << std::endl;
  std::cout << a << std::endl;
  std::cout << a++ << std::endl;
  std::cout << a << std::endl;
  std::cout << b << std::endl;
  std::cout << Fixed::max( a, b ) << std::endl;

  //std::cout << (a > b) << std::endl;
  //std::cout << (a < b) << std::endl;
  //std::cout << (a >= b) << std::endl;
  //std::cout << (a <= b) << std::endl;
  //std::cout << (a == b) << std::endl;
  //std::cout << (a != b) << std::endl;
  
  return 0;
}