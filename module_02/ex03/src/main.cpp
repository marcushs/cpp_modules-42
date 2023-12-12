/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 13:50:00 by hleung            #+#    #+#             */
/*   Updated: 2023/12/12 15:12:27 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Point.hpp"
#include "../include/bsp.hpp"

int	main(void)
{
	Point a(0.0f, 0.0f);
	Point b(4.0f, 0.0f);
	Point c(2.0f, 4.0f);
	Point point(2.0f, 2.0f);

	if (bsp(a, b, c, point))
		std::cout << "point is inside triangle <a b c>" << std::endl;
	else
		std::cout << "point is not inside triangle <a b c>" << std::endl;

	Point d(0.0f, 0.0f);
	Point e(4.0f, 0.0f);
	Point f(2.0f, 4.0f);
	Point point2(5.0f, 5.0f);

	if (bsp(d, e, f, point2))
		std::cout << "point2 is inside triangle <d e f>" << std::endl;
	else
		std::cout << "point2 is not inside triangle <d e f>" << std::endl;
	
}
