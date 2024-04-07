/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carla <carla@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:43:46 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/04/07 17:09:35 by carla            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        const std::string _name;
        bool    _is_signed;
        const int _sign_grade;
        const int _exec_grade; 

    public:
        Form(void);
        Form(const std::string name, const int sgrade, const int exgrade);
        Form(const Form &other);
        virtual ~Form(void);

        Form & operator=(const Form &other);

        const std::string getName() const;
        bool getSignStatus() const;
        int getSignGrade() const;
        int getExecGrade() const;
        
        bool beSigned(Bureaucrat &b);

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
};

std::ostream & operator <<(std::ostream &out, Form const &fo);

#endif
