/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 20:18:19 by hleung            #+#    #+#             */
/*   Updated: 2024/05/05 16:45:39 by hleung           ###   ########.fr       */
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

		std::cout << "Before: ";
		p.printContainer(1);

		clock_t	vectorStart = clock();
		p.sortVector();
		clock_t	vectorEnd = clock();
		double	vectorDuration = static_cast<double>(vectorEnd - vectorStart);

		clock_t	dequeStart = clock();
		p.sortDeque();
		clock_t	dequeEnd = clock();
		double	dequeDuration = static_cast<double>(dequeEnd - dequeStart);
		
		std::cout << "After:  ";
		p.printContainer(1);
		std::cout << "Time to process a range of " << ac - 1 << " elements with std::vector<int>: ";
		std::cout << vectorDuration << " us" << std::endl;
		std::cout << "Time to process a range of " << ac - 1 << " elements with std::deque<int>:  ";
		std::cout << dequeDuration << " us" << std::endl;
		
	} catch(const std::runtime_error &e) {
		std::cout << e.what() << std::endl;
		return 1;
	}
	
	return 0;
}
