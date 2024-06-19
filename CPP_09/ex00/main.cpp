/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:44:09 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/06/19 14:50:26 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2) 
	{
		std::cerr << "Error: wrong number of arguments." << std::endl;
		return 1;
	} 
	try
	{
		BitcoinExchange b;
		b.inputDataBase();
		b.makeExchange(argv[1]);
	}
	catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
	return 0;
}