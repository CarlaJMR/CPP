/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:44:09 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/04/12 18:19:52 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int	main(void)
{
	try
	{
		Bureaucrat				m("Maria", 20);
		Bureaucrat				a("Ana", 140);
		Bureaucrat				c("Chefe", 1);
		ShrubberyCreationForm	g("Garden");	
		PresidentialPardonForm	dr("Doctor Who");
		RobotomyRequestForm		b("Someone");
		
		std::cout << g << std::endl << std::endl;
		g.beSigned(m);
		m.executeForm(g);
		a.executeForm(g);

		std::cout << std::endl << b << std::endl << std::endl;
		b.beSigned(c);
		a.executeForm(b);
		m.executeForm(b);
		m.executeForm(b);
		c.executeForm(b);

		std::cout << std::endl << dr << std::endl << std::endl;
		dr.beSigned(m);
		m.executeForm(dr);
		c.executeForm(dr);
		
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}