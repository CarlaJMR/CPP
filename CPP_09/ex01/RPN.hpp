/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:43:46 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/05/31 13:24:32 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <algorithm>

class RPN
{
    public:
        RPN();
        RPN(const RPN &other);
        RPN & operator=(RPN const & other);
        ~RPN();

        void calculate(std::string expression);
        
        class	InvalidExpression : public std::exception
		{
			public:
				const char	*what() const throw();
		};
    
    private:
        std::stack<float> _numbers;
};

#endif