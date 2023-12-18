/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:14:24 by hleung            #+#    #+#             */
/*   Updated: 2023/12/18 17:14:11 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"

/*------------------------------- Constructors -------------------------------*/

Bureaucrat::Bureaucrat(void) : _name("Default"), _grade(150) {}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name)
{
	try
	{
		if (grade < 0)
			throw Bureaucrat::GradeTooHighException();
		else if (grade > 150)
			throw Bureaucrat::GradeTooLowException();
		else
			this->_grade = grade;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat &src)
{
	*this = src;
}

/*-------------------------------- Destructor --------------------------------*/

Bureaucrat::~Bureaucrat(void) {}

/*--------------------------------- Overload ---------------------------------*/

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &rhs)
{
	this->_grade = rhs._grade;
	return *this;
}

/*--------------------------------- Getters ----------------------------------*/

std::string	Bureaucrat::getName(void) const {return this->_name;}
int Bureaucrat::getGrade(void) const {return this->_grade;}

/*----------------------------- Member Functions ------------------------------*/

void	Bureaucrat::incrementGrade(void)
{
	if (this->_grade - 1 < 0)
		throw Bureaucrat::GradeTooHigh();
	this->_grade--;
}

void	Bureaucrat::decrementGrade(void)
{
	if (this->_grade + 1 > 150)
		throw Bureaucrat::GradeTooLow();
	this->_grade++;
}

