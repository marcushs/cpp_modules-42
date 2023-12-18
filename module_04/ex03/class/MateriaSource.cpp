/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 08:24:30 by hleung            #+#    #+#             */
/*   Updated: 2023/12/18 12:47:07 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource(void)
{
	for (unsigned int i = 0; i < MateriaSource::_nbMateria; i++)
		this->_library[i] = NULL;
}

MateriaSource::~MateriaSource(void)
{
	for (unsigned int i = 0; i < MateriaSource::_nbMateria; i++)
		if (this->_library[i])
			delete this->_library[i];
}

MateriaSource::MateriaSource(const MateriaSource &src)
{
	for (unsigned int i = 0; i < MateriaSource::_nbMateria; i++)
		this->_library[i] = NULL;
	*this = src;
}

MateriaSource	&MateriaSource::operator=(const MateriaSource &rhs)
{
	if (this != &rhs)
	{
		for (unsigned int i = 0; i < MateriaSource::_nbMateria; i++)
		{
			if (this->_library[i])
				delete this->_library[i];
			if (rhs._library[i])
				this->_library[i] = rhs._library[i]->clone();
			else
				this->_library[i] = NULL;
		}
	}
	return *this;
}

void	MateriaSource::learnMateria(AMateria *m)
{
	if (!m)
	{
		std::cout << "* AMateria is not valid *" << std::endl;
		return ;
	}
	
	if (m->isLearned)
	{
		std::cout << "* THIS MATERIA IS ALREADY IN THE LIBRARY! *" << std::endl;
		return ;
	}
	
	for (unsigned int i = 0; i < MateriaSource::_nbMateria; i++)
	{
		if (!this->_library[i])
		{
			this->_library[i] = m;
			m->isLearned = true;	
			std::cout << "* Learned AMateria " << m->getType() << " to the library *" << std::endl;
			return ;
		}
	}
	std::cout << "* LIBRARY IS FULL, " << m->getType()
	<< " CANNOT BE ADDED TO THE LIBRARY *" << std::endl;
	delete m;

}

AMateria	*MateriaSource::createMateria(const std::string &type)
{
	for (unsigned int i = 0; i < MateriaSource::_nbMateria; i++)
	{
		if (!this->_library[i]->getType().compare(type))
		{
			std::cout << "* Created AMateria " << type << " from library *" << std::endl;
			return this->_library[i];
		}
	}
	std::cout << "* NO MATCHING AMATERIA IN LIBRARY *" << std::endl;
	return NULL;
}
