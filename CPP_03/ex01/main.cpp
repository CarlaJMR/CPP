/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:44:09 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/03/01 11:05:53 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main( void )
{
	std::cout << std::endl;
	
	ScavTrap	d ("Dalila");
	ScavTrap	e ("Elisa");
	ClapTrap *ptr = &d;

	std::cout << std::endl;
	ptr->attack("XPTO");
	std::cout << std::endl;
	d.attack("Elisa");
	e.takeDamage(20);
	std::cout << std::endl;
	d.guardGate();
	std::cout << std::endl;
	d.attack("Elisa");
	e.takeDamage(20);
	std::cout << std::endl;
	return 0;
}