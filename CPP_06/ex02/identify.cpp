/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 12:20:05 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/04/30 15:21:26 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Base *generate(void)
{
    int i;
    srand(time(0));
    i = rand() % 3;
    switch (i)
        {
        case 0:
            return(new A);
        case 1:
            return(new B);
        case 2:
            return(new C);
        default:
            return(NULL);
        }
}

void identify(Base *p)
{
    if (dynamic_cast<A*>(p))
		std::cout << "A";
    else if (dynamic_cast<B*>(p))
		std::cout << "B";
    else if (dynamic_cast<C*>(p))
		std::cout << "C";
    else
        std::cout << "unkown type";
    std::cout << std::endl;
}

void identify(Base &p)
{
    try {
        A &a = dynamic_cast<A &>(p);
        std::cout << "A" << std::endl;
        (void) a;
    } catch (std::exception &e) {
        try {
            B &b = dynamic_cast<B &>(p);
            std::cout << "B" << std::endl;
            (void) b;
        } catch (std::exception &e) {
            try {
                C &c = dynamic_cast<C &>(p);
                std::cout << "C" << std::endl;
                (void) c;
            } catch (std::exception &e) {
                std::cout << "Unknown" << std::endl;
            }
        }
    }
}

int main()
{
    Base *ptr = generate();;
	
    std::cout << "Ptr test: ";
    identify(ptr);
    std::cout << "Ref test: ";
    identify(*ptr);
    delete ptr;
    std::cout << std::endl;

    return 0;
}
