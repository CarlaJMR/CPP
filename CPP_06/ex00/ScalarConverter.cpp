/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:31:35 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/05/14 12:50:11 by cjoao-me         ###   ########.fr       */
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
    std::cout << "Char: impossible" << std::endl;
    std::cout << "Int: impossible" << std::endl;
    std::cout << "Float: impossible" << std::endl;
    std::cout << "Double: impossible" << std::endl;
}

void PseudoInput(std::string p)
{
    std::cout << "Char: impossible" << std::endl;
    std::cout << "Int: impossible" << std::endl;
    if (p == "+inf" || p == "-inf" || p == "nan")
    {
        std::cout << "Float: " << p << "f" << std::endl;
        std::cout << "Double: " << p << std::endl;
    }
    else
    {
        std::cout << "float: " << p << std::endl;
        std::cout << "double: " << p.substr(0, p.size() - 1) << std::endl;
    } 
}

void ScalarConverter::charInput(char c)
{
    std::cout << "Char: '" << c << "'" << std::endl;
	std::cout << "Int: " << static_cast<int>(c) << std::endl;
	std::cout << "Float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << 'f' << std::endl;
	std::cout << "Double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
}

void ScalarConverter::intInput(std::string s)
{
    std::stringstream out(s);
    int i;
    out >> i;
    if (!out.fail())
    {
        if (isprint(static_cast<char>(i)))
            std::cout << "Char: '" << static_cast<char>(i)  << "'" << std::endl;
        else{
            std::cout << "Char: Non displayable"  << std::endl;}
        std::cout << "Int: " << i << std::endl;
        std::cout << "Float: " << std::fixed << std::setprecision(1) << static_cast<float>(i) << "f" << std::endl;
        std::cout << "Double: " << std::fixed << std::setprecision(1) << static_cast<double>(i) << std::endl;
    }
    else
    {
        std::cout << "Char: impossible" << std::endl;
        std::cout << "Int: impossible" << std::endl;
        out.str("");
        out.clear();
        out << s;
        double x;
        out >> x;
        if(!out.fail())
        {
            if (x > std::numeric_limits<float>::max())
                std::cout << "Float: +inff" << std::endl;
            else if (-x > std::numeric_limits<float>::max())
                std::cout << "Float: -inff" << std::endl;
            else
                std::cout << "Float: " << std::fixed << std::setprecision(1) << static_cast<float>(x) << "f" << std::endl;
            std::cout << "Double: " << std::fixed << std::setprecision(1) << x << std::endl;
        }
        else
        {
            if(*(s.begin()) == '-')
            {
                std::cout << "Float: -inff" << std::endl;
                std::cout << "Double: -inf" << std::endl;
            }  
            else
            {
                std::cout << "Float: +inff" << std::endl;
                std::cout << "Double: +inf" << std::endl;
            }  
        }
    }
}

void ScalarConverter::floatInput(std::string s)
{
    std::stringstream out(s);
    float f;
    out >> f;
    if (!out.fail())
    {
        std::cout << isprint(static_cast<char>(f)) << std::endl;
        if (isprint(static_cast<char>(f)))
            std::cout << "Char: '" << static_cast<char>(f)  << "'" << std::endl;
        else{
            std::cout << "Char: Non displayable"  << std::endl;}
        if (f > std::numeric_limits<int>::max() || f < std::numeric_limits<int>::min())
            std::cout << "Int: impossible" << std::endl;
        else
            std::cout << "Int: " << static_cast<int>(f) << std::endl;
        std::cout << "Float: " << std::fixed << std::setprecision(1)<< f << "f" << std::endl;
	    std::cout << "Double: " << std::fixed << std::setprecision(1)<< static_cast<double>(f) << std::endl;
    }
    else
    {
        std::cout << "Char: impossible" << std::endl;
        std::cout << "Int: impossible" << std::endl;
        if(*(s.begin()) == '-')
            std::cout << "Float: -inff" << std::endl; 
        else
            std::cout << "Float: +inff" << std::endl;
        out.str("");
        out.clear();
        out << s;
        double x;
        out >> x;
        if (!out.fail())
            std::cout << "Double: " << std::fixed << std::setprecision(1) << x << std::endl;
        else
        {
            if(*(s.begin()) == '-')
                std::cout << "Double: -inf" << std::endl; 
            else
                std::cout << "Double: +inf" << std::endl;
        }
    }
}

void ScalarConverter::doubleInput(std::string s)
{
    std::stringstream out(s);
    double d;
    out >> d;
    if (!out.fail())
    {
         if (isprint(static_cast<char>(d)))
            std::cout << "Char: '" << static_cast<char>(d)  << "'" << std::endl;
        else{
            std::cout << "Char: " << "Non displayable"  << std::endl;}
        if (d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
            std::cout << "Int: impossible" << std::endl;
        else
            std::cout << "Int: " << static_cast<int>(d) << std::endl;
        if ((d > std::numeric_limits<float>::max()) || (-d > std::numeric_limits<float>::max()))
        {
            if(*(s.begin()) == '-')
                std::cout << "Float: -inff" << std::endl; 
            else
                std::cout << "Float: +inff" << std::endl;
        }
        else
            std::cout << "Float: " << std::fixed << std::setprecision(1)<< static_cast<float>(d)  << "f" << std::endl;
        std::cout << "Double: " << std::fixed << std::setprecision(1)<< d << std::endl;
    } 
    else
    {
        std::cout << "Char: impossible" << std::endl;
        std::cout << "Int: impossible" << std::endl;
        if(*(s.begin()) == '-')
        {
            std::cout << "Float: -inff" << std::endl;
            std::cout << "Double: -inf" << std::endl;
        }  
        else
        {
            std::cout << "Float: +inff" << std::endl;
            std::cout << "Double: +inf" << std::endl;
        }  
    }
}

void ScalarConverter::convert(std::string literal)
{
    bool digit = true;
    int dot = 0;
    int f = 0;
    unsigned int i = 0;
    
    if (literal.length() == 1 && !isdigit(*literal.begin())) 
    {
        charInput(*literal.begin());
        return;
    }
    if ( literal == "nan" || literal == "nanf" || literal == "+inf" || literal == "+inff" || literal == "-inf" || literal == "-inff") 
    {
        PseudoInput(literal);
        return;
    }
   
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
    
    if (!literal.empty() && digit && !dot && !f)
    {
            intInput(literal);
            return;
    }
    
    if (digit && dot == 1 && f == 1 && *(literal.end() - 1) == 'f' )
    {
        floatInput(literal);
        return;
    }
    if (digit && dot == 1 && !f)
    {
        doubleInput(literal);
        return;
    }
    ImpossibleInput();
}

