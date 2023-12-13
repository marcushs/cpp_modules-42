/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 20:50:25 by hleung            #+#    #+#             */
/*   Updated: 2023/12/13 14:37:52 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : _name("Default")
{
	this->_hitPoints = FragTrap::getStartHitPoints();
	this->_energyPoints = ScavTrap::getStartEnergyPoints();
	this->_attackDamage = FragTrap::getStartAttackDamage();
	std::cout << "Created DiamondTrap " << this->_name << std::endl;
}

DiamondTrap::DiamondTrap(const std::string name) : ClapTrap(name + "_clap_name"), _name(name)
{
	this->_hitPoints = FragTrap::getStartHitPoints();
	this->_energyPoints = ScavTrap::getStartEnergyPoints();
	this->_attackDamage = FragTrap::getStartAttackDamage();
	std::cout << "Created DiamondTrap " << this->_name << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &src)
{
	*this = src;
	std::cout << "Copied DiamondTrap " << this->_name << std::endl;
	return ;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap " << this->_name << " called destructor" << std::endl;
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "DiamondTrap's name: " << this->_name << std::endl;
	std::cout << "ClapTrap's name   : " << ClapTrap::getName() << std::endl;
}

std::string	DiamondTrap::getName(void) const
{
	return this->_name;
}

std::ostream	&operator<<(std::ostream &o, const DiamondTrap &rhs)
{
	o << "Name         : " << rhs.getName() << std::endl;
	o << "Hit Points   : " << rhs.getHitPoints() << std::endl;
	o << "Energy Points: " << rhs.getEnergyPoints() << std::endl;
	o << "Attack Damage: " << rhs.getAttackDamage() << std::endl;
	return o;
}
