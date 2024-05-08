/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:31:35 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/05/08 18:20:03 by cjoao-me         ###   ########.fr       */
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

void printResult(char c)
{
    std::cout << "Char: '" << c << "'" << std::endl;
	std::cout << "Int: " << static_cast<int>(c) << std::endl;
	std::cout << "Float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << 'f' << std::endl;
	std::cout << "Double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
}

void printResult(int i)
{
    if (isprint(i))
        std::cout << "Char: '" << static_cast<char>(i)  << "'" << std::endl;
    else{
        std::cout << "Char: " << "Non displayable"  << std::endl;}
	std::cout << "Int: " << i << std::endl;
	std::cout << "Float: " << std::fixed << std::setprecision(1) << static_cast<float>(i) << "f" << std::endl;
	std::cout << "Double: " << std::fixed << std::setprecision(1) << static_cast<double>(i) << std::endl;
}

void printResult(float f)
{
    if (isprint(static_cast<char>(f)))
        std::cout << "Char: '" << static_cast<char>(f)  << "'" << std::endl;
    else{
        std::cout << "Char: " << "Non displayable"  << std::endl;}
	std::cout << "Int: " << static_cast<int>(f) << std::endl;
	std::cout << "Float: " << std::fixed << std::setprecision(1)<< f << "f" << std::endl;
	std::cout << "Double: " << std::fixed << std::setprecision(1)<< static_cast<double>(f) << std::endl;
}

void printResult(double d)
{
    if (isprint(static_cast<char>(d)))
        std::cout << "Char: '" << static_cast<char>(d)  << "'" << std::endl;
    else{
        std::cout << "Char: " << "Non displayable"  << std::endl;}
	std::cout << "Int: " << static_cast<int>(d) << std::endl;
	std::cout << "Float: " << std::fixed << std::setprecision(1)<< static_cast<float>(d)  << "f" << std::endl;
	std::cout << "Double: " << std::fixed << std::setprecision(1)<< d << std::endl;
}

void ScalarConverter::convert(std::string literal)
{
    if (literal.length() == 1 && !isdigit(*literal.begin())) 
    {
        printResult(*literal.begin());
        return;
    }
    if ( literal == "nan" || literal == "nanf" || literal == "+inf" || literal == "+inff" || literal == "-inf" || literal == "-inff") 
    {
        PseudoInput(literal);
        return;
    }
    bool digit = true;
    int dot = 0;
    int f = 0;
    unsigned int i = 0;
    if (*literal.begin() == '+' || *literal.begin() == '-')
        i++;
    for (unsigned j = i; j < literal.size(); j++)
    {
        if (!isdigit(literal[j]) && literal[j] != '.' && literal[j] != 'f')
        {
            digit = false;
            break;
        }
        else if (literal[j] == '.')
            dot++;
        else if (literal[j] == 'f')
            f++;  
    }
    if (digit && !dot && !f)
    {
        printResult(atoi(literal.c_str()));
        return;
    }
    if (digit && dot == 1 && f == 1 && *(literal.end() - 1) == 'f' )
    {
        printResult(static_cast<float>(std::atof(literal.c_str())));
        return;
    }
    if (digit && dot == 1 && !f)
    {
        printResult(std::atof(literal.c_str()));
        return;
    }
    ImpossibleInput();
}

