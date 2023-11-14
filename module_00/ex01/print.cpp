/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 09:29:10 by hleung            #+#    #+#             */
/*   Updated: 2023/11/14 08:09:26 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto.hpp"

void	greet(void)
{
	printChars(1, "\n");
	printChars(47, "*");
	printChars(1, "\n");
	printChars(1, "*");
	printChars(6, " ");
	std::cout << "Welcome to My Awesome Phonebook!";
	printChars(7, " ");
	printChars(1, "*\n");
	printChars(1, "*");
	printChars(1, " ");
	std::cout << "Please enter a command (ADD, SEARCH, EXIT)!";
	printChars(1, " ");
	printChars(1, "*\n");
	printChars(47, "*");
	printChars(2, "\n");
}

void	printChars(int s, std::string c)
{
	for (int i = 0; i < s; i++)
		std::cout << c;
}

