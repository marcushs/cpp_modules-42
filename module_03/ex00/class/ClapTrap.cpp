/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 09:43:14 by hleung            #+#    #+#             */
/*   Updated: 2023/12/11 14:37:02 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Created ClapTrap " << this->_name << std::endl;
	return ;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Created ClapTrap " << this->_name << std::endl;
	return ;
}

ClapTrap::ClapTrap(const ClapTrap &src)
{
	std::cout << "Copied ClapTrap " << src.getName() << std::endl;
	*this = src;
	return ;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap " << this->_name << " called destructor" << std::endl;
	return ;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &rhs)
{
	this->_name = rhs.getName();
	this->_hitPoints = rhs.getHitPoints();
	this->_energyPoints = rhs.getEnergyPoints();
	this->_attackDamage = rhs.getAttackDamage();
	return *this;
}

void	ClapTrap::attack(const std::string &target)
{
	if (this->isDead())
		return ;

	std::cout << "ClapTrap " << this->_name << " attacks " << target;
	std::cout << ", causing " << this->_attackDamage << " points of damage" << std::endl;

	this->_energyPoints--;
	return ;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->isDead())
		return ;

	std::cout << "ClapTrap " << this->_name << " took ";
	std::cout << amount << " points of damage" << std::endl;

	if (amount <= this->_hitPoints)
		this->_hitPoints -= amount;
	else
		this->_hitPoints = 0;
	return ;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->isDead())
		return ;

	std::cout << "ClapTrap " << this->_name << " repaired ";
	std::cout << amount << " hit points" << std::endl;

	this->_hitPoints += amount;
	this->_energyPoints--;
	return ;
}

const std::string	&ClapTrap::getName(void) const
{
	return this->_name;
}

unsigned int	ClapTrap::getHitPoints(void) const
{
	return this->_hitPoints;
}

unsigned int	ClapTrap::getEnergyPoints(void) const
{
	return this->_energyPoints;
}

unsigned int	ClapTrap::getAttackDamage(void) const
{
	return this->_attackDamage;
}

int	ClapTrap::isDead(void) const
{
	if (!this->_hitPoints)
	{
		std::cout << "ClapTrap " << this->_name << " died" << std::endl;
		return (1);
	}
	if (!this->_energyPoints)
	{
		std::cout << "ClapTrap " << this->_name << " ran out of energy" << std::endl;
		return (1);
	}
	return (0);
}

std::ostream	&operator<<(std::ostream &o, const ClapTrap &rhs)
{
	o << "Name         : " << rhs.getName() << std::endl;
	o << "Hit Points   : " << rhs.getHitPoints() << std::endl;
	o << "Energy Points: " << rhs.getEnergyPoints() << std::endl;
	o << "Attack Damage: " << rhs.getAttackDamage() << std::endl;
	return o;
}
