/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:13:54 by hleung            #+#    #+#             */
/*   Updated: 2023/12/22 09:14:02 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/Form.hpp"

int	main(void)
{
	{
		try
		{
			Form a("a", 0, 100);
			std::cout << a; // No output
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}

		// Output: Grade too high!
	}

	std::cout << std::endl;
	
	{
		try
		{
			Form b("b", 100, 151);
			std::cout << b; // No output
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		
		// Output: Grade too low!
	}

	std::cout << std::endl;
	
	{
		try
		{
			Form a("a", 100, 100);
			std::cout << a;
			
			/*
			Output:
			Form Name                : a
			Form Is Signed           : Not signed yet!
			Required Grade To Sign   : 100
			Required Grade To Execute: 100
			*/
		
			std::cout << std::endl;
			
			Form b(a);
			std::cout << b;

			/*
			Output:
			Form Name                : a.Copy
			Form Is Signed           : Not signed yet!
			Required Grade To Sign   : 100
			Required Grade To Execute: 100
			*/

			std::cout << std::endl;

			Form c;
			std::cout << c;

			
			/*
			Output:
			Form Name                : Default Form
			Form Is Signed           : Not signed yet!
			Required Grade To Sign   : 1
			Required Grade To Execute: 1
			*/
		
			std::cout << std::endl;
			
			c = a;
			std::cout << c;

			/*
			Output:
			Form Name                : Default Form
			Form Is Signed           : Not signed yet!
			Required Grade To Sign   : 1
			Required Grade To Execute: 1
			*/
			
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	std::cout << std::endl;

	{
		try
		{
			Form d("d", 50, 1);
			Bureaucrat bob("bob", 51);

			bob.signForm(d); // Output: bob couldn't sign d because Grade too low!
			d.beSigned(bob); // Ouput: Grade too low!

			std::cout << d;

			/*
			Output:
			Form Name                : d
			Form Is Signed           : Not signed yet!
			Required Grade To Sign   : 50
			Required Grade To Execute: 1
			*/
			
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	std::cout << std::endl;

	{
		try
		{
			Form f("f", 50, 1);
			Bureaucrat max("max", 49);

			max.signForm(f); // Output: max signed f
			f.beSigned(max);

			std::cout << f;

			/*
			Output:
			Form Name                : f
			Form Is Signed           : Signed!
			Required Grade To Sign   : 50
			Required Grade To Execute: 1
			*/
			
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
}
