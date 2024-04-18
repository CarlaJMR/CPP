/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:44:09 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/04/18 18:05:28 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

int main()
{
	Data original;

	original.i = 42;
	original.c = 'A';
	
	std::cout << "Address of original: " << &original << std::endl;
	//std::cout << "Original data: " << data->i << std::endl;
	uintptr_t raw = Serializer::serialize(&original);
	std::cout << "Serialized adress: " << raw << std::endl;
	
	Data *ptr = Serializer::deserialize(raw);
	std::cout << "Deserialized adress: " << ptr << std::endl;
}