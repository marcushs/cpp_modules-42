/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:17:36 by hleung            #+#    #+#             */
/*   Updated: 2023/12/11 16:30:05 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/FragTrap.hpp"

FragTrap::FragTrap(void)
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "Created FragTrap Default" << std::endl;
	return ;
}

FragTrap::FragTrap(const std::string name)
{
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "Created FragTrap " << name << std::endl;
	return ;
}

FragTrap::FragTrap(const FragTrap &src)
{
	*this = src;
	std::cout << "Copied FragTrap " << this->_name << std::endl;
	return ;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap " << this->_name << " called destructor" << std::endl;
	return ;
}

void	FragTrap::highFiveGuys(void)
{
	std::cout << "Let's high five guys!" << std::endl;
	return ;
}
