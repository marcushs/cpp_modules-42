/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 11:30:24 by hleung            #+#    #+#             */
/*   Updated: 2023/11/19 08:17:31 by hleung           ###   ########.fr       */
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
		std::ifstream	ifs(args[0].c_str());
		if (!ifs.is_open())
		{
			std::cout << "Error opening " << args[0] << std::endl;
			return (1);
		}
		std::ofstream	ofs(args[0].append(".replace").c_str());
		char c;
		while (ifs.get(c))
		{
			ofs << c;
		}
		ifs.close();
		// std::cout << args[0].append(".replace") << std::endl;
		ofs.close();
		// ifs.close();
		return (0);
	}
	std::cout << "Usage: sed <filename> <string1> <string2>" << std::endl;
	return (0);

}
