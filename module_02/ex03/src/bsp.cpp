/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 09:20:27 by hleung            #+#    #+#             */
/*   Updated: 2023/12/12 14:49:05 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	crossProdAP = (a - b) * (a - point);
	Fixed	crossProdBP = (b - c) * (b - point);
	Fixed	crossProdCP = (c - a) * (c - point);

	if (crossProdAP > 0 && crossProdBP > 0 && crossProdCP > 0)
		return true;
	if (crossProdAP < 0 && crossProdBP < 0 && crossProdCP < 0)
		return true;
	return false;
}


