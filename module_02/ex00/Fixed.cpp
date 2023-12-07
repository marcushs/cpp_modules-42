/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 13:06:40 by hleung            #+#    #+#             */
/*   Updated: 2023/12/06 18:13:15 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

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
	std::cout << "get_rawBits member function called" << std::endl;
	return this->_rawBits;
}

void	Fixed::set_rawBits(int const raw)
{
	this->_rawBits = raw;
	return ;
}

const int	Fixed::_nbFractionalBits = 8;