/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:46:05 by hleung            #+#    #+#             */
/*   Updated: 2024/01/02 15:21:17 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/iter.hpp"
#include <iostream>

int main( void ) 
{
	std::string	str = "hello world!";
	::iter<char, size_t, void>(str.c_str(), str.length(), print);

	std::cout << std::endl;

	int	arr1[6] = {3, 5, 2, 100, 45, 99};
	::iter<int, size_t, void>(arr1, sizeof(arr1) / sizeof(int), print);

	std::cout << std::endl;

	float	arr2[10] = {86.05, 104.40, 104.17, 65.83, 93.66, 28.58, 2.82, 25.95, 91.55, 70.93};
	::iter<float, size_t, void>(arr2, sizeof(arr2) / sizeof(float), print);
	
	return 0;
}
