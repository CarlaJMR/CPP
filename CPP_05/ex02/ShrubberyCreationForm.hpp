/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:43:46 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/04/12 16:53:42 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ShrubberyCreationForm_HPP
#define ShrubberyCreationForm_HPP

#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{ 
    private:
        std::string _target;
        ShrubberyCreationForm(void);
        
    public:
        ShrubberyCreationForm(const std::string target);
        ShrubberyCreationForm(const ShrubberyCreationForm &other);
        ~ShrubberyCreationForm(void);

        ShrubberyCreationForm & operator=(const ShrubberyCreationForm &other);

        const std::string getTarget() const;
       
        void execute(Bureaucrat const & executor) const;
};

#endif
