/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 09:58:13 by hleung            #+#    #+#             */
/*   Updated: 2023/12/21 18:01:35 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Form.hpp"
#include <iostream>

/*------------------------------- Constructors -------------------------------*/

Form::Form(void) : _name("Default Form"), _isSigned(false), _gradeToSign(1), _gradeToExec(1) {}

Form::Form(const std::string name, const int gradeToSign, const int gradeToExec) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	if (gradeToSign < 1 || gradeToExec < 1)
		throw Form::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExec > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &src) : _name(src._name + ".Copy"), _isSigned(false), _gradeToSign(src._gradeToSign), _gradeToExec(src._gradeToExec) {}

/*-------------------------------- Destructor --------------------------------*/

Form::~Form() {}

/*--------------------------------- Overload ---------------------------------*/

Form	&Form::operator=(const Form &rhs) {(void)rhs; return *this;}

/*--------------------------------- Getters ----------------------------------*/
const std::string	&Form::getName(void) const {return this->_name;}

bool	Form::getIsSigned(void) const {return this->_isSigned;}

int	Form::getGradeToSign(void) const {return this->_gradeToSign;}

int	Form::getGradeToExec(void) const {return this->_gradeToExec;}

/*----------------------------- Member Functions -----------------------------*/

void	Form::beSigned(const Bureaucrat &bureaucrat)
{
	try
	{
		if (bureaucrat.getGrade() > this->_gradeToSign)
			throw Form::GradeTooLowException();
		this->_isSigned = true;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

std::ostream	&operator<<(std::ostream &o, const Form &rhs)
{
	o << "Form Name                : " << rhs.getName() << std::endl;
	o << "Form Is Signed           : " <<(rhs.getIsSigned() ? "Signed!" : "Not signed yet!") 
	<< std::endl;
	o << "Required Grade To Sign   : " << rhs.getGradeToSign() << std::endl;
	o << "Required Grade To Execute: " << rhs.getGradeToExec() << std::endl;
	return o;
}
