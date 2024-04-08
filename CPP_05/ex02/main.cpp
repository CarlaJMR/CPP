/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:44:09 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/04/08 15:45:09 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	bureau_life(std::string name, int grade, std::string name2, int grade2, int grade3)
{
	Bureaucrat b(name, grade);
	Form		f(name2, grade2, grade3);

	std::cout << b << std::endl;
	std::cout << f << std::endl;
	b.signForm(f);
	std::cout << f << std::endl;
	return (0);
}

int	error_testing(std::string name, int grade, std::string name2, int grade2, int grade3)
{
	try
	{
		bureau_life(name, grade, name2, grade2, grade3);
	}
	catch(Form::GradeTooHighException &error)
	{
		std::cerr << error.what() << std::endl;
		return (1);
	}
	catch(Form::GradeTooLowException &error)
	{
		std::cerr << error.what() << std::endl;
		return (1);
	}
	catch(Bureaucrat::GradeTooHighException &error)
	{
		std::cerr << error.what() << std::endl;
		return (1);
	}
	catch(Bureaucrat::GradeTooLowException &error)
	{
		std::cerr << error.what() << std::endl;
		return (1);
	}
	return (0);
}

int	main(void)
{
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