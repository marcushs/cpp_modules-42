/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 13:21:16 by hleung            #+#    #+#             */
/*   Updated: 2023/12/22 14:09:26 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

/*------------------------------- Constructors -------------------------------*/

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("Default RobotomyRequestForm", 72, 45), _target("home"){}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : AForm(src.getName() + ".Copy", 72, 45), _target(src._target) {}

/*-------------------------------- Destructor --------------------------------*/

RobotomyRequestForm::~RobotomyRequestForm(void) {}

/*--------------------------------- Overload ---------------------------------*/

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs) {(void)rhs; return *this;}

/*---------------------------------- Getter ----------------------------------*/
const std::string	&RobotomyRequestForm::getTarget(void) const {return this->_target;}

/*----------------------------- Member Functions -----------------------------*/

void	RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	try
	{
		if (!this->getIsSigned())
			throw AForm::FormNotSignedException();
		if (executor.getGrade() > this->getGradeToExec())
			throw AForm::ExecutorGradeTooLowException();
		std::cout << "Bzzzzz... Whirrrr... Clank! Clank! Bzzzzz..." << std::endl;
		
		srand((unsigned int)time(NULL));
		if (rand() % 2 == 0)
			std::cout << this->_target << " has succesfully been robotomized" << std::endl;
		else
			std::cout << this->_target << "'s robotomization failed" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

std::ostream	&operator<<(std::ostream &o, const RobotomyRequestForm &rhs)
{
	o << "Form Name                : " << rhs.getName() << std::endl;
	o << "Form Is Signed           : " <<(rhs.getIsSigned() ? "Signed!" : "Not signed yet!") 
	<< std::endl;
	o << "Target                   : " << rhs.getTarget() << std::endl;
	o << "Required Grade To Sign   : " << rhs.getGradeToSign() << std::endl;
	o << "Required Grade To Execute: " << rhs.getGradeToExec() << std::endl;
	return o;
}
