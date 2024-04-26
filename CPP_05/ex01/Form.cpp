/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:31:35 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/04/26 16:57:40 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

class Bureaucrat;

Form::Form(): _name("FORM"), _is_signed(false), _sign_grade(1), _exec_grade(1)
{
    //std::cout << "Form: Default constructor called" << std::endl;
    return;
}

Form::Form(const std::string name, const int sgrade, const int exgrade): _name(name), _is_signed(false), _sign_grade(sgrade), _exec_grade(exgrade)
{
    //std::cout << "Form: Parametric constructor called" << std::endl;
    if (sgrade < 1 || exgrade < 1)
        throw Form::GradeTooHighException();
    else if (sgrade > 150 || exgrade > 150)
        throw Form::GradeTooLowException();
    return;
}

Form::~Form(void)
{
    //std::cout << "Form: Destructor called" << std::endl;
    return;
}

Form::Form(const Form & other): _name(other._name) , _sign_grade(other._sign_grade), _exec_grade(other._exec_grade)
{
    //std::cout << "Form: Copy constructor called" << std::endl;
    *this = other;
    return;
}

Form & Form::operator=(const Form & other)
{
    //std::cout << "Form: Copy assignment operator called" << std::endl;
    if (this != &other){
        _is_signed = other.getSignStatus();}
	return (*this);
}

const std::string Form::getName( void ) const
{
    return (_name);
}

bool Form::getSignStatus( void ) const
{
    return (_is_signed);
}

int Form::getSignGrade( void ) const
{
    return (_sign_grade);
}

int Form::getExecGrade( void ) const
{
    return (_exec_grade);
}

void Form::beSigned(Bureaucrat &b)
{
    if (b.getGrade() > _sign_grade)
        throw Form::GradeTooLowException();
    _is_signed = true;
}

const char	*Form::GradeTooLowException::what() const throw()
{
	return ("Form: Grade to low.");
}

const char	*Form::GradeTooHighException::what() const throw()
{
	return ("Form: Grade to high.");
}

std::ostream & operator <<(std::ostream &out, Form const &f)
{
    out << f.getName();
    if (f.getSignStatus())
        out << ", signed, ";
    else
        out << ", not signed, ";
    out << "Grade to sign: " << f.getSignGrade() << ", Grade to execute: " << f.getExecGrade(); 
    return (out);
}
