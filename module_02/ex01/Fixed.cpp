/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 13:06:40 by hleung            #+#    #+#             */
/*   Updated: 2023/12/06 18:20:06 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(void) : _rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed(const Fixed &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return ;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->_rawBits = value << Fixed::_nbFractionalBits;
	return ;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	this->_rawBits = roundf(value * (1 << Fixed::_nbFractionalBits));
	return ;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed	&Fixed::operator=(const Fixed &rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_rawBits = rhs.get_rawBits();
	return *this;
}

int	Fixed::get_rawBits(void) const
{
	return this->_rawBits;
}

void	Fixed::set_rawBits(int const raw)
{
	this->_rawBits = raw;
	return ;
}

float	Fixed::toFloat(void) const
{
	return ((float)this->_rawBits / (1 << Fixed::_nbFractionalBits));
}

int	Fixed::toInt(void) const
{
	return (this->_rawBits >> Fixed::_nbFractionalBits);
}

std::ostream	&operator<<(std::ostream &o, const Fixed &rhs)
{
	o << rhs.toFloat();
	return (o);
}

const int	Fixed::_nbFractionalBits = 8;
