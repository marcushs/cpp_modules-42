/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 07:10:21 by hleung            #+#    #+#             */
/*   Updated: 2023/12/14 09:52:46 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Dog.hpp"
#include <iostream>

Dog::Dog(void)
{
	this->_type = "Dog";
	this->_brain = new Brain();
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &src)
{
	this->_type = src.getType();
	this->_brain = new Brain(*src.getBrain());
	std::cout << "Dog copy constructor called (Dog)" << std::endl;
}

Dog::Dog(const Animal &src)
{
	this->_type = src.getType();
	this->_brain = new Brain(*src.getBrain());
	std::cout << "Dog copy constructor called (Animal)" << std::endl;
}

Dog::~Dog(void)
{
	delete this->_brain;
	std::cout << "Dog destructor called" << std::endl;
}

Animal	&Dog::operator=(const Animal &rhs)
{
	if (this != &rhs)
	{
		delete this->_brain;
		this->_type = rhs.getType();
		this->_brain = new Brain(*rhs.getBrain());
	}
	return *this;
}

Dog	&Dog::operator=(const Dog &rhs)
{
	if (this != &rhs)
	{		
		delete this->_brain;
		this->_type = rhs._type;
		this->_brain = new Brain(*rhs._brain);
	}
	return *this;
}

void	Dog::makeSound(void) const
{
	std::cout << this->_type << " goes \"ROOF ROOF\"" << std::endl;
}

Brain	*Dog::getBrain(void) const
{
	return this->_brain;
}
