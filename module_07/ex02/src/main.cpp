/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:46:05 by hleung            #+#    #+#             */
/*   Updated: 2024/01/02 19:50:16 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Array.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

int main( void ) 
{
	srand(time(NULL)); //set random seed

	/* Array a */
	Array<int> a(10);

	std::cout << "Array a : ";
	std::cout << a << std::endl;
	std::cout << "Array a : ";
	for (unsigned int i = 0; i < a.size(); i++)
		a[i] = rand() % 100;
	for (unsigned int i = 0; i < a.size(); i++)
	{
		std::cout << a[i];
		if (i != a.size() - 1)
			std::cout << " ";
	}
	std::cout << std::endl;
	
	/* Array b */
	Array<int> b(a);

	std::cout << "Array b : ";
	std::cout << b << std::endl;
	std::cout << "Array b : ";
	for (unsigned int i = 0; i < b.size(); i++)
	{
		std::cout << b[i];
		if (i != b.size() - 1)
			std::cout << " ";
	}
	b[9] = rand() % 100;
	std::cout << std::endl;

	/* Array c */
	Array<int> c(15);

	std::cout << "Array c : ";
	std::cout << c << std::endl;
	std::cout << "Array c : ";
	for (unsigned int i = 0; i < c.size(); i++)
		c[i] = rand() % 100;
	for (unsigned int i = 0; i < c.size(); i++)
	{
		std::cout << c[i];
		if (i != c.size() - 1)
			std::cout << " ";
	}
	c = b;
	std::cout << std::endl;

	/* Array a after */
	std::cout << "Array a after : ";
	for (unsigned int i = 0; i < a.size(); i++)
	{
		std::cout << a[i];
		if (i != a.size() - 1)
			std::cout << " ";
	}
	std::cout << std::endl;

	/* Array b after */
	std::cout << "Array b after : ";
	for (unsigned int i = 0; i < b.size(); i++)
	{
		std::cout << b[i];
		if (i != b.size() - 1)
			std::cout << " ";
	}
	std::cout << std::endl;

	/* Array c after */
	std::cout << "Array c after : ";
	for (unsigned int i = 0; i < c.size(); i++)
	{
		std::cout << c[i];
		if (i != c.size() - 1)
			std::cout << " ";
	}
	std::cout << std::endl;

	/* Out of range tests */
	try
	{
		a[19] = 100;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	try
	{
		b[-4] = 77;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
} 
