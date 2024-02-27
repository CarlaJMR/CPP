/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:44:09 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/02/27 13:34:11 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main( void )
{
	ScavTrap	d ("Dalila");
	ScavTrap	e ("Elisa");

	d.attack("Elisa");
	e.takeDamage(20);
	d.guardGate();
	d.attack("Elisa");
	e.takeDamage(20);
	d.attack("Elisa");
	e.guardGate();
	e.takeDamage(20);
	d.attack("Elisa");
	e.takeDamage(20);
	d.attack("Elisa");
	e.takeDamage(20);
	d.attack("Elisa");
	e.takeDamage(20);
	d.guardGate();
	return 0;
}