/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:44:09 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/03/01 11:16:45 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main( void )
{
	std::cout << std::endl;
	FragTrap	f ("First");
	FragTrap	s ("Second");
	FragTrap	copy = f;
	
	std::cout << std::endl;
	s.attack("First");
	f.takeDamage(30);
	std::cout << std::endl;
	f.highFivesGuys();
	std::cout << std::endl;
	copy.beRepaired(30);
	std::cout << std::endl;
	
	return 0;
}