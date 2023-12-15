/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 08:20:33 by hleung            #+#    #+#             */
/*   Updated: 2023/12/15 12:03:27 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Character.hpp"
#include <iostream>

/*------------------------------- Constructors -------------------------------*/

Character::Character(void)
{
	this->_name = "Default";
	for (int i = 0; i < Character::_nbItem; i++)
		this->_inventory[i] = NULL;
	this->_floor[0] = NULL;
	this->_floor = NULL;
	std::cout << "* Created Character " << this->_name << " *" << std::endl;
}

Character::Character(const std::string name) :_name(name)
{
	for (int i = 0; i < Character::_nbItem; i++)
		this->_inventory[i] = NULL;
	this->_floor[0] = NULL;
	this->_floor = NULL;
	std::cout << "* Created Character " << this->_name << " *" << std::endl;
}

Character::Character(const Character &src)
{
	*this = src;
}

/*-------------------------------- Destructor --------------------------------*/

Character::~Character(void)
{
	for (int i = 0; i < Character::_nbItem; i++)
		delete this->_inventory[i];
}

/*--------------------------------- Overload ---------------------------------*/

Character	&Character::operator=(const Character &rhs)
{
	if (this != &rhs)
	{
		for (int i = 0; i < Character::_nbItem; i++)
		{
			delete this->_inventory[i];
			this->_inventory[i] = rhs.getMateria(i)->clone();
		}
	}
	return *this;
}

/*--------------------------------- Getters ----------------------------------*/

std::string const &Character::getName(void) const
{
	return this->_name;
}

AMateria	*Character::getMateria(int i) const
{
	return this->_inventory[i];
}

/*----------------------------- Member Functions ------------------------------*/

void	Character::equip(AMateria* m)
{
	if (!m)
	{
		std::cout << "* AMateria is not valid *" << std::endl;
		return ;
	}
	
	for (int i = 0; i < this->_nbItem; i++)
	{
		if (!this->_inventory[i])
		{
			this->_inventory[i] = m;
			std::cout << "* " << this->_name << " equipped " << m->getType()
			<< " to his inventory *" << std::endl;
			return ;
		}
	}
	std::cout << "* INVENTORY IS FULL, " << m->getType()
	<< " CANNOT BE ADDED TO THE INVENTORY *" << std::endl;
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx > this->_nbItem)
	{
		std::cout << "* INDEX SHOULD BE IN RANGE < 0 - "
		<< this->_nbItem << " *" << std::endl;
		return ;
	}

	if (!this->_inventory[idx])
	{
		std::cout << "* INVENTORY SLOT HAS NOTHING TO UNEQUIP *" << std::endl;
		return ;
	}
	
	this->_floorSize++;
	AMateria	**newFloor = new AMateria *[this->_floorSize];
	
	
	
}

void	Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx > this->_nbItem)
	{
		std::cout << "* INDEX SHOULD BE IN RANGE < 0 - "
		<< this->_nbItem << " *" << std::endl;
		return ;
	}

	if (!this->_inventory[idx])
	{
		std::cout << "* NO MATERIA AT SLOT " << idx << " *" << std::endl;
		return ;
	}

	this->_inventory[idx]->use(target);
}

