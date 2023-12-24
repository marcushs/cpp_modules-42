/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:13:54 by hleung            #+#    #+#             */
/*   Updated: 2023/12/24 20:13:54 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AForm.hpp"
#include "../include/Bureaucrat.hpp"
#include "../include/Intern.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"

int main(void)
{

	{
		try
		{
			Intern someRandomIntern;
			AForm* scf;
			Bureaucrat bob("bob", 145);
			Bureaucrat max("max", 137);

			scf = someRandomIntern.makeForm("shrubbery creation", "Bender");
			std::cout << *scf;
			scf->beSigned(bob);
			std::cout << *scf;
			max.executeForm(*scf);
			delete scf;
		}
		catch (const std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	// {
	// 	try
	// 	{
	// 		Intern someRandomIntern;
	// 		AForm* rrf;
	// 		Bureaucrat bob("bob", 72);
	// 		Bureaucrat max("max", 45);

	// 		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	// 		std::cout << *rrf;
	// 		rrf->beSigned(bob);
	// 		std::cout << *rrf;
	// 		max.executeForm(*rrf);
	// 		delete rrf;
	// 	}
	// 	catch(const std::exception& e)
	// 	{
	// 		std::cerr << e.what() << std::endl;
	// 	}
	// }
	
	// {
	// 	try
	// 	{
	// 		Intern someRandomIntern;
	// 		AForm* ppf;
	// 		Bureaucrat bob("bob", 25);
	// 		Bureaucrat max("max", 5);

	// 		ppf = someRandomIntern.makeForm("presidential pardon", "Bender");
	// 		std::cout << *ppf;
	// 		ppf->beSigned(bob);
	// 		std::cout << *ppf;
	// 		max.executeForm(*ppf);
	// 		delete ppf;
	// 	}
	// 	catch(const std::exception& e)
	// 	{
	// 		std::cerr << e.what() << std::endl;
	// 	}
	// }

	// {
	// 	try
	// 	{
	// 		Intern someRandomIntern;
	// 		AForm* rrf;
	// 		rrf = someRandomIntern.makeForm("some random form", "Bender");
	// 		delete rrf;
	// 	}
	// 	catch(const std::exception& e)
	// 	{
	// 		std::cerr << e.what() << std::endl;
	// 	}
	// }
}
