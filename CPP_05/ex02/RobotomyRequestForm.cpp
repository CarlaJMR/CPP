/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 16:44:50 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/04/12 18:11:52 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

class Bureaucrat;

RobotomyRequestForm::RobotomyRequestForm(): AForm("robotomy request", 72, 45)
{
    //std::cout << "RobotomyRequestForm: Default constructor called" << std::endl;
    return;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target): AForm("robotomy request", 72, 45), _target(target)
{
    //std::cout << "RobotomyRequestForm: Parametric constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
    //std::cout << "RobotomyRequestForm: Destructor called" << std::endl;
    return;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm & other): AForm(other)
{
    //std::cout << "RobotomyRequestForm: Copy constructor called" << std::endl;
    *this = other;
    return;
}

RobotomyRequestForm & RobotomyRequestForm::operator=(const RobotomyRequestForm & other)
{
    //std::cout << "RobotomyRequestForm: Copy assignment operator called" << std::endl;
    if (this != &other){
        this->_target = other._target;}
	return (*this);
}

const std::string RobotomyRequestForm::getTarget( void ) const
{
    return (_target);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	this->execPermission(executor);
	std::cout << " ....... some drilling noises .........." << std::endl;
    srand(std::time(0));
	if (rand() % 2 == 0)
		std::cout << _target << " has been robotomized successfully" << std::endl;
	else
		std::cout << "The robotomy of " << _target << " failed" << std::endl;
}
