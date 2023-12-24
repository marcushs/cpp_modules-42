/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 17:13:19 by hleung            #+#    #+#             */
/*   Updated: 2023/12/24 20:10:11 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Intern.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"

static AForm	*makePresidentialPardonFrom(const std::string &target);
static AForm	*makeRobotomyRequestForm(const std::string &target);
static AForm	*makeShrubberyCreationForm(const std::string &target);

/*------------------------------- Constructors -------------------------------*/

Intern::Intern(void) {}

Intern::Intern(const Intern &src) {(void)src;}

/*-------------------------------- Destructor --------------------------------*/

Intern::~Intern(void) {}

/*--------------------------------- Overload ---------------------------------*/

Intern	&Intern::operator=(const Intern &rhs) {(void)rhs; return *this;}

/*----------------------------- Member Functions -----------------------------*/

AForm	*Intern::makeForm(const std::string &name, const std::string &target) const
{
	AForm	*(*f[3])(const std::string &target) = {&makePresidentialPardonFrom, &makeRobotomyRequestForm, &makeShrubberyCreationForm};
	std::string	names[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	for (int i = 0; i < 3; i++)
	{
		if (!name.compare(names[i]))
		{
			std::cout << "Intern creates " << name << std::endl;
			return f[i](target);
		}
	}
	throw	Intern::NoFormException();
}

static AForm	*makePresidentialPardonFrom(const std::string &target) {return new PresidentialPardonForm(target);}

static AForm	*makeRobotomyRequestForm(const std::string &target) {return new RobotomyRequestForm(target);}

static AForm	*makeShrubberyCreationForm(const std::string &target) {return new ShrubberyCreationForm(target);}
