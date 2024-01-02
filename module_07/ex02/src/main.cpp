/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:46:05 by hleung            #+#    #+#             */
/*   Updated: 2024/01/02 19:20:49 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../template/Array.tpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

int main( void ) 
{
	srand(time(NULL));
	Array<int> a(10);

	std::cout << "Array a : ";
	std::cout << a << std::endl;
	for (unsigned int i = 0; i < a.size(); i++)
		a[i] = rand() % 100;
	std::cout << "Array a : ";
	for (unsigned int i = 0; i < a.size(); i++)
	{
		std::cout << a[i];
		if (i != a.size() - 1)
			std::cout << " ";
	}

	std::cout << std::endl;
	
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

	std::cout << "Array a after : ";
	for (unsigned int i = 0; i < a.size(); i++)
	{
		std::cout << a[i];
		if (i != a.size() - 1)
			std::cout << " ";
	}

	std::cout << std::endl;

	std::cout << "Array b after : ";
	for (unsigned int i = 0; i < b.size(); i++)
	{
		std::cout << b[i];
		if (i != b.size() - 1)
			std::cout << " ";
	}


	std::cout << std::endl;

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
