/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:31:35 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/02/09 16:02:15 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
 
Harl::Harl()
{
    return;
}

Harl::~Harl()
{
    return;
}

void Harl::debug( void ) const
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!";
    std::cout << std::endl;
    return;
}

void Harl::info( void ) const
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn\'t put enough bacon in my burger! If you did, I wouldn\'t be asking for more!";
    std::cout << std::endl;
    return;
}

void Harl::warning( void ) const
{
    std::cout << "I think I deserve to have some extra bacon for free. I\'ve been coming for years whereas you started working here since last month.";
    std::cout << std::endl;
    return;
}

void Harl::error( void ) const
{
    std::cout << "This is unacceptable! I want to speak to the manager now.";
    std::cout << std::endl;
    return;
}

void Harl::complain( std::string level ) const
{
    void    (Harl::*f)(void) const;
    
     if (level == "DEBUG" || level == "INFO" || level == "WARNING" || level == "ERROR")
     {
        switch (level[0])
        {
        case 'D':
            std::cout << "\n[ DEBUG ]" << std::endl;
            f = &Harl::debug;
            (this->*f)();
        case 'I':
            std::cout << "\n[ INFO ]" << std::endl;
            f = &Harl::info;
            (this->*f)();
        case 'W':
            std::cout << "\n[ WARNING ]" << std::endl;
            f = &Harl::warning;
            (this->*f)();
        case 'E':
            std::cout << "\n[ ERROR ]" << std::endl;
            f = &Harl::error;
            (this->*f)();
        }
    }
    else
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    return;
}

