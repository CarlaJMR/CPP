/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:43:46 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/04/30 11:42:49 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RobotomyRequestForm_HPP
#define RobotomyRequestForm_HPP

#include <ctime>
#include <cstdlib>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{ 
    private:
        std::string _target;
        RobotomyRequestForm(void);
        RobotomyRequestForm & operator=(const RobotomyRequestForm &other);
        
    public:
        RobotomyRequestForm(const std::string target);
        RobotomyRequestForm(const RobotomyRequestForm &other);
        ~RobotomyRequestForm(void);
        
        const std::string getTarget() const;
       
        void execute(Bureaucrat const & executor) const;
};

#endif
