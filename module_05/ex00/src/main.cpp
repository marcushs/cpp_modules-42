/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:13:54 by hleung            #+#    #+#             */
/*   Updated: 2023/12/24 20:22:32 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"

int	main(void)
{
	Bureaucrat	a;
	Bureaucrat	b("b", 1);
	Bureaucrat	c(b);
	try
	{
		Bureaucrat	d("d", 200); // Output: Grade too low!
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat	e("e", -2); // Output: Grade too high!
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << a; // Output: Default, bureaucrat grade 150
	std::cout << b; // Output: b, bureaucrat grade 1
	std::cout << c; // Output: b, bureaucrat grade 1
	try
	{
		a.decrementGrade(); // Output: Grade too low!
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << a; // Output: Default, bureaucrat grade 150

	try
	{
		b.incrementGrade(); // Output: Grade too high!
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << b; // Output: b, bureaucrat grade 1

	try
	{
		for (int i = 0; i < 10; i++)
			c.decrementGrade();
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << c; // Output: b, bureaucrat grade 11

	try
	{
		for (int i = 0; i < 6; i++)
			c.incrementGrade();
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << c; // Output: b, bureaucrat grade 5
	a = c;
	std::cout << a; // Output: Default, bureaucrat grade 5

}
