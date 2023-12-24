/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:13:54 by hleung            #+#    #+#             */
/*   Updated: 2023/12/24 17:11:46 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"

int main(void)
{
	// {
	// 	ShrubberyCreationForm a("home");
	// 	ShrubberyCreationForm b(a);
	// 	Bureaucrat bob("bob", 145);
	// 	Bureaucrat max("max", 137);

	// 	std::cout << a;
	// 	std::cout << std::endl;
	// 	std::cout << b;
	// 	std::cout << std::endl;
	// 	a.beSigned(bob);
	// 	std::cout << a;
	// 	max.executeForm(a);
	// }

	// {
	// 	RobotomyRequestForm a("target");
	// 	RobotomyRequestForm b(a);
	// 	Bureaucrat bob("bob", 72);
	// 	Bureaucrat max("max", 45);

	// 	std::cout << a;
	// 	std::cout << std::endl;
	// 	std::cout << b;
	// 	std::cout << std::endl;
	// 	a.beSigned(bob);
	// 	std::cout << a;
	// 	max.executeForm(a);
	// }

	{
		PresidentialPardonForm a("target");
		PresidentialPardonForm b(a);
		Bureaucrat bob("bob", 25);
		Bureaucrat max("max", 5);

		std::cout << a;
		std::cout << std::endl;
		std::cout << b;
		std::cout << std::endl;
		a.beSigned(bob);
		std::cout << a;
		max.executeForm(a);
	}
}
