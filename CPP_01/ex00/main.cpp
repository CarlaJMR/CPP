/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:31:35 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/02/02 18:45:29 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp" 

void randomChump( std::string name );

Zombie* newZombie( std::string name );


int main( void )
{
    std::cout << "We'll create a zombie allocated in the heap:" << std::endl;
	Zombie	*h = newZombie("Heap_Zombie");
	std::cout << std::endl;

	std::cout << "We'll create a zombie allocated in the stack:" << std::endl;
	randomChump("Stack_Zombie");
	std::cout << std::endl;

	std::cout << "We can announce the Heap_Zombie but not the Stack_Zombie" << std::endl;
	h->announce();
	delete	h;
    return (0);
}


 

