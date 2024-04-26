/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:52:08 by hleung            #+#    #+#             */
/*   Updated: 2024/04/26 09:25:49 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/BitcoinExchange.hpp"


/*------------------------------- Constructors -------------------------------*/

BitcoinExchange::BitcoinExchange()
{
	std::ifstream	ifs;
	std::string		str;
	
	ifs.open("../cpp_09/data.csv");
	if (!ifs.good()) {
		std::cout << "Error: cannot access database" << std::endl;
		throw BitcoinExchange::ConstructorException();
	}
	getline(ifs, str);
	while (getline(ifs, str)) {
		if (str.empty())
			continue;

		size_t	pos = str.find(',');
		if (pos != str.rfind(',') || pos == str.npos) {
			std::cout << "Error: Bad data entry" << std::endl;
			throw BitcoinExchange::ConstructorException();
		}
		std::string		key = str.substr(0, pos);
		if (!isValidDate(key))
		{
			std::cout << "Error: Bad date\n";
			throw BitcoinExchange::ConstructorException();
		}
		float	value = strtof(str.substr(pos + 1, str.npos).c_str(), NULL);
		this->_data.insert(std::make_pair(key, value));
	}
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

const std::map<std::string, float> &BitcoinExchange::getData() const { return this->_data; }

/*---------------------------------- Setter ----------------------------------*/

/*----------------------------- Member Functions -----------------------------*/

bool	BitcoinExchange::isValidDate(const std::string &date)
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

bool	BitcoinExchange::isLeapYear(const int &yr)
{
	if ((yr % 4 == 0 && yr % 100 != 0) || yr % 400 == 0)
		return true;
	return false;
}
