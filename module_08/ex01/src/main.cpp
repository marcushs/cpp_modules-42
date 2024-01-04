/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 20:48:48 by hleung            #+#    #+#             */
/*   Updated: 2024/01/04 17:00:19 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Span.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int	main(void)
{
	// {
	// 	srand(time(NULL));
	// 	Span a(10);

	// 	for (int i = 0; i < 11; i++)
	// 	{
	// 		try
	// 		{
	// 			a.addNumber(rand() % 100);
	// 		}
	// 		catch(const std::exception& e)
	// 		{
	// 			std::cerr << e.what() << std::endl;
	// 		}
	// 	}

	// 	Span b(a);
	// 	a.getNumbers()[0] = 100;
	// 	std::cout << "Span a : ";
	// 	for (unsigned int i = 0; i < a.getCount(); i++)
	// 	{
	// 		std::cout << a.getNumbers()[i];
	// 		if (i != a.getCount() - 1)
	// 			std::cout << ' ';
	// 	}

	// 	std::cout << std::endl;

	// 	std::cout << "Span b : ";
	// 	for (unsigned int i = 0; i < b.getCount(); i++)
	// 	{
	// 		std::cout << b.getNumbers()[i];
	// 		if (i != b.getCount() - 1)
	// 			std::cout << ' ';
	// 	}

	// 	std::cout << std::endl;
		
	// 	std::cout << "Span a's longest span is : " << a.longestSpan() << std::endl;
	// 	std::cout << "Span b's shortest span is : " << a.shortestSpan() << std::endl;

	// 	Span	c(10);
	// 	std::vector<int>::iterator i = b.getNumbers().begin() + 2;
	// 	c.addNumber(i, i + 3);
	// 	std::cout << "Span c : ";
	// 	for (unsigned int i = 0; i < c.getNumbers().size(); i++)
	// 	{
	// 		std::cout << c.getNumbers()[i];
	// 		if (i != c.getCount() - 1)
	// 			std::cout << ' ';
	// 	}

	// 	std::cout << std::endl;
	// }

	// {
	// 	Span sp = Span(5);
	// 	sp.addNumber(6);
	// 	sp.addNumber(3);
	// 	sp.addNumber(17);
	// 	sp.addNumber(9);
	// 	sp.addNumber(11);
	// 	std::cout << sp.shortestSpan() << std::endl;
	// 	std::cout << sp.longestSpan() << std::endl;
	// 	return 0;
	// }

	{
		Span a(10000);
		srand(time(NULL));
		try
		{
			for (int i = 0; i < 10000; i++)
				a.addNumber(rand());
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << "Span a : " << std::endl;
		for (unsigned int i = 0; i < a.getNumbers().size(); i++)
		{
			std::cout << a.getNumbers()[i];
			if (a.getNumbers().size() - 1)
				std::cout << ' ';
		}
		std::cout << std::endl;
		std::cout << a.longestSpan() << std::endl;
		std::cout << a.shortestSpan() << std::endl;
	}
}
