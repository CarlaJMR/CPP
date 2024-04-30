/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:43:46 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/04/30 11:38:30 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        const std::string _name;
        bool    _is_signed;
        const int _sign_grade;
        const int _exec_grade;
        AForm & operator=(const AForm &other); 

    public:
        AForm(void);
        AForm(const std::string name, const int sgrade, const int exgrade);
        AForm(const AForm &other);
        virtual ~AForm(void);

        const std::string getName() const;
        bool getSignStatus() const;
        int getSignGrade() const;
        int getExecGrade() const;
        
        void beSigned(Bureaucrat &b);
        virtual void execute(Bureaucrat const & executor) const = 0;
        void execPermission(const Bureaucrat& b) const;

        class	GradeTooLowException : public std::exception
		{
			public:
				const char	*what() const throw();
		};
		class	GradeTooHighException : public std::exception
		{
			public:
				const char	*what() const throw();
		}; 
        class	NotSignedFormException : public std::exception
		{
			public:
				const char	*what() const throw();
		}; 
};

std::ostream & operator <<(std::ostream &out, AForm const &fo);

#endif
