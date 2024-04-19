/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:43:46 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/04/19 14:53:52 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(){}
        
Intern::Intern(const Intern &other)
{
    (void)other;
}

Intern::~Intern(){}
        
Intern & Intern::operator=(const Intern &other)
{
    (void)other;
    return(*this);
}

AForm *createPresidential(std::string target) 
{
	return new PresidentialPardonForm(target);
}

AForm *createRobotomy(std::string target) 
{
	return new RobotomyRequestForm(target);
}    

AForm *createShrubbery(std::string target) 
{
	return new ShrubberyCreationForm(target);
}    

AForm* Intern::makeForm(std::string name, std::string target)
{
    std::string forms[3] = { 
		"presidential pardon",
		"robotomy request",
		"shrubbery creation" };

	AForm *(*functions[3])(std::string target) = { 
        &createPresidential,
		&createRobotomy,
		&createShrubbery };

    for (int i = 0; i < 3; i++)
    {
        if (name == forms[i])
        {
            std::cout << "Intern creates " << name << std::endl;
            return ((*functions[i])(target));
        }
    }
    throw Intern::FormDoesNotExist();
}

const char	*Intern::FormDoesNotExist::what() const throw()
{
	return ("Can\'t create a form that does not exist!");
}

