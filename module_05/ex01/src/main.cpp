/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:13:54 by hleung            #+#    #+#             */
/*   Updated: 2023/12/19 09:51:22 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"

int	main(void)
{
	Bureaucrat	a;
	Bureaucrat	b("b", 100);
	Bureaucrat	c(b);
	Bureaucrat	d("d", 200); // Output: Grade too low! Grade reset to 150
	Bureaucrat	e("e", -2); // Output: Grade too high! Grade reset to 0

	std::cout << a; // Output: Default, bureaucrat grade 150
	std::cout << b; // Output: b, bureaucrat grade 100
	std::cout << c; // Output: b, bureaucrat grade 100
	std::cout << d; // Output: d, bureaucrat grade 150
	std::cout << e; // Output: e, bureaucrat grade 0

	try
	{
		a.decrementGrade();
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		e.incrementGrade();
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		for (int i = 0; i < 10; i++)
			e.decrementGrade();
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << e;
	a = e;
	std::cout << a;

}
