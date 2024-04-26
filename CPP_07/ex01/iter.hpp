/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:43:46 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/04/26 18:22:52 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T, typename F> 
void iter(T *arr, size_t len , F func)
{
	for (size_t i = 0; i < len; i++)
		func(arr[i]);
}

#endif
