/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:17:43 by hleung            #+#    #+#             */
/*   Updated: 2024/05/02 14:02:55 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RPN.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Usage: RPN \"expression\"" << std::endl;
		return 1;
	}
	try {
		RPN	rpn;
		rpn.calculate(av[1]);
	} catch(const std::runtime_error &e) {
		std::cout << e.what() << std::endl;
		return 1;
	}
	
	return 0;
}
