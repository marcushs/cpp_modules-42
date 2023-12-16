/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 08:20:33 by hleung            #+#    #+#             */
/*   Updated: 2023/12/16 16:46:08 by hleung           ###   ########.fr       */
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
	this->_floor = NULL;
	this->_floorSize = 0;
	std::cout << "* Created Character " << this->_name << " *" << std::endl;
}

Character::Character(const std::string name) :_name(name)
{
	for (int i = 0; i < Character::_nbItem; i++)
		this->_inventory[i] = NULL;
	this->_floor = NULL;
	this->_floorSize = 0;
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
		if (this->_inventory[i])
			delete this->_inventory[i];
	
	for (unsigned int i = 0; i < this->_floorSize; i++)
		delete this->_floor[i];

	std::cout << "* Destroyed Character " << this->_name << " *" << std::endl;
}

/*--------------------------------- Overload ---------------------------------*/

Character	&Character::operator=(const Character &rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_floor = NULL;
		this->_floor[0] = NULL;
		this->_floorSize = 0;
		for (int i = 0; rhs._inventory[i]; i++)
		{
			if (this->_inventory[i])
				delete this->_inventory[i];
			this->_inventory[i] = rhs._inventory[i]->clone();
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
			this->_inventory[i] = m->clone();
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
	if (idx < 0 || idx >= this->_nbItem)
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

	for(int i = 0; this->_floor[i]; i++)
		newFloor[i] = this->_floor[i];
	
	newFloor[this->_floorSize - 1] = this->_inventory[idx];
	std::cout << "* " << this->_name << " dropped "
	<< this->_inventory[idx]->getType() << " from his inventory *" << std::endl;
	this->_inventory[idx] = NULL;
}

void	Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx >= this->_nbItem)
	{
		std::cout << this->_name << ": "<< "* INDEX SHOULD BE IN RANGE < 0 - "
		<< this->_nbItem << " *" << std::endl;
		return ;
	}

	if (!this->_inventory[idx])
	{
		std::cout << this->_name << ": " << "* NO MATERIA AT SLOT "
		<< idx << " *" << std::endl;
		return ;
	}

	std::cout << this->_name << ": ";
	this->_inventory[idx]->use(target);
}

