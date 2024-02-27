/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:44:09 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/02/27 14:21:26 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main( void )
{
	FragTrap	f ("First");
	FragTrap	s ("Second");
	ScavTrap	st ("Serena");
	

	s.attack("First");
	s.takeDamage(30);
	f.highFivesGuys();
	st.attack("First");
	f.takeDamage(20);
	
	return 0;
}