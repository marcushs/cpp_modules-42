/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 11:30:24 by hleung            #+#    #+#             */
/*   Updated: 2023/11/27 13:54:25 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

static int	writeStringToFile(std::ofstream &ofs, const std::string &cpy);
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
			return (2);

		std::string cpy = replaceOccurrence(content, occ, rep);

		std::ofstream	ofs(inFileName.append(".replace").c_str());
		if (!ofs.good())
		{
			std::cerr << "Error opening outfile" << std::endl;
			delete [] content;
			return (3);
		}

		if (writeStringToFile(ofs, cpy) == -1)
		{
			delete [] content;
			ofs.close();
			return (4);
		}

		delete [] content;
		ofs.close();
		return (0);
	}

	std::cerr << "Usage: sed <filename> <string1> <string2>" << std::endl;
	return (1);
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
		std::cerr << "Error opening " << inFile << std::endl;
		return (NULL);
	}
	
	ifs.seekg (0, ifs.end);
	int length = ifs.tellg();
	ifs.seekg (0, ifs.beg);

	char *str = new char [length + 1];
	ifs.read (str, length);
	if (!ifs)
	{
		std::cerr << "Error: only " << ifs.gcount() << " have been read";
		return (NULL);
	}
	str[length] = '\0';
	ifs.close();
	return (str);
}

static int	writeStringToFile(std::ofstream &ofs, const std::string &cpy)
{
	ofs.write(cpy.c_str(), cpy.length());
	if (!ofs)
	{
		std::cerr << "Error during write operation" << std::endl;
		return (-1);
	}
	return (0);
}
