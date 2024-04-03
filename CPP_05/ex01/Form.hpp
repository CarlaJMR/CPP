/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carla <carla@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:43:46 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/03/29 21:10:10 by carla            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include <exception>

class Form
{
    private:
        const std::string name;
        bool    is_signed;
        const int sign_grade;
        const int exec_grade; 

    public:
        Form(void);
        Form(const std::string name, int grade);
        Form(const Form &other);
        virtual ~Form(void);

        Form & operator=(const Form &other);

        const std::string getName() const;
        int getGrade() const;
        void incrementGrade();
        void decrementGrade();

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
