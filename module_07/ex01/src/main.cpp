/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:46:05 by hleung            #+#    #+#             */
/*   Updated: 2023/12/28 22:02:22 by hleung           ###   ########.fr       */
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
	::iter<int, size_t, void>(arr1, 6, print);

	std::cout << std::endl;

	
	return 0;
}
