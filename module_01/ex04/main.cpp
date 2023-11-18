/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 11:30:24 by hleung            #+#    #+#             */
/*   Updated: 2023/11/18 11:57:33 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int	main(int argc, char **argv)
{
	if (argc == 4)
	{
		std::string	args[3];
		for (int i = 0; i < 3; i++)
			args[i] = argv[i + 1];
		// std::ifstream	ifs(args[0]);
		std::cout << args[0].append(".replace") << std::endl;
		// std::ofstream	ofs();
		// ifs.close();
		return (0);
	}
	std::cout << "Usage: sed <filename> <string1> <string2>" << std::endl;
	return (0);

}
