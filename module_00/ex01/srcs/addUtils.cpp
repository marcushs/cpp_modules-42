/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addUtils.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 09:46:28 by hleung            #+#    #+#             */
/*   Updated: 2023/11/15 17:08:35 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.hpp"
#include "../include/PhoneBook.hpp"
#include "../include/Contact.hpp"

int	isValidPhone(std::string str)
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

int	hasNonPrintable(std::string str)
{
	for(std::string::iterator i = str.begin(); i != str.end(); ++i)
		if (!isprint(*i))
			return (1);
	return (0);
}
