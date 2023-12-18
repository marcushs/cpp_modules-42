/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 08:24:30 by hleung            #+#    #+#             */
/*   Updated: 2023/12/18 09:15:07 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource(void)
{
	for (unsigned int i = 0; i < MateriaSource::_nbMateria; i++)
		this->_library[i] = NULL;
}

MateriaSource::~MateriaSource(void) {}

MateriaSource::MateriaSource(const MateriaSource &src)
{
	for (unsigned int i = 0; i < MateriaSource::_nbMateria; i++)
		this->_library[i] = src._library[i];
}

MateriaSource	&MateriaSource::operator=(const MateriaSource &rhs)
{
	for (unsigned int i = 0; i < MateriaSource::_nbMateria; i++)
		this->_library[i] = rhs._library[i];
}

void	MateriaSource::learnMateria(AMateria *m)
{
	if (!m)
	{
		std::cout << "* AMateria is not valid *" << std::endl;
		return ;
	}
	
	for (unsigned int i = 0; i < MateriaSource::_nbMateria; i++)
	{
		if (!this->_library[i])
			this->_library[i] = m;
		std::cout << "* Learned AMateria " << m->getType() << " to the library *" << std::endl;
		return ;
	}

	std::cout << "* INVENTORY IS FULL, " << m->getType()
	<< " CANNOT BE ADDED TO THE INVENTORY *" << std::endl;
}
