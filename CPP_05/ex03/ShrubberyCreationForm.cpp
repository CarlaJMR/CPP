/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 16:44:50 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/04/30 11:50:16 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

class Bureaucrat;

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("shrubbery creation", 145, 137)
{
    //std::cout << "ShrubberyCreationForm: Default constructor called" << std::endl;
    return;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target): AForm("shrubbery creation", 145, 137), _target(target)
{
    //std::cout << "ShrubberyCreationForm: Parametric constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
    //std::cout << "ShrubberyCreationForm: Destructor called" << std::endl;
    return;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm & other): AForm(other)
{
    //std::cout << "ShrubberyCreationForm: Copy constructor called" << std::endl;
    *this = other;
    return;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(const ShrubberyCreationForm & other)
{
    //std::cout << "ShrubberyCreationForm: Copy assignment operator called" << std::endl;
    if (this != &other){
        this->_target = other._target;}
	return (*this);
}

const std::string ShrubberyCreationForm::getTarget( void ) const
{
    return (_target);
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	this->execPermission(executor);
	std::ofstream file(( this->_target + "_shrubbery" ).c_str());
	if (!file.fail())
    {
        file <<"          &&& &&  & &&" << std::endl;
        file <<"      && & /& /& ()|/ @, &&" << std::endl;
        file <<"      & /(/&/&||/& /_/)_&/_&" << std::endl;
        file <<"   &() & /&|()|/& /  % & ()" << std::endl;
        file <<"  &_ _&&_  |& |&&/&__%_/_& &&" << std::endl;
        file <<"&&   && & &| &| /& & % ()& /&&" << std::endl;
        file <<"()&_---()& & |&&-&&--%---()~" << std::endl;
        file <<"     &&      |||" << std::endl;
        file <<"             |||" << std::endl;
        file <<"             |||" << std::endl;
        file <<"             |||" << std::endl;
        file <<"       , -=-~  .-^- _" << std::endl;
        file.close();
    }
}

