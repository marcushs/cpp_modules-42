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


/*------------------------------- Constructors -------------------------------*/

BitcoinExchange::BitcoinExchange()
{
	std::ifstream	ifs;
	std::string		str;
	
	ifs.open("../cpp_09/data.csv");
	if (!ifs.good()) {
		std::cout << "Error: cannot access database" << std::endl;
		return ;
	}
	getline(ifs, str);
	while (getline(ifs, str)) {
		if (str.empty())
			continue;

		size_t			pos = str.find(',');
		if (pos == str.npos) {
			std::cout << "Error: no delimiter\n";
			return ;
		}
		std::string		key = str.substr(0, pos);

		if (key.length() != 10)
		{
			std::cout << "Error: Bad date format" << std::endl;
			return ;
		}
		float	value = strtof(str.substr(str.find(',') + 1, str.npos).c_str(), NULL);
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

// bool	BitcoinExchange::isValidDate(const std::string &date)
// {
	
// }