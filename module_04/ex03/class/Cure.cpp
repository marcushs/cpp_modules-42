/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:19:38 by hleung            #+#    #+#             */
/*   Updated: 2023/12/16 16:20:28 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cure.hpp"
#include <iostream>

/*------------------------------- Constructors -------------------------------*/

Cure::Cure(void) : AMateria("cure") {}

Cure::Cure(const Cure &src) : AMateria("cure")
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
