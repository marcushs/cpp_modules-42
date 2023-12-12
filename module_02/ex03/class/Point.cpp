/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 08:55:59 by hleung            #+#    #+#             */
/*   Updated: 2023/12/12 09:24:54 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Point.hpp"

Point::Point(void) : _x(0), _y(0) {}

Point::Point(const float x, const float y) : _x(x), _y(y) {}

Point::Point(const Point &src)
{
	*this = src;
	return ;
}

Point::~Point(void) {}

Point	&Point::operator=(const Point &rhs)
{
	this->_x = rhs.getX();
	this->_y = rhs.getY();
	return *this;
}

bool	Point::operator==(const Point &rhs)
{
	if (this->_x == rhs.getX() && this->_y == rhs.getY())
		return true;
	return false;
}

Fixed	Point::getX(void) const {return this->_x;}

Fixed	Point::getY(void) const {return this->_y;}
