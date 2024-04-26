/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:43:46 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/04/26 17:43:28 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template <typename T> 
void swap(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}

template <typename T> 
T& min(T& a, T& b)
{
    return (a < b ? a : b);
}

template <typename T> 
T& max(T& a, T& b)
{
    return (a > b ? a : b);
}

#endif
