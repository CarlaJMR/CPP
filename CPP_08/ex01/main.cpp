/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:55:25 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/05/31 12:37:41 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
    {
        Span sp = Span(15);
        
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
        std::cout << std::endl;
        sp.addNumber(-5);
        std::cout << sp.longestSpan() << std::endl;
        std::cout << sp.shortestSpan() << std::endl;
        sp.addNumber(5);
        std::cout << sp.longestSpan() << std::endl;
        std::cout << sp.shortestSpan() << std::endl;
    }
    std::cout << std::endl;
    {
        Span sp = Span(3);
        try
        {
            sp.addNumber(6);
            sp.addNumber(3);
            sp.addNumber(17);
            sp.addNumber(9);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
        
    }
    std::cout << std::endl;
    {
        Span sp = Span(2);
        try
        {
            sp.addNumber(-123);
            sp.print();
            std::cout << sp.shortestSpan() << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
        
    }
    std::cout << std::endl;
    {
        Span sp = Span(2);
        try
        {
            std::cout << sp.shortestSpan() << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
        
    }
    std::cout << std::endl;
    {
        Span sp = Span(10);
        try
        {
            sp.addNumber(-1);
            sp.addNumber(-2);
            sp.addNumber(17);
            sp.addNumber(13, 7);
            sp.print();
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
        
    }
    std::cout << std::endl;
    {
        Span sp = Span(10);
        try
        {
            sp.addNumber(-1);
            sp.addNumber(-2);
            sp.addNumber(17);
            sp.addNumber(13, 8);
            sp.print();
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
        
    }
    std::cout << std::endl;
    {
        Span sp = Span(12000);
        try
        {
            sp.addNumber(-1, 3000);
            sp.addNumber(2, 2000);
            sp.addNumber(0, 2000);
            sp.addNumber(13, 2000);
            sp.addNumber(42, 1000);
            sp.addNumber(21, 1000);
            std::cout << sp.longestSpan() << std::endl;
            std::cout << sp.shortestSpan() << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    return 0;
}
