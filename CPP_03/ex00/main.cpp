/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:44:09 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/03/01 10:47:24 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main( void )
{
	std::cout << std::endl;
    
    ClapTrap A("Aniceto");
	ClapTrap B("Blimundo");
    ClapTrap C("Cesaltino");
    
    std::cout << std::endl;
    
	A.attack("enemy");
    std::cout << std::endl;
    A.attack("Blimundo");
    std::cout << std::endl;
    B.takeDamage(8);
    std::cout << std::endl;
    A.beRepaired(5);
    std::cout << std::endl;
    B.beRepaired(20);
    std::cout << std::endl;
	B.beRepaired(25);
   
    std::cout << std::endl;
    
    for (int i = 1; i < 13; i++){
        C.attack("anyone");}

    std::cout << std::endl;
    C.beRepaired(5);
    C.takeDamage(10);
    C.attack("anyone");
    std::cout << std::endl;
	return 0;
}