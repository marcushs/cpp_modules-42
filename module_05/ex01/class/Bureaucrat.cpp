/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:14:24 by hleung            #+#    #+#             */
/*   Updated: 2023/12/19 10:27:22 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"

/*------------------------------- Constructors -------------------------------*/

Bureaucrat::Bureaucrat(void) : _name("Default"), _grade(150) {}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name)
{
	try
	{
		if (grade < 1)
		{
			this->_grade = 1;
			throw Bureaucrat::GradeTooHighException();
		}
		else if (grade > 150)
		{
			this->_grade = 150;
			throw Bureaucrat::GradeTooLowException();
		}
		else
			this->_grade = grade;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : _name(src._name)
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

const std::string	&Bureaucrat::getName(void) const {return this->_name;}
int Bureaucrat::getGrade(void) const {return this->_grade;}

/*----------------------------- Member Functions ------------------------------*/

void	Bureaucrat::incrementGrade(void)
{
	if (this->_grade - 1 < 1)
	{
		this->_grade = 1;
		throw Bureaucrat::GradeTooHighException();
	}
	this->_grade--;
}

void	Bureaucrat::decrementGrade(void)
{
	if (this->_grade + 1 > 150)
	{
		this->_grade = 150;
		throw Bureaucrat::GradeTooLowException();
	}
	this->_grade++;
}

std::ostream	&operator<<(std::ostream &o, const Bureaucrat &rhs)
{
	o << rhs.getName() << ", bureaucrat grade "
	<< rhs.getGrade() << std::endl;
	return o;
}
