/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:44:09 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/03/04 19:18:34 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main( void )
{

    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;//should not create a leak
    delete i;

    std::cout << std::endl << "Array ok animals" <<std::endl;
    
    Animal *arr[8];
    
    for (int i = 0; i < 4; i++)
        arr[i] = new Dog();
    for (int i = 4; i < 7; i++)
        arr[i] = new Cat();
    for (int i = 0; i < 7; i++)
    {
        arr[i]->makeSound();
        delete arr[i];
    }

    std::cout << std::endl << "Deep copy" <<std::endl;
    Dog d;
	{
		Dog tmp = d;
	}

	Cat c;
	{
		Cat tmp = c;
	}
    return 0;
}