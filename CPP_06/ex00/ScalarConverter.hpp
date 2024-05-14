/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:43:46 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/05/14 12:41:38 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ScalarConverter_HPP
#define ScalarConverter_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <limits>
#include <iomanip>
#include <sstream>

class ScalarConverter
{
    public:
        static void convert(std::string literal);
        ~ScalarConverter();

    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &other);
        ScalarConverter & operator=(ScalarConverter const & other);
        static void charInput(char c);
        static void intInput(std::string s);
        static void floatInput(std::string s);
        static void doubleInput(std::string s);
};

#endif
