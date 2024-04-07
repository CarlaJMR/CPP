/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carla <carla@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:44:09 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/04/07 17:38:17 by carla            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	bureau_life(std::string name, int grade, std::string name2, int grade2, int grade3)
{
	Bureaucrat	desk_jockey(name, grade);
	Form		paperwork(name2, grade2, grade3);

	std::cout << desk_jockey << std::endl;
	std::cout << paperwork << std::endl;
	desk_jockey.signForm(paperwork);
	std::cout << paperwork << std::endl;
	//desk_jockey.incrementGrade();
	//std::cout << desk_jockey << std::endl;
	//desk_jockey.signForm(paperwork);
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
	error_testing("pencil_pusher", 0, "form1", 1, 75);
	std::cout << std::endl;
	error_testing("pencil_pusher", 170, "form1", 1, 75);
	std::cout << std::endl;
	error_testing("pencil_pusher", 74, "form1", 0, 75);
	std::cout << std::endl;
	error_testing("pencil_pusher", 74, "form1", 151, 75);
	std::cout << std::endl;
	error_testing("pencil_pusher", 74, "form1", 75, 0);
	std::cout << std::endl;
	error_testing("pencil_pusher", 74, "form1", 75, 151);
	std::cout << std::endl;
	error_testing("pencil_pusher", 74, "form1", 75, 75);
	std::cout << std::endl;
	error_testing("pencil_pusher", 75, "form1", 75, 75);
	std::cout << std::endl;
	error_testing("pencil_pusher", 75, "form1", 74, 75);
	return (0);
}