/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:52:08 by hleung            #+#    #+#             */
/*   Updated: 2024/01/09 16:39:52 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/BitcoinExchange.hpp"

int	getDateSum(std::string &date);

/*------------------------------- Constructors -------------------------------*/

BitcoinExchange::BitcoinExchange()
{
	std::ifstream ifs;
	std::string str;
	
	ifs.open("../cpp_09/data.csv");
	if (!ifs.good())
	{
		std::cout << "Error: cannot access database" << std::endl;
		return ;
	}
	getline(ifs, str);
	while (getline(ifs, str))
	{
		// std::cout << str << std::endl;
		std::string key = str.substr(0, str.find(','));
		getDateSum(key);
		// float	value = strtof(str.substr(str.find(',') + 1, str.npos).c_str(), NULL);
		// std::cout << key << ", ";
		// std::cout << value << std::endl;
		
		// this->_data.insert(std::make_pair(key, value));
	}
	// std::cout << "opened db" << std::endl;
	ifs.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) {*this = src;}

/*-------------------------------- Destructor --------------------------------*/

BitcoinExchange::~BitcoinExchange() {}

/*--------------------------------- Overload ---------------------------------*/

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &rhs)
{
	static_cast<void>(rhs);
	// if (this != &rhs)
	// {
		
	// }
	return (*this);
}

/*---------------------------------- Getter ----------------------------------*/

std::map<std::string, float> &BitcoinExchange::getData()
{
	return this->_data;
}

/*---------------------------------- Setter ----------------------------------*/

/*----------------------------- Member Functions -----------------------------*/

int	getDateSum(std::string &date)
{
	std::string	strs[3] = {0};
	std::istringstream	src(date);
	while ()
	std::cout << yr << std::endl;
	return 0;
}