/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 09:29:10 by hleung            #+#    #+#             */
/*   Updated: 2023/11/14 14:33:50 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto.hpp"

void	greet(void)
{
	std::cout << std::endl;
	printChars(47, "*");
	std::cout << std::endl;
	printChars(1, "*");
	printChars(6, " ");
	std::cout << "Welcome to My Awesome Phonebook!";
	printChars(7, " ");
	printChars(1, "*");
	std::cout << std::endl;
	printChars(1, "*");
	printChars(1, " ");
	std::cout << "Please enter a command (ADD, SEARCH, EXIT)!";
	printChars(1, " ");
	printChars(1, "*");
	std::cout << std::endl;
	printChars(47, "*");
	std::cout << std::endl;
	std::cout << std::endl;
}

void	printChars(int s, std::string c)
{
	for (int i = 0; i < s; i++)
		std::cout << c;
}

void	printPhoneBookHeader(void)
{
	std::cout << std::endl;
	printChars(45, "*");
	std::cout << std::endl;
	std::cout << "*";
	printChars(2, " ");
	std::cout << "INDEX";
	printChars(3, " ");
	std::cout << "|";
	printChars(2, " ");
	std::cout << "F.NAME";
	printChars(2, " ");
	std::cout << "|";
	printChars(2, " ");
	std::cout << "L.NAME";
	printChars(2, " ");
	std::cout << "|";
	printChars(2, " ");
	std::cout << "N.NAME";
	printChars(2, " ");
	std::cout << "*";
	std::cout << std::endl;
	std::cout << "*";
	printChars(43, "-");
	std::cout << "*";
	std::cout << std::endl;
}

void	printPhoneBookShort(std::string str)
{
	int	len = str.length();

	if (len > 10)
	{
		for (int i = 0; i < 9; i++)
			std::cout << str[i];
		std::cout << ".";
	}
	else
	{
		printChars(10 - len, " ");
		std::cout << str;
	}
}
