/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:44:09 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/03/01 18:46:58 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main( void )
{
	std::cout << std::endl;
	
	DiamondTrap	D ("TestVersion");
	
	std::cout << std::endl;
	D.attack("Other");
	std::cout << std::endl;
	D.takeDamage(10);
	std::cout << std::endl;
	D.highFivesGuys();
	std::cout << std::endl;
	D.guardGate();
	std::cout << std::endl;
	D.beRepaired(20);
	std::cout << std::endl;
	D.whoAmI();
	std::cout << std::endl;
	return 0;
}