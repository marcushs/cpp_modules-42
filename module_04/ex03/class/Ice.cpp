/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:19:30 by hleung            #+#    #+#             */
/*   Updated: 2023/12/16 16:20:45 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Ice.hpp"
#include <iostream>

/*------------------------------- Constructors -------------------------------*/

Ice::Ice(void) : AMateria("ice") {}

Ice::Ice(const Ice &src) : AMateria("ice")
{
	*this = src;
}

/*-------------------------------- Destructor --------------------------------*/

Ice::~Ice(void) {}

/*--------------------------------- Overload ---------------------------------*/

Ice	&Ice::operator=(const Ice &rhs)
{
	this->_type = rhs._type;
	return *this;
}

AMateria	&Ice::operator=(const AMateria &rhs)
{
	this->_type = rhs.getType();
	return *this;
}

/*----------------------------- Member Functions ------------------------------*/

Ice	*Ice::clone(void) const
{
	return new Ice();
}

void	Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() 
	<< " *" << std::endl;
}

