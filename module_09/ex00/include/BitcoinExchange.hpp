/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:52:25 by hleung            #+#    #+#             */
/*   Updated: 2024/04/29 17:14:10 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP
# include <iostream>
# include <fstream>
# include <map>
# include <string>
# include <cstdlib>

typedef std::map<std::string, double>::const_iterator dataIt;

class BitcoinExchange
{
		
public:
	BitcoinExchange();
	~BitcoinExchange();

	void	addToMap(const std::string &str);
	void	findExchangeValue(const char *inputPath);
	void	printCalculatedValue(const std::string &date, const double &value) const;

private:
	BitcoinExchange(const BitcoinExchange &src);
	BitcoinExchange	&operator=(const BitcoinExchange &rhs);
	std::map<std::string, double>	_data;
};


#endif
