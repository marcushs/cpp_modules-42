/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 20:48:48 by hleung            #+#    #+#             */
/*   Updated: 2024/01/03 14:35:18 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/easyfind.hpp"
#include <vector>
#include <list>

int	main(void)
{
    std::vector<int> vect1;
	std::vector<int>::const_iterator vect1_i;
	vect1.push_back(34);
	vect1.push_back(23);
	vect1.push_back(13);
	vect1.push_back(49);

    std::list<int> list1;
	std::list<int>::const_iterator list1_i;
	list1.push_back(10);
	list1.push_back(20);
	list1.push_back(30);
	list1.push_back(40);

	try
	{
		vect1_i = easyfind(vect1, 13);  // Should find the value in the vector
	}
	catch(const std::exception& e)
	{
		std::cout << "Value not found" << std::endl;
	}

	try
	{
		list1_i = easyfind(list1, 13);  // Should not find the value in the list
	}
	catch(const std::exception& e)
	{
		std::cout << "Value not found" << std::endl;
	}

    return 0;
}
