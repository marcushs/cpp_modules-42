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
# include <fstream>
# include <map>
# include <string>
# include <cstdlib>


class BitcoinExchange
{

public:
	BitcoinExchange();
	// BitcoinExchange(const std::ifstream &ifs);
	BitcoinExchange(const BitcoinExchange &src);
	~BitcoinExchange();

	BitcoinExchange	&operator=(const BitcoinExchange &rhs);
	std::map<std::string, float> &getData();

private:
	std::map<std::string, float>	_data;
};


#endif
