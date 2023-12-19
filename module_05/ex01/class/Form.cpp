/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 09:58:13 by hleung            #+#    #+#             */
/*   Updated: 2023/12/19 10:40:38 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Form.hpp"

/*------------------------------- Constructors -------------------------------*/

Form::Form(void) : _name("Default Form"), _isSigned(false), _gradeToSign(1), _gradeToExec(1) {}


/*-------------------------------- Destructor --------------------------------*/

Form::~Form() {}

/*--------------------------------- Overload ---------------------------------*/

/*--------------------------------- Getters ----------------------------------*/

/*----------------------------- Member Functions -----------------------------*/

std::ostream	&operator<<(std::ostream &o, const Form &rhs)
{
	o << "Form Name                :" << rhs.getName() << std::endl;
	o << "Form Is Signed           :" << rhs.getIsSigned() << std::endl;
	o << "Required Grade To Sign   :" << rhs.getGradeToSign() << std::endl;
	o << "Required Grade To Execute:" << rhs.getGradeToExec() << std::endl;
	return o;
}
