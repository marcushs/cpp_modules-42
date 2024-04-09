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

int	main(int argc, char **argv)
{
	(void) argv;
	if (argc != 2)
	{
		std::cout << "Usage: btc <input file>" << std::endl;
		return 1;
	}
	// std::ifstream ifs;
	// ifs.open(argv[1], std::ifstream::in);
	// if (!ifs.good())
	// {
	// 	std::cout << "Error: cannot open file " << argv[1] << std::endl;
	// 	return 2;
	// }
	BitcoinExchange btc;
	// if (btc.getData()["2001-42-42"] == btc.getData()::end);
	// 	std::cout << "map::end" << std::endl;
	// std::cout << ) << std::endl;

	// ifs.close();
	return 0;
}
