/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:44:09 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/04/26 17:07:58 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void	bureau_task(std::string name, int grade, std::string name2, int grade2, int grade3)
{
	Bureaucrat b(name, grade);
	Form		f(name2, grade2, grade3);

	std::cout << b << std::endl;
	std::cout << f << std::endl;
	b.signForm(f);
	std::cout << f << std::endl;
	b.signForm(f);
}

void	error_testing(std::string name, int grade, std::string name2, int grade2, int grade3)
{
	try
	{
		bureau_task(name, grade, name2, grade2, grade3);
	}
	catch(std::exception &error)
	{
		std::cerr << error.what() << std::endl;
	}
}

int	main(void)
{
	try
	{
		Bureaucrat b1("Cris", 56);
		Form	f1("FirstForm", 12, 100);
		f1.beSigned(b1);
	}
	catch(std::exception &error)
	{
		std::cerr << error.what() << std::endl;
	}
	
	std::cout << std::endl;
	
	error_testing("Bubu", 0, "form1", 1, 75);
	std::cout << std::endl;
	error_testing("Bubu", 170, "form1", 1, 75);
	std::cout << std::endl;
	error_testing("Bubu", 74, "form1", 0, 75);
	std::cout << std::endl;
	error_testing("Bubu", 74, "form1", 151, 75);
	std::cout << std::endl;
	error_testing("Bubu", 74, "form1", 75, 0);
	std::cout << std::endl;
	error_testing("Bubu", 74, "form1", 75, 151);
	std::cout << std::endl;
	error_testing("Bubu", 74, "form1", 75, 75);
	std::cout << std::endl;
	error_testing("Bubu", 75, "form1", 75, 75);
	std::cout << std::endl;
	error_testing("Bubu", 75, "form1", 74, 75);
	return (0);
}