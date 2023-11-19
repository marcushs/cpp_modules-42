/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 11:30:24 by hleung            #+#    #+#             */
/*   Updated: 2023/11/19 12:06:12 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

static std::string	replaceOccurrence(char *buf, std::string occ, std::string rep);

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
		ifs.seekg (0, ifs.end);
		int length = ifs.tellg();
		ifs.seekg (0, ifs.beg);

		char * buffer = new char [length];

		// read data as a block:
		ifs.read (buffer,length);
		ifs.close();
		std::string cpy = replaceOccurrence(buffer, args[1], args[2]);
		ofs.write(cpy.c_str(),length);
		ofs.close();
		return (0);
	}

	std::cout << "Usage: sed <filename> <string1> <string2>" << std::endl;
	return (0);
}

static std::string	replaceOccurrence(char *buf, std::string occ, std::string rep)
{
	std::string cpy = buf;
	size_t		pos = cpy.find(occ);
	int			nbOcc = 0;

	while (pos != std::string::npos)
	{
		nbOcc++;
		cpy.erase(pos, occ.length());
		cpy.insert(pos, rep);
		pos = cpy.find(occ, pos + rep.length());
	}
	
	int	lenDiff = ((int)occ.length() - (int)rep.length()) * nbOcc;
	if (lenDiff < 0)
		lenDiff *= -1;
	cpy.resize(lenDiff);
	return (cpy);
}
