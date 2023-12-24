/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 14:15:50 by hleung            #+#    #+#             */
/*   Updated: 2023/12/24 17:07:06 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PresidentialPardonForm.hpp"

/*------------------------------- Constructors -------------------------------*/

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("Default PresidentialPardonForm", 25, 5), _target("home") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) : AForm(src.getName() + ".Copy", 25, 5), _target(src._target) {}

/*-------------------------------- Destructor --------------------------------*/

PresidentialPardonForm::~PresidentialPardonForm(void) {}

/*--------------------------------- Overload ---------------------------------*/

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs)
{
	(void)rhs;
	return *this;
}

/*---------------------------------- Getter ----------------------------------*/
const std::string &PresidentialPardonForm::getTarget(void) const { return this->_target; }

/*----------------------------- Member Functions -----------------------------*/

void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	if (!this->getIsSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->getGradeToExec())
		throw AForm::ExecutorGradeTooLowException();
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

std::ostream &operator<<(std::ostream &o, const PresidentialPardonForm &rhs)
{
	o << "Form Name                : " << rhs.getName() << std::endl;
	o << "Form Is Signed           : " << (rhs.getIsSigned() ? "Signed!" : "Not signed yet!")
	  << std::endl;
	o << "Target                   : " << rhs.getTarget() << std::endl;
	o << "Required Grade To Sign   : " << rhs.getGradeToSign() << std::endl;
	o << "Required Grade To Execute: " << rhs.getGradeToExec() << std::endl;
	return o;
}
