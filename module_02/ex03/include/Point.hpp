/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 08:51:46 by hleung            #+#    #+#             */
/*   Updated: 2023/12/12 15:01:10 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP
# include "Fixed.hpp"

class Point
{

public:
	Point(void);
	Point(const float x, const float y);
	Point(const Point &src);
	~Point(void);

	Point	&operator=(const Point &rhs);
	bool	operator==(const Point &rhs);
	Point	operator-(const Point &rhs) const;
	Fixed	operator*(const Point &rhs);
	Fixed	getX(void) const;
	Fixed	getY(void) const;

private:
	Fixed	_x;
	Fixed	_y;
	
};

std::ostream	&operator<<(std::ostream &o, const Point &rhs);

#endif
