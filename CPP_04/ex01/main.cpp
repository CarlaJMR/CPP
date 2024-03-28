/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:44:09 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/03/22 16:52:32 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "ShallowCat.hpp"

int main( void )
{
    std::cout << std::endl << "Subject test" <<std::endl;
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;//should not create a leak
    delete i;

    std::cout << std::endl << "Array of animals" <<std::endl;
    Animal *arr[6];
    for (int i = 0; i < 3; i++)
        arr[i] = new Dog();
    for (int i = 3; i < 6; i++)
        arr[i] = new Cat();
    std::cout << std::endl;
    for (int i = 0; i < 6; i++)
    {
        arr[i]->makeSound();
        delete arr[i];
    }

    std::cout << std::endl << "Deep copy test" <<std::endl;
    {
        Cat original;
        Cat a;
        original.getBrain()->setIdea(0, "brincadeira");
        a = original;
        a.getBrain()->setIdea(0, "vou passear");
        Cat deepcp(original);
        deepcp.getBrain()->setIdea(0, "tenho fome");
        std::cout << "Original idea: " << original.getBrain()->getIdea(0) << std::endl;
        std::cout << "Copy idea: " << deepcp.getBrain()->getIdea(0) << std::endl;
        std::cout << "Copy assignment idea: " << a.getBrain()->getIdea(0) << std::endl;
    }

    std::cout << std::endl << "Shallow copy test" <<std::endl;
    {
        ShallowCat original;
        original.getBrain()->setIdea(0, "brincadeira");
        ShallowCat shacp(original);
        shacp.getBrain()->setIdea(0, "tenho fome");
        std::cout << "Original idea: " << original.getBrain()->getIdea(0) << std::endl;
        std::cout << "Copy idea: " << shacp.getBrain()->getIdea(0) << std::endl;
    }
    return 0;
}