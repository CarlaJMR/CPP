/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:55:25 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/05/16 17:21:25 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>


int main()
{
    std::cout << "\nTesting with a vector:" << std::endl;
    std::vector<int> myvector (3,100);
    std::vector<int>::iterator itv;
    
    myvector.push_back(-6);
    itv = myvector.begin();
    myvector.insert (itv, 4, 200);
    itv = myvector.begin();
    
    try{
        itv = easyfind(myvector, -6);
        std::cout << "Found the number " << *itv << std::endl;
    }
    catch (std::exception & e){
        std::cerr << e.what() << std::endl;
    }
    try{
        itv = easyfind(myvector, 250);
        std::cout << "Found the number " << *itv << std::endl;
    }
    catch (std::exception & e){
        std::cerr << e.what() << std::endl;
    }
    
    std::cout << "\nTesting with a list:" << std::endl;
    int myints[] = {75,23,65,42,13};
    std::list<int> mylist (myints,myints+5);

    try{
        std::list<int>::iterator it = easyfind(mylist, 42);
        std::cout << "Found the number " << *it << std::endl;
    }
    catch (std::exception & e){
        std::cerr << e.what() << std::endl;
    }

    try{
        std::list<int>::iterator it = easyfind(mylist, 4);
        std::cout << "Found the number " << *it << std::endl;
    }
    catch (std::exception & e){
        std::cerr << e.what() << std::endl;
    }
    
    return 0;
}
