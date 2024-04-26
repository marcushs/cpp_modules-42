/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 10:49:11 by hleung            #+#    #+#             */
/*   Updated: 2024/04/26 09:27:54 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/BitcoinExchange.hpp"
#include <functional>
#include <ctime>

int	main(int argc, char **argv)
{
	if (argc != 2) {
		std::cout << "Usage: btc <input file>" << std::endl;
		return 1;
	}
	std::ifstream ifs;
	ifs.open(argv[1], std::ifstream::in);
	if (!ifs.good()) {
		std::cout << "Error: cannot open file " << argv[1] << std::endl;
		return 2;
	}
	try {
		BitcoinExchange btc;
	} catch (const BitcoinExchange::ConstructorException &e) {
		ifs.close();
		return 1;
	}
	// std::map<std::string, float>::const_iterator itlow = btc.getData().lower_bound("2022-03-21");
	// std::cout << "lower_bound value is : " << itlow->second << std::endl;
	// std::map<std::string, float>::const_iterator it;
	// for (it = btc.getData().begin(); it != btc.getData().end(); it++) {
	// 	std::cout << "Key: " << it->first << " , " << "Value: " << it->second << std::endl;
	// }

	ifs.close();


	// std::string date = "2020-02-30";
	// struct tm tm;
	// if (!strptime(date.c_str(), "%Y-%m-%d", &tm))
	// {
	// 	std::cout << "strptime error\n";
	// 	return 1;
	// }
	// std::cout << tm.tm_year + 1900 << "-" << tm.tm_mon + 1 << "-" << tm.tm_mday << std::endl;
	// std::time_t t_date = std::mktime(&tm);
	// if (t_date == -1)
	// {
	// 	std::cout << "mktime error\n";
	// }
	// std::cout << "Seconds since epoch: " << t_date << std::endl;
	return 0;
}
