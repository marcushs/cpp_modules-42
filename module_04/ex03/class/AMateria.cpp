/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:08:25 by hleung            #+#    #+#             */
/*   Updated: 2023/12/15 09:37:40 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AMateria.hpp"

/*------------------------------- Constructors -------------------------------*/

AMateria::AMateria(void) {}

AMateria::AMateria(const std::string &type) : _type(type) {}

AMateria::AMateria(const AMateria &src)
{
	*this = src;
}

/*-------------------------------- Destructor --------------------------------*/

AMateria::~AMateria(void) {}

/*--------------------------------- Overload ---------------------------------*/

AMateria	&AMateria::operator=(const AMateria &rhs)
{
	this->_type = rhs._type;
	return *this;
}

/*--------------------------------- Getters ----------------------------------*/

std::string const	&AMateria::getType(void) const 
{
	return this->_type;
}

/*----------------------------- Member Functions ------------------------------*/

void	AMateria::use(ICharacter &target) {(void)target;}
