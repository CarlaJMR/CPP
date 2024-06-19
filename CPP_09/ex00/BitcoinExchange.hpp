/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:48:35 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/06/19 14:56:41 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BitcoinExchange_HPP
#define BitcoinExchange_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <map>
#include <algorithm>
#include<iomanip>
#include <ctime>

class BitcoinExchange
{
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange & operator=(BitcoinExchange const & other);
        ~BitcoinExchange();

        void inputDataBase();
        void makeExchange(char *input_file);
        
        class	ErrorInputFile : public std::exception
		{
			public:
				const char	*what() const throw();
		};

        class DataBaseError : public std::exception
        {
            public :
                virtual const char* what() const throw();
        };
    
    private:
        std::map<std::string, float> _DB;
        float currentValue(std::string date);
};

bool checkDate(std::string date);

#endif