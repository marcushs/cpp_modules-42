/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 07:30:11 by hleung            #+#    #+#             */
/*   Updated: 2023/12/14 09:48:19 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cat.hpp"
#include <iostream>

Cat::Cat(void)
{
	this->_type = "Cat";
	this->_brain = new Brain();
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat &src)
{
	this->_type = src.getType();
	this->_brain = new Brain(*src.getBrain());
	std::cout << "Cat copy constructor called (Cat)" << std::endl;
}

Cat::Cat(const Animal &src)
{
	this->_type = src.getType();
	this->_brain = new Brain(*src.getBrain());
	std::cout << "Cat copy constructor called (Animal)" << std::endl;
}

Cat::~Cat(void)
{
	delete this->_brain;
	std::cout << "Cat destructor called" << std::endl;
}

Animal	&Cat::operator=(const Animal &rhs)
{
	if (this != &rhs)
	{		
		delete this->_brain;
		this->_type = rhs.getType();
		this->_brain = new Brain(*rhs.getBrain());
	}
	return *this;
}

Cat	&Cat::operator=(const Cat &rhs)
{
	if (this != &rhs)
	{		
		delete this->_brain;
		this->_type = rhs._type;
		this->_brain = new Brain(*rhs._brain);
	}
	return *this;
}

void	Cat::makeSound(void) const
{
	std::cout << this->_type << " goes \"MEOW MEOW\"" << std::endl;
}

Brain	*Cat::getBrain(void) const
{
	return this->_brain;
}
