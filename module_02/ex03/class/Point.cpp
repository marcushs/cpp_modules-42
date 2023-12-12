/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 08:55:59 by hleung            #+#    #+#             */
/*   Updated: 2023/12/12 15:02:52 by hleung           ###   ########.fr       */
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

Point	Point::operator-(const Point &rhs) const
{
	return Point(this->_x.toFloat() - rhs.getX().toFloat(), this->_y.toFloat() - rhs.getY().toFloat());
}

Fixed	Point::operator*(const Point &rhs)
{
	return (this->_x * rhs.getY() - this->_y * rhs.getX());
}

Fixed	Point::getX(void) const {return this->_x;}

Fixed	Point::getY(void) const {return this->_y;}

std::ostream	&operator<<(std::ostream &o, const Point &rhs)
{
	o << "x = " << rhs.getX() << " y = " << rhs.getY();
	return o;
}

