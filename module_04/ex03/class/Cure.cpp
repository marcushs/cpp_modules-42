/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:19:38 by hleung            #+#    #+#             */
/*   Updated: 2023/12/14 12:57:34 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cure.hpp"
#include <iostream>

/*------------------------------- Constructors -------------------------------*/

Cure::Cure(void) : AMateria("cure") {}

Cure::Cure(const Cure &src)
{
	*this = src;
}

/*-------------------------------- Destructor --------------------------------*/

Cure::~Cure(void) {}

/*--------------------------------- Overload ---------------------------------*/

Cure	&Cure::operator=(const Cure &rhs)
{
	this->_type = rhs._type;
	return *this;
}

AMateria	&Cure::operator=(const AMateria &rhs)
{
	this->_type = rhs.getType();
	return *this;
}

/*----------------------------- Member Functions ------------------------------*/

Cure	*Cure::clone(void) const
{
	return new Cure();
}

void	Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() 
	<< "'s wounds *" << std::endl;
}
