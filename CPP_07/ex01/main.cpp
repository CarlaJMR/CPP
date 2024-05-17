/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:44:09 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/05/17 13:26:46 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"

template <typename U>
void printfuntion(U x)
{
	std::cout << x << std::endl;
}

int main(void)
{
	int intArray[] = {1, 2, 3, 4};
	iter(intArray, 4, printfuntion<int>);
	std::cout << std::endl;
	
	char charArray[] = {'a', 'b', 'c', 'd', 'e', 'f'};
	iter(charArray, 5, printfuntion<char>);
	std::cout << std::endl;
	
	double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	iter(doubleArray, 5, printfuntion<double>);
	std::cout << std::endl;
	
	return 0;
}