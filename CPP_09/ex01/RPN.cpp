/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:43:46 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/05/31 13:22:07 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &other)
{
    *this = other;
}

RPN & RPN::operator=(RPN const & other)
{
    _numbers = other._numbers;
    return(*this);
}

RPN::~RPN() {}

bool lessThanTen(std::string s)
{
    for (size_t i = 0; i < s.size(); i++)
    {
        if (isdigit(s[i]) && isdigit(s[i + 1]))
            return (false);
    }
    return (true);
}

bool isOperation(std::string s)
{
    if (s == "-" || s == "+" || s == "*" || s == "/"){
        return(true);
    }
    return (false);
}

void RPN::calculate(std::string expression)
{
    std::string token;
    std::istringstream iss(expression);
    
    if (expression.empty() || expression.find_first_not_of("0123456789+-/* ") != std::string::npos \
            || expression.find_first_of("+-*/") == std::string::npos || !lessThanTen(expression)) 
    {
		throw RPN::InvalidExpression();
	}
    
    while (iss >> token) 
    {
        if (isdigit(*token.begin()))
                _numbers.push(atoi(token.c_str()));
        else if (isOperation(token))
        {
            if (_numbers.size() < 2)
                throw RPN::InvalidExpression();
           
			float b = _numbers.top();
			_numbers.pop();

			float a = _numbers.top();
			_numbers.pop();
            
            switch (*token.begin())
            {
                case '+':
                    _numbers.push(a + b);
                    break;
                case '*':
                    _numbers.push(a * b);
                    break;
                case '-':
                    _numbers.push(a - b);
                    break;
                case '/':
                    _numbers.push(a / b);
                    break;
            }
        }
        else
            throw RPN::InvalidExpression();
    }        
            
    if (_numbers.size() > 1){
        throw RPN::InvalidExpression();}

	std::cout << _numbers.top() << std::endl;
}

const char	*RPN::InvalidExpression::what() const throw()
{
	return ("invalid input.");
}
