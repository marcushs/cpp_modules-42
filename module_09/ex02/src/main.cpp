/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 20:18:19 by hleung            #+#    #+#             */
/*   Updated: 2024/05/05 11:50:26 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PmergeMe.hpp"

int	main(int ac, char **av)
{
	if (ac < 2) {
		std::cout << "Usage: PmergeMe \"list of positive integers\"" << std::endl;
		return 1;
	}
	try {
		PmergeMe p(av);
		p.sortVector();
		p.sortDeque();
	} catch(const std::runtime_error &e) {
		std::cout << e.what() << std::endl;
		return 1;
	}
	
	return 0;
}
