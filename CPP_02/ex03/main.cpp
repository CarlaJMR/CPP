/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:31:35 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/02/20 14:56:25 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool	bsp( Point const a, Point const b, Point const c, Point const Point);

int main( void ) 
{
  const Point a(1, 1);
		const Point b(5, 5);
		const Point c(1, 10);
		const Point point(4.9f, 5); 
		std::cout << (bsp(a, b, c, point) == 1 ? "True" : "False") << std::endl;
    return 0;
}