/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:52:25 by hleung            #+#    #+#             */
/*   Updated: 2024/04/26 16:20:41 by hleung           ###   ########.fr       */
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
	BitcoinExchange(char *path);
	BitcoinExchange(const BitcoinExchange &src);
	~BitcoinExchange();

	BitcoinExchange	&operator=(const BitcoinExchange &rhs);
	const std::map<std::string, double> &getData() const;
	void	addToMap(const std::string &str);

	class	ConstructorException : public std::exception {};
private:
	BitcoinExchange();
	std::map<std::string, double>	_data;
};


#endif
