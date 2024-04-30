/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 16:44:50 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/04/30 11:41:16 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

class Bureaucrat;

PresidentialPardonForm::PresidentialPardonForm(): AForm("Presidential pardon", 25, 5)
{
    //std::cout << "PresidentialPardonForm: Default constructor called" << std::endl;
    return;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target): AForm("Presidential pardon", 25, 5), _target(target)
{
    //std::cout << "PresidentialPardonForm: Parametric constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
    //std::cout << "PresidentialPardonForm: Destructor called" << std::endl;
    return;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm & other): AForm(other)
{
    //std::cout << "PresidentialPardonForm: Copy constructor called" << std::endl;
    *this = other;
    return;
}

PresidentialPardonForm & PresidentialPardonForm::operator=(const PresidentialPardonForm & other)
{
    //std::cout << "PresidentialPardonForm: Copy assignment operator called" << std::endl;
    if (this != &other){
        this->_target = other._target;
        }
	return (*this);
}

const std::string PresidentialPardonForm::getTarget( void ) const
{
    return (_target);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	this->execPermission(executor);
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

