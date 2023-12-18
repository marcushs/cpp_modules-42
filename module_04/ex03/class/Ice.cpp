/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:19:30 by hleung            #+#    #+#             */
/*   Updated: 2023/12/18 10:53:06 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Ice.hpp"
#include <iostream>

/*------------------------------- Constructors -------------------------------*/

Ice::Ice(void) : AMateria("ice") {this->isLearned = false;}

Ice::Ice(const Ice &src) : AMateria("ice")
{
	this->isLearned = false;
	*this = src;
}

/*-------------------------------- Destructor --------------------------------*/

Ice::~Ice(void) {}

/*--------------------------------- Overload ---------------------------------*/

Ice	&Ice::operator=(const Ice &rhs)
{
	this->_type = rhs._type;
	this->isLearned = rhs.isLearned;
	return *this;
}

AMateria	&Ice::operator=(const AMateria &rhs)
{
	this->_type = rhs.getType();
	this->isLearned = rhs.isLearned;
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

