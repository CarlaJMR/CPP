/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:31:35 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/04/26 17:05:19 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

class Bureaucrat;

AForm::AForm(): _name("FORM"), _is_signed(false), _sign_grade(1), _exec_grade(1)
{
    //std::cout << "AForm: Default constructor called" << std::endl;
    return;
}

AForm::AForm(const std::string name, const int sgrade, const int exgrade): _name(name), _is_signed(false), _sign_grade(sgrade), _exec_grade(exgrade)
{
    //std::cout << "AForm: Parametric constructor called" << std::endl;
    if (sgrade < 1 || exgrade < 1)
        throw AForm::GradeTooHighException();
    else if (sgrade > 150 || exgrade > 150)
        throw AForm::GradeTooLowException();
    return;
}

AForm::~AForm(void)
{
    //std::cout << "AForm: Destructor called" << std::endl;
    return;
}

AForm::AForm(const AForm & other): _name(other._name) , _sign_grade(other._sign_grade), _exec_grade(other._exec_grade)
{
    //std::cout << "Form: Copy constructor called" << std::endl;
    *this = other;
    return;
}

AForm & AForm::operator=(const AForm & other)
{
    //std::cout << "AForm: Copy assignment operator called" << std::endl;
    if (this != &other){
        _is_signed = other.getSignStatus();}
	return (*this);
}

const std::string AForm::getName( void ) const
{
    return (_name);
}

bool AForm::getSignStatus( void ) const
{
    return (_is_signed);
}

int AForm::getSignGrade( void ) const
{
    return (_sign_grade);
}

int AForm::getExecGrade( void ) const
{
    return (_exec_grade);
}

void AForm::beSigned(Bureaucrat &b)
{
    if (b.getGrade() > _sign_grade)
        throw AForm::GradeTooLowException();
    _is_signed = true;
}

const char	*AForm::GradeTooLowException::what() const throw()
{
	return ("AForm: Grade to low.");
}

const char	*AForm::GradeTooHighException::what() const throw()
{
	return ("AForm: Grade to high.");
}

const char	*AForm::NotSignedFormException::what() const throw()
{
	return ("AForm: not signed.");
}

std::ostream & operator <<(std::ostream &out, AForm const &f)
{
    out << f.getName();
    if (f.getSignStatus())
        out << ", signed, ";
    else
        out << ", not signed, ";
    out << "Grade to sign: " << f.getSignGrade() << ", Grade to execute: " << f.getExecGrade(); 
    return (out);
}

void AForm::execPermission(const Bureaucrat& b) const
{
    if (!_is_signed)
        throw AForm::NotSignedFormException();
    if (b.getGrade() > _exec_grade)
        throw AForm::GradeTooLowException();
}
