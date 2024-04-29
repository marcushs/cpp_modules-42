/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:52:08 by hleung            #+#    #+#             */
/*   Updated: 2024/04/28 15:59:58 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/BitcoinExchange.hpp"

static bool	isValidDate(const std::string &date);
static bool	isLeapYear(const int &yr);
static void	trimWhiteSpace(std::string &str);
static bool	isValidValue(const std::string &value);
static bool	isValidInput(const std::string &input);

/*------------------------------- Constructors -------------------------------*/

BitcoinExchange::BitcoinExchange()
{
	std::ifstream	ifs;
	std::string		str;
	
	ifs.open("../cpp_09/data.csv", std::ifstream::in);
	if (!ifs.good())
		throw std::runtime_error("Error: Cannot access database");
	while (getline(ifs, str)) {
		if (str.empty() || !str.compare("date,exchange_rate"))
			continue;
		addToMap(str);
	}
	if (this->_data.empty())
		throw std::runtime_error("Error: Empty database");
	ifs.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) {*this = src;}

/*-------------------------------- Destructor --------------------------------*/

BitcoinExchange::~BitcoinExchange() {}

/*--------------------------------- Overload ---------------------------------*/

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &rhs)
{
	if (this != &rhs)
		this->_data = rhs._data;	
	return (*this);
}

/*---------------------------------- Getter ----------------------------------*/

const std::map<std::string, double> &BitcoinExchange::getData() const { return this->_data; }

/*---------------------------------- Setter ----------------------------------*/

/*----------------------------- Member Functions -----------------------------*/

void	BitcoinExchange::addToMap(const std::string &str)
{
	size_t	pos = str.find(',');
	if (pos != str.rfind(',') || pos == str.npos)
		throw std::runtime_error("Error: Invalid data entry");
	std::string	key = str.substr(0, pos);
	trimWhiteSpace(key);
	if (!isValidDate(key))
		throw std::runtime_error("Error: Invalid date");
	std::string	value_str = str.substr(pos + 1, str.npos);
	if (!isValidValue(value_str)) 
		throw std::runtime_error("Error: Invalid value");
	double	value = strtod(value_str.c_str(), NULL);
	this->_data.insert(std::make_pair(key, value));
}

void	BitcoinExchange::findExchangeValue(const char *inputPath)
{
	std::ifstream	ifs;
	std::string		str;
	
	ifs.open(inputPath, std::ifstream::in);
	if (!ifs.good())
		throw std::runtime_error("Error: Cannot open input file");
	while (getline(ifs, str)) {
		if (str.empty() || !str.compare("date | value") || !isValidInput(str))
			continue;
	}
	ifs.close();
}

/*------------------------- Static Helper Functions --------------------------*/

static void	trimWhiteSpace(std::string &str)
{
	if (str.empty())
		return ;
	size_t	begin = str.find_first_not_of(" \t\n\v\f\r");
	size_t	end = str.find_last_not_of(" \t\n\v\f\r");
	str = str.substr(begin, end - begin + 1);
}

static bool	isValidDate(const std::string &date)
{
	if (date.length() != 10)
		return false;
	if (date[4] != '-' || date[7] != '-')
		return false;

	int	yr = std::atoi(date.substr(0,4).c_str());
	if (yr < 2009 || yr > 2100)
		return false;

	int	mon = std::atoi(date.substr(5,2).c_str());
	if (mon < 1 || mon > 12)
		return false;
	
	int	maxDays[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int	day = std::atoi(date.substr(8,2).c_str());
	if (day < 1 || day > maxDays[mon - 1] || (mon == 2 && !isLeapYear(yr) && day > 28))
		return false;
	return true;
}

static bool	isLeapYear(const int &yr)
{
	return (yr % 4 == 0 && yr % 100 != 0) || yr % 400 == 0;
}

static bool	isValidValue(const std::string &value)
{
	if (value.find_first_not_of(" \t\n\v\f\r1234567890.") != std::string::npos)
		return false;
	if (value.find('.') != value.rfind('.'))
		return false;
	return true;
}

static bool	isValidInput(const std::string &input)
{
	size_t	pos = input.find('|');
	if (pos == input.npos || pos != input.rfind('|')) {
		std::cout << "Error: bad input => " << input << std::endl;
		return false;
	}
	std::string	date = input.substr(0, pos);
	trimWhiteSpace(date);
	if (!isValidDate(date)) {
		std::cout << "Error: Invalid date" << std::endl;
		return false;
	}
	std::string	value_str = input.substr(pos + 1, input.npos);
	
}
