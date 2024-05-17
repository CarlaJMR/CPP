/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:39:04 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/05/17 14:25:51 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

#define MAX_VAL 750

int main(int, char**)
{
    
    std::cout << "Empty array:" << std::endl;
    Array<char> a;
    std::cout << a.size() << std::endl;
    try
    {
        std::cout << a[0] << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    std::cout << "\nArray of strings:" << std::endl;
    Array<std::string> s(2);
    std::cout << s.size() << std::endl;
    s[0] = "Hello ";
    s[1] = "world!";
    std::cout << s[0] << s[1] << std::endl;
    std::cout << "Copy constructor:" << std::endl;
    Array<std::string> copy(s);
    std::cout << s.size() << std::endl;
    std::cout << copy[0] << copy[1] << std::endl;
    copy[1] = "guys!";
    std::cout << "Original and copy after change:" << std::endl;
    std::cout << s[0] << s[1] << std::endl;
    std::cout << copy[0] << copy[1] << std::endl;
    std::cout << "Assigment operator:" << std::endl;
    copy = s;
    std::cout << "Original and copy before change:" << std::endl;
    std::cout << s[0] << s[1] << std::endl;
    std::cout << copy[0] << copy[1] << std::endl;
    s[0] = "Hey ";
    s[1] = "you!";
    std::cout << "Original and copy after change the original:" << std::endl;
    std::cout << s[0] << s[1] << std::endl;
    std::cout << copy[0] << copy[1] << std::endl;
    
    
    std::cout << "\nMain provided in subjet:" << std::endl;
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }
    
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;
    return 0;
}