/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:48:35 by cjoao-me          #+#    #+#             */
/*   Updated: 2024/06/19 15:46:11 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    *this = other;
}

BitcoinExchange & BitcoinExchange::operator=(BitcoinExchange const & other)
{
    _DB = other._DB;
    return(*this);
}

BitcoinExchange::~BitcoinExchange() {}


void BitcoinExchange::makeExchange(char *input_file)
{
	std::ifstream filename(input_file);
	std::string date;
	double value;
	char *prt;
	if (filename.fail())
		throw BitcoinExchange::ErrorInputFile();
	std::string line = "";
	std::getline(filename, line);
	if (line != "date | value")
		throw BitcoinExchange::ErrorInputFile();
	while(std::getline(filename, line))
	{
		date = line.substr(0, 10);
		if (!checkDate(date))
			std::cout << "Error: bad input (date) => " << date << std::endl;
		else if (line.size() > 13 && line.substr(10, 3) == " | " )
		{
			value = std::strtod(line.substr(13).c_str(), &prt);
			if (*prt || value < 0){
				std::cout << "Error: not a positive number." << std::endl;}
			else if (value > 1000){
				std::cout << "Error: too large number." << std::endl;}
			else{
				std::cout << date << " => " << value << " = " << value * currentValue(date) << std::endl;}
		}
		else
			std::cout << "Error: bad input => " << line << std::endl;
	}
}

void BitcoinExchange::inputDataBase()
{
	std::string date;
	float value;
	char *prt;
	std::ifstream db("data.csv");
	if (db.fail())
		throw BitcoinExchange::DataBaseError();
	std::string line = "";
	std::getline(db, line);
	if (line != "date,exchange_rate")
		throw BitcoinExchange::DataBaseError();
	while(std::getline(db, line))
	{
		if (line[10] != ',' || !isdigit(line[11]))
			throw BitcoinExchange::DataBaseError();
		date = line.substr(0, 10);
		if (!checkDate(date))
			throw BitcoinExchange::DataBaseError();
		value = std::strtod(line.substr(11).c_str(), &prt);
		if (*prt)
			throw BitcoinExchange::DataBaseError();
		_DB[date] = value;
	}
}

bool checkDate(std::string date)
{
    struct std::tm tm = {};
	time_t now;
    time(&now);
    
    struct tm *current_date = localtime(&now);
   
    
	if (!strptime(date.c_str(), "%Y-%m-%d", &tm)){
		return (false);}
	if (tm.tm_year + 1900 < 2009 || tm.tm_year > current_date->tm_year){
		return (false);}
    if ((tm.tm_mday == 31) && ((tm.tm_mon == 3) || (tm.tm_mon == 5) || (tm.tm_mon == 8) || (tm.tm_mon == 10))){
		return (false);}
	if ((tm.tm_mday >= 30) && (tm.tm_mon == 1)){
		return (false);}
	if ((tm.tm_mday == 29) && (tm.tm_mon == 1))
	{
		if ((tm.tm_year + 100) % 4){
			return (false);}
		if ((!(tm.tm_year + 100) % 100) && (tm.tm_year + 100) % 400){
			return (false);}
	}
	if (tm.tm_year == current_date->tm_year && tm.tm_mon > current_date->tm_mon){
		return (false);}
	else if (tm.tm_year == current_date->tm_year && tm.tm_mon == current_date->tm_mon && tm.tm_mday > current_date->tm_mday){
		return (false);}
	return (true);
}

float BitcoinExchange::currentValue(std::string date)
{
	std::map<std::string, float>::iterator it = _DB.lower_bound(date);

	if (it == _DB.end())
		it--;
    if (it->first > date)
		it--;
	return(it->second);
}

const char	*BitcoinExchange::ErrorInputFile::what() const throw()
{
	return ("Impossible to open input file, or empty file or wrong header.");
}

const char	*BitcoinExchange::DataBaseError::what() const throw()
{
	return ("Impossible to open database or data base error.");
}