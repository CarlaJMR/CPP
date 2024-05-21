/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:43:46 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/05/21 14:52:24 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &other)
{
    (void)other;
}

RPN & RPN::operator=(RPN const & other)
{
    (void)other;
    return(*this);
}

RPN::~RPN() {}

bool lessThenTen(std::string s)
{
    for (int i = 0; i < s.size(); i++)
    {
        if (isdigit(s[i]) && isdigit(s[i + 1]))
            return (false);
    }
    return (true);
}

bool isOperation(char c)
{
    if (c == '-' || c == '+' || c == '*' || c == '/'){
        return(true);
    }
    return (false);
}

void RPN::calculate(std::string expression)
{
    if (expression.empty() || expression.find_first_not_of("0123456789+-/* ") != std::string::npos \
            || expression.find_first_of("+-*/") == std::string::npos || !lessThenTen(expression)) 
    {
		std::cerr << "Error" << std::endl;
        return;
	}
    
    
	for (int i = 0; i < expression.size(); i++)
    {
        if (isdigit(expression[i]))
            _numbers.push(1);
    }
}



