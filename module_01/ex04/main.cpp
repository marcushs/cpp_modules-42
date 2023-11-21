/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 11:30:24 by hleung            #+#    #+#             */
/*   Updated: 2023/11/21 10:25:26 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

static char	*readFileString(char *inFile);
static std::string	replaceOccurrence(char *buf, std::string occ, std::string rep);

int	main(int argc, char **argv)
{
	if (argc == 4)
	{
		std::string	inFileName = argv[1];
		std::string	occ = argv[2];
		std::string	rep = argv[3];
		
		char	*content = readFileString(argv[1]);
		if (!content)
			return (1);

		std::string cpy = replaceOccurrence(content, occ, rep);

		std::ofstream	ofs(inFileName.append(".replace").c_str());
		ofs.write(cpy.c_str(),cpy.length());
		ofs.close();

		delete [] content;
		return (0);
	}

	std::cout << "Usage: sed <filename> <string1> <string2>" << std::endl;
	return (0);
}

static std::string	replaceOccurrence(char *buf, std::string occ, std::string rep)
{
	std::string	cpy = buf;
	size_t		occLen = occ.length();
	size_t		repLen = rep.length();
	size_t		pos = cpy.find(occ);

	while (pos != std::string::npos)
	{
		cpy.erase(pos, occLen);
		cpy.insert(pos, rep);
		pos = cpy.find(occ, pos + repLen);
	}
	return (cpy);
}

static char	*readFileString(char *inFile)
{
	std::ifstream	ifs(inFile);

	if (!ifs.is_open())
	{
		std::cout << "Error opening " << inFile << std::endl;
		return (NULL);
	}
	
	ifs.seekg (0, ifs.end);
	int length = ifs.tellg();
	ifs.seekg (0, ifs.beg);

	char *str = new char [length + 1];
	ifs.read (str,length);
	str[length] = '\0';
	ifs.close();

	return (str);
}
