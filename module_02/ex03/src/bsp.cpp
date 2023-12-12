/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 09:20:27 by hleung            #+#    #+#             */
/*   Updated: 2023/12/12 09:36:05 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Point.hpp"

static bool	checkPointOnEdge(Point const a, Point const b, Point const c, Point point);

bool	bsp(Point const a, Point const b, Point const c, Point point)
{
	if (checkPointOnEdge(a, b, c, point))
		return false;
}

static bool	isTriangle(Point const a, Point const b, Point const c)
{
	Fixed	area;

	area = a.getX()
}

static bool	checkPointOnEdge(Point const a, Point const b, Point const c, Point point)
{
	if (point == a || point == b || point == c)
		return true;
	return false;
}
