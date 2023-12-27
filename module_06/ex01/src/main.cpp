/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 21:14:36 by hleung            #+#    #+#             */
/*   Updated: 2023/12/27 21:43:45 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Data.hpp"
#include "../include/Serializer.hpp"
#include <iostream>

int	main(int argc, char **argv)
{
	static_cast<void>(argv);
	if (argc != 1)
	{
		std::cout << "Usage: serializer" << std::endl;
		return (1);
	}
	Data	*ptr = new Data;
	ptr->content = "Hello world!";
	
	std::cout << ptr->content << std::endl;
	std::cout << ptr << std::endl;

	unsigned long	serialNumber = Serializer::serialize(ptr);
	std::cout << serialNumber << std::endl;

	Data	*ptr2 = Serializer::deserialize(serialNumber);
	std::cout << ptr2 << std::endl;
	std::cout << ptr2->content << std::endl;

	delete ptr;
	
}
