/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 07:01:11 by hleung            #+#    #+#             */
/*   Updated: 2023/12/14 09:04:54 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Animal.hpp"
#include <iostream>

Animal::Animal(void) : _type("Generic animal")
{
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal &src)
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = src;
	return ;
}

Animal::~Animal(void)
{
	std::cout << "Animal destructor called" << std::endl;
}

Animal	&Animal::operator=(const Animal &rhs)
{
	if (this != &rhs)
		this->_type = rhs._type;
	return *this;
}

std::string	Animal::getType(void) const
{
	return this->_type;
}

void	Animal::makeSound(void) const
{
	std::cout << this->_type << " goes \"RANDOM ANIMAL SOUND\"" << std::endl;
}

Brain	*Animal::getBrain(void) const
{
	std::cout << "Generic animal has no brain!" << std::endl;
	return NULL;
}
