/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 10:49:11 by hleung            #+#    #+#             */
/*   Updated: 2024/04/29 17:10:58 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2) {
		std::cout << "Usage: btc <input file>" << std::endl;
		return 1;
	}
	try {
		BitcoinExchange btc;
		btc.findExchangeValue(argv[1]);
	} catch (const std::runtime_error &e) {
		std::cout << e.what() << std::endl;
		return 1;
	}
	return 0;
}
