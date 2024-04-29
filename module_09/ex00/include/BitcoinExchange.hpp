/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:52:25 by hleung            #+#    #+#             */
/*   Updated: 2024/04/28 15:47:42 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP
# include <iostream>
# include <iomanip>
# include <sstream>
# include <fstream>
# include <map>
# include <string>
# include <cstdlib>

class BitcoinExchange
{
		
public:
	BitcoinExchange();
	~BitcoinExchange();

	const std::map<std::string, double> &getData() const;
	void	addToMap(const std::string &str);

	void	findExchangeValue(const char *inputPath);

private:
	BitcoinExchange(const BitcoinExchange &src);
	BitcoinExchange	&operator=(const BitcoinExchange &rhs);
	std::map<std::string, double>	_data;
};


#endif
