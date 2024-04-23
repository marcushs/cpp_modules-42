/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:52:25 by hleung            #+#    #+#             */
/*   Updated: 2024/01/09 16:39:16 by hleung           ###   ########.fr       */
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
	BitcoinExchange(const BitcoinExchange &src);
	~BitcoinExchange();

	BitcoinExchange	&operator=(const BitcoinExchange &rhs);
	const std::map<std::string, float> &getData() const;
	bool	isValidDate(const std::string &date);

private:
	std::map<std::string, float>	_data;
};


#endif
