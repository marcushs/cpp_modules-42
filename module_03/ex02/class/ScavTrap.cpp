/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:29:30 by hleung            #+#    #+#             */
/*   Updated: 2023/12/11 20:42:38 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "Created ScavTrap Default" << std::endl;
	return;
}

ScavTrap::ScavTrap(const std::string name)
{
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "Created ScavTrap " << name << std::endl;
	return;
}

ScavTrap::ScavTrap(const ScavTrap &src) : ClapTrap(src)
{
	*this = src;
	std::cout << "Copied ScavTrap " << this->_name << std::endl;
	return;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap " << this->_name << " called destructor" << std::endl;
	return;
}

void ScavTrap::attack(const std::string &target)
{
	if (this->isDead())
		return;

	std::cout << "ScavTrap " << this->_name << " attacks " << target;
	std::cout << ", causing " << this->_attackDamage << " points of damage" << std::endl;

	this->_energyPoints--;
	return;
}

void ScavTrap::guardGate(void)
{
	if (this->isDead())
		return;

	std::cout << "ScavTrap " << this->_name << " is now in Gatekeeper mode." << std::endl;
	return;
}
