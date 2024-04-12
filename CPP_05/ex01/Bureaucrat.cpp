/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:31:35 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/04/12 14:13:00 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp" 

Bureaucrat::Bureaucrat(): _name("Buuuu Crat"), _grade(150)
{
    //std::cout << "Bureaucrat: Default constructor called" << std::endl;
    return;
}

Bureaucrat::Bureaucrat(const std::string name, int grade): _name(name), _grade(grade)
{
    //std::cout << "Bureaucrat: Parametric constructor called" << std::endl;
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    return;
}

Bureaucrat::~Bureaucrat(void)
{
    //std::cout << "Bureaucrat: Destructor called" << std::endl;
    return;
}

Bureaucrat::Bureaucrat(const Bureaucrat & other)
{
    //std::cout << "Bureaucrat: Copy constructor called" << std::endl;
    *this = other;
    return;
}

Bureaucrat & Bureaucrat::operator=(const Bureaucrat & other)
{
    //std::cout << "Bureaucrat: Copy assignment operator called" << std::endl;
    if (this != &other){
        _grade = other.getGrade();}
	return (*this);
}

const std::string Bureaucrat::getName( void ) const
{
    return (_name);
}

int Bureaucrat::getGrade( void ) const
{
    return (_grade);
}

void Bureaucrat::incrementGrade()
{
    if (_grade < 2)
        throw Bureaucrat::GradeTooHighException();
    _grade--;
}

void Bureaucrat::decrementGrade()
{
    if (_grade > 149)
        throw Bureaucrat::GradeTooLowException();
    _grade++;
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Bureaucrat: Grade to low.");
}

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Bureaucrat: Grade to high.");
}

std::ostream & operator <<(std::ostream &out, Bureaucrat const &buc)
{
    out << buc.getName();
    out << ", bureaucrat grade ";
    out << buc.getGrade(); 
    return (out);
}

void Bureaucrat::signForm(Form &f)
{
    if (f.getSignStatus())
    {
        std::cout << getName() << " couldn\'t sign " << f.getName();
        std::cout << " because it\'s already signed." << std::endl;
    }
    else
    {
        if (_grade > f.getSignGrade())
        {
            std::cout << getName() << " couldn\'t sign " << f.getName();
            std::cout << " because grade is too low." << std::endl;
        }
        else
        {
            std::cout << getName() << " signed " << f.getName() << std::endl;
            f.beSigned(*this);
        }
    }
}
