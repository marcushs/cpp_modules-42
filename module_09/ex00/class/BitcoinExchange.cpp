/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:52:08 by hleung            #+#    #+#             */
/*   Updated: 2024/05/06 20:34:17 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/BitcoinExchange.hpp"

static bool	isValidDate(const std::string &date);
static bool	isLeapYear(const int &yr);
static void	trimWhiteSpace(std::string &str);
static bool	isValidValue(const std::string &value);
static bool	parseInput(const std::string &input, std::string &date, double &value);

/*------------------------------- Constructors -------------------------------*/

BitcoinExchange::BitcoinExchange()
{
	std::ifstream	ifs;
	std::string		str;
	
	ifs.open("data.csv", std::ifstream::in);
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
	std::string	value_str = str.substr(pos + 1);
	trimWhiteSpace(value_str);
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
		std::string	date;
		double		value;
		if (str.empty() || !str.compare("date | value") || !parseInput(str, date, value))
			continue;
		printCalculatedValue(date, value);
	}
	ifs.close();
}

void	BitcoinExchange::printCalculatedValue(const std::string &date, const double &value) const
{
	dataIt	it = this->_data.find(date);
	if (it == this->_data.end()) {
		it = this->_data.lower_bound(date);
		if (it == this->_data.begin()) {
			std::cout << "Error: no date entry before " << date << std::endl;
			return;
		}
		it--;
	}
	std::cout << date << " => " << value << " = " << it->second * value << std::endl;
}

/*------------------------- Static Helper Functions --------------------------*/

static void	trimWhiteSpace(std::string &str)
{
	if (str.empty())
		return ;
	size_t	begin = str.find_first_not_of(" \t\n\v\f\r");
	if (begin == str.npos)
		return ;
	size_t	end = str.find_last_not_of(" \t\n\v\f\r");
	str = str.substr(begin, end - begin + 1);
}

static bool	isValidDate(const std::string &date)
{
	if (date.length() != 10)
		return false;
	if (date[4] != '-' || date[7] != '-')
		return false;
	if (date.find_first_not_of("1234567890.-") != date.npos)
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
	if (value.empty())
		return false;
	if (value.find('-') != value.rfind('-'))
		return false;
	if (value.find('-') != value.npos && value[0] != '-')
		return false;
	if (value.find_first_not_of("1234567890.-") != value.npos)
		return false;
	if (value.find('.') != value.rfind('.'))
		return false;
	return true;
}

static bool	parseInput(const std::string &input, std::string &date, double &value)
{
	size_t	pos = input.find(" | ");
	if (pos == input.npos || pos != input.rfind(" | ")) {
		std::cout << "Error: bad input => " << input << std::endl;
		return false;
	}
	date = input.substr(0, pos);
	trimWhiteSpace(date);
	if (!isValidDate(date)) {
		std::cout << "Error: Invalid date" << std::endl;
		return false;
	}
	std::string	value_str = input.substr(pos + 3, input.npos);
	trimWhiteSpace(value_str);
	if (!isValidValue(value_str)) {
		std::cout << "Error: Invalid value" << std::endl;
		return false;
	}
	value = strtod(value_str.c_str(), NULL);
	if (value < 0) {
		std::cout << "Error: not a postitive number." << std::endl;
		return false;
	}
	if (value > 1000) {
		std::cout << "Error: too large a number." << std::endl;
		return false;
	}
	return true;
}


