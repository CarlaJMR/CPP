/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:43:46 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/04/30 11:35:54 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
    private:
        const std::string _name;
        int _grade;
        Bureaucrat & operator=(const Bureaucrat &other);

    public:
        Bureaucrat(void);
        Bureaucrat(const std::string name, int grade);
        Bureaucrat(const Bureaucrat &other);
        ~Bureaucrat(void);

        const std::string getName() const;
        int getGrade() const;
        void incrementGrade();
        void decrementGrade();

        void signForm(AForm &f);
        void executeForm(AForm const & form);

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

std::ostream & operator <<(std::ostream &out, Bureaucrat const &buc);

#endif
