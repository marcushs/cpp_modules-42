/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 17:36:02 by hleung            #+#    #+#             */
/*   Updated: 2023/11/12 17:36:34 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for (int i = 1; i < argc && argc > 1; i++)
	{
		for (size_t j = 0; argv[i][j]; j++)
			argv[i][j] = std::toupper(argv[i][j]);
		std::cout << argv[i];
	}
	std::cout << std::endl;
}
