/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:44:09 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/04/26 16:49:49 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
	{
		try{
			Bureaucrat Min("bb", 151);
			std::cout << Min << std::endl;
		}
		catch (std::exception &e){
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	{
		try{
			Bureaucrat Max("bb", 0);
			std::cout << Max << std::endl;
		}
		catch (std::exception &e){
			std::cerr << e.what() << std::endl;
		}
	}

	std::cout << std::endl;
	{
		try{
			Bureaucrat Ok("Inbounds", 104);
			std::cout << Ok << std::endl;
			Ok.incrementGrade();
			std::cout << Ok << std::endl;
		}
		catch (std::exception &e){
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	{
		try{
			Bureaucrat b("Promo", 1);
			std::cout << b << std::endl;
			b.incrementGrade();
			std::cout << b << std::endl;
		}
		catch (std::exception &e){
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	{
		try{
			Bureaucrat b("Depromo", 149);
			std::cout << b << std::endl;
			b.decrementGrade();
			std::cout << b << std::endl;
			b.decrementGrade();
			std::cout << b << std::endl;
		}
		catch (std::exception &e){
			std::cerr << e.what() << std::endl;
		}
	}
	return 0;
}