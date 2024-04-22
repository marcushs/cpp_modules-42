/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 10:49:11 by hleung            #+#    #+#             */
/*   Updated: 2024/01/09 16:49:45 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/BitcoinExchange.hpp"
#include <functional>

int	main(int argc, char **argv)
{
	// if (argc != 2)
	// {
	// 	std::cout << "Usage: btc <input file>" << std::endl;
	// 	return 1;
	// }
	// std::ifstream ifs;
	// ifs.open(argv[1], std::ifstream::in);
	// if (!ifs.good())
	// {
	// 	std::cout << "Error: cannot open file " << argv[1] << std::endl;
	// 	return 2;
	// }
	BitcoinExchange btc;
	std::map<std::string, float>::const_iterator itlow = btc.getData().lower_bound("2022-03-21");
	std::cout << "lower_bound value is : " << itlow->second << std::endl;
	std::map<std::string, float>::const_iterator it;
	for (it = btc.getData().begin(); it != btc.getData().end(); it++) {
		std::cout << "Key: " << it->first << " , " << "Value: " << it->second << std::endl;
	}
	// if (btc.getData()["2001-42-42"] == btc.getData()::end);
	// 	std::cout << "map::end" << std::endl;

	// ifs.close();
	return 0;
}
