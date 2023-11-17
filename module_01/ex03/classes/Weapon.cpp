/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:35:42 by hleung            #+#    #+#             */
/*   Updated: 2023/11/17 12:28:41 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <iostream>

Weapon::Weapon(std::string const type) : _type(type)
{
	return ;
}

Weapon::~Weapon(void)
{
	return ;
}

std::string	const &Weapon::getType(void) const
{
	return this->_type;
}

void	Weapon::setType(std::string const type)
{
	this->_type = type;
	return ;
}
