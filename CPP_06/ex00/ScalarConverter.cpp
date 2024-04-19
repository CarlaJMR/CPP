/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:31:35 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/04/19 18:00:55 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}

ScalarConverter::~ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter & other)
{
    *this = other;
}

ScalarConverter & ScalarConverter::operator=(const ScalarConverter & other)
{
    (void)other;
	return (*this);
}

void ImpossibleInput(void)
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
}

void PseudoInput(std::string p)
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    if (p == "+inf" || p == "-inf" || p == "nan")
    {
        std::cout << "float: " << p << "f" << std::endl;
        std::cout << "double: " << p << std::endl;
    }
    else
    {
        std::cout << "float: " << p << std::endl;
        std::cout << "double: " << p.substr(0, p.size() - 1) << std::endl;
    } 
}

void CharInput(std::string s)
{
    std::cout << "Char: '" << s[0] << "'" << std::endl;
	std::cout << "Int: " << static_cast<int>(s[0]) << std::endl;
	std::cout << "Float: " << std::fixed << std::setprecision(1) << static_cast<float>(s[0]) << 'f' << std::endl;
	std::cout << "Double: " << std::fixed << std::setprecision(1) << static_cast<double>(s[0]) << std::endl;
}

void IntInput()
{
    
}

void FloatInput()
{
    
}

void DoubleInput()
{
    
}

void ScalarConverter::convert(std::string literal)
{
    if (literal.length() == 1 && !isdigit(literal[0])) 
    {
        CharInput(literal);
        return;
    }
    if ( literal== "nan" || literal == "nanf" || literal == "+inf" || literal == "+inff" || literal == "-inf" || literal == "-inff") 
    {
        PseudoInput(literal);
        return;
    }
    ImpossibleInput();
}

