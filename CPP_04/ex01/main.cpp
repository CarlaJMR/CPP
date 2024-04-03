/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:44:09 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/04/03 18:00:53 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

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
        std::cout << "**** Cat: Ideas immediately after copy assignement ****" << std::endl;
        std::cout << "Original idea: " << original.getBrain()->getIdea(0) << std::endl;
        std::cout << "Copy idea: " << a.getBrain()->getIdea(0) << std::endl;
        a.getBrain()->setIdea(0, "vou passear");
        std::cout << "**** Cat: after copy changes idea ****" << std::endl;
        std::cout << "Original idea: " << original.getBrain()->getIdea(0) << std::endl;
        std::cout << "Copy idea: " << a.getBrain()->getIdea(0) << std::endl;
        Dog first;
        first.getBrain()->setIdea(0, "tenho fome");
        Dog deepcp(first);
        std::cout << "**** Dog: Ideas immediately after copy constructor ****" << std::endl;
        std::cout << "Original idea: " << first.getBrain()->getIdea(0) << std::endl;
        std::cout << "Copy idea: " << deepcp.getBrain()->getIdea(0) << std::endl;
        first.getBrain()->setIdea(0, "vou roer os chinelos");
        std::cout << "**** Dog: Ideas after original changes idea ****" << std::endl;
        std::cout << "Original idea: " << first.getBrain()->getIdea(0) << std::endl;
        std::cout << "Copy idea: " << deepcp.getBrain()->getIdea(0) << std::endl;
    }

    return 0;
}