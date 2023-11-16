/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 17:36:02 by hleung            #+#    #+#             */
/*   Updated: 2023/11/16 07:04:58 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for (int i = 1; i < argc && argc > 1; i++)
	{
		std::string str = argv[i];
		for (std::string::iterator i = str.begin(); i != str.end(); ++i)
			*i = std::toupper(*i);
		std::cout << str;
	}
	std::cout << std::endl;
}
