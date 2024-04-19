/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:44:09 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/04/19 16:16:26 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

int main()
{
	{
		Data original;

		original.i = 42;
		original.c = 'A';
		
		std::cout << "Address of original: " << &original << std::endl;
		std::cout << "Original values: " << original.i << "\t" << original.c << std::endl;
		
		uintptr_t raw = Serializer::serialize(&original);
		std::cout << "\nnUintptr after serializer: " << raw << std::endl;
		
		Data *ptr = Serializer::deserialize(raw);
		std::cout << "\nData * after deserializer: " << ptr << std::endl;
		std::cout << "Values after deserializer: " << original.i << "\t" << original.c << std::endl;
	}
	std::cout << "\n------------------------------------------\n" << std::endl;
	{
		Data *original = new Data;
		
		original->i = 42;
		original->c = 'A';
		
		std::cout << "Address of original: " << original << std::endl;
		std::cout << "Original values: " << original->i << "\t" << original->c << std::endl;
		
		uintptr_t raw = Serializer::serialize(original);
		std::cout << "\nnUintptr after serializer: " << raw << std::endl;
		
		Data *ptr = Serializer::deserialize(raw);
		std::cout << "\nData * after deserializer: " << ptr << std::endl;
		std::cout << "Values after deserializer: " << original->i << "\t" << original->c << std::endl;
		delete original;
	}
	
}