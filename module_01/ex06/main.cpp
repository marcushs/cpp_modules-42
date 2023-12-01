/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:02:25 by hleung            #+#    #+#             */
/*   Updated: 2023/12/01 17:05:36 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		Harl	h;
		std::string	level = argv[1];

		h.complain(level);
		return (0);
	}
	std::cerr << "Usage: harlFilter [LEVEL]" << std::endl;
	return (1);
}
