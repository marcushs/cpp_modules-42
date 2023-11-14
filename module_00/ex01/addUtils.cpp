/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addUtils.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 09:46:28 by hleung            #+#    #+#             */
/*   Updated: 2023/11/14 14:13:28 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto.hpp"
#include "PhoneBook.hpp"
#include "Contact.hpp"

static int		isValidPhone(std::string str);

void	addPrompt(std::string strs[5])
{
	for (int i = 0; i < 5; i++)
	{
		do
		{
			if (i == 0)
				std::cout << ">> Enter First Name    :";
			else if (i == 1)
				std::cout << ">> Enter Last Name     :";
			else if (i == 2)
				std::cout << ">> Enter Nick Name     :";
			else if (i == 3)
				std::cout << ">> Enter Phone Number  :";
			else if (i == 4)
				std::cout << ">> Enter Darket Secret :";
			std::getline(std::cin, strs[i]);
			if (i == 3 && !isValidPhone(strs[3]))
				strs[i][0] = 0;
		} while (!strs[i][0]);
	}
}

static int	isValidPhone(std::string str)
{
	for (int i = 0; str[i]; i++)
	{
		if ((str[0] != '+' && !isdigit(str[0])) || \
		(i > 0 && !isdigit(str[i]) && str[i] != '-' && str[i] != ' ') || \
		(str[i + 1] && str[i] == '-' && !isdigit(str[i + 1])) || \
		(str[i + 1] && str[i] == ' ' && !isdigit(str[i + 1])))
		{
			std::cout << "Bad phone number format" << std::endl;
			return (0);
		}
	}
	return (1);
}
