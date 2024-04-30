/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:43:46 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/04/30 11:41:57 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PresidentialPardonForm_HPP
#define PresidentialPardonForm_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{ 
    private:
        std::string _target;
        PresidentialPardonForm(void);
        PresidentialPardonForm & operator=(const PresidentialPardonForm &other);
        
    public:
        PresidentialPardonForm(const std::string target);
        PresidentialPardonForm(const PresidentialPardonForm &other);
        ~PresidentialPardonForm(void);

        const std::string getTarget() const;
       
        void execute(Bureaucrat const & executor) const;
};

#endif
