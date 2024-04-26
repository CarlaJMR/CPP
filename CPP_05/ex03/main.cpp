/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:44:09 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/04/26 17:33:00 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"

int	main(void)
{	
	Intern someRandomIntern;
	
	{
		AForm *rrf;
		rrf = NULL;
		
		try 
		{
			Bureaucrat bob("bob", 1);
			rrf = someRandomIntern.makeForm("robotomy request", "Bender");
			if (rrf)
			{
				bob.signForm(*rrf); 
				rrf->execute(bob);
			} 
		}
		catch (const std::exception &e)
		{
			std::cout << "Error: " << e.what() << std::endl;
		}
		if (rrf)
			delete rrf;
	}
	
	{
		AForm *rrf;
		rrf = NULL;
		
		try 
		{
			Bureaucrat bob("bob", 150);
			rrf = someRandomIntern.makeForm("robotomy request", "Bender");
			if (rrf)
			{
				bob.signForm(*rrf); 
				rrf->execute(bob);
			} 
		}
		catch (const std::exception &e)
		{
			std::cout << "Error: " << e.what() << std::endl;
		}
		if (rrf)
			delete rrf;
	}
	std::cout << std::endl;
	{
		AForm *rrf;
		rrf = NULL;
		
		try 
		{
			Bureaucrat bob("bob", 1);
			rrf = someRandomIntern.makeForm("presidential pardon", "Cupertino");
			if (rrf)
			{
				rrf->beSigned(bob); 
				rrf->execute(bob);
			} 
		}
		catch (const std::exception &e)
		{
			std::cout << "Error: " << e.what() << std::endl;
		}
		if (rrf)
			delete rrf;
	}
	std::cout << std::endl;
	{
		AForm *rrf;
		rrf = NULL;
	
		try 
		{
			Bureaucrat bob("bob", 1);
			rrf = someRandomIntern.makeForm("another form", "B");
			if (rrf)
			{
				bob.signForm(*rrf); 
				rrf->execute(bob);
			} 
		}
		catch (const std::exception &e)
		{
			std::cout << "Error: " << e.what() << std::endl;
		}
		if (rrf)
			delete rrf;
	}
	return (0);
}