/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 18:43:08 by hleung            #+#    #+#             */
/*   Updated: 2023/12/27 20:45:33 by hleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarConverter.hpp"
#include <iostream>
#include <iomanip>
#include <limits>
#include <climits>
#include <cmath>
#include <cstdlib>

static int	trimWhitespace(std::string &str);
static unsigned int	detectType(std::string &str);
static void	print(const std::string &str, const unsigned int &type);
static void	printChar(const char &c, const double &value);
static void	printInt(const int &i, const double &value);
static void	printFloat(const float &f);
static void	printDouble(const double &d);

/*------------------------------- Constructors -------------------------------*/

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &src) {*this = src;}

/*-------------------------------- Destructor --------------------------------*/

ScalarConverter::~ScalarConverter() {}

/*--------------------------------- Overload ---------------------------------*/

ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &rhs) {static_cast<void>(rhs); return *this;}

/*----------------------------- Member Functions -----------------------------*/

/* Either const std::string & or just std::string*/
void	ScalarConverter::convert(std::string s)
{
	if (s.empty() || trimWhitespace(s) == 1)
	{
		std::cout << "Error: Empty string" << std::endl;
		return ;
	}
	unsigned int	type = detectType(s);
	if (type == 9)
	{
		std::cout << "Error: Invalid Input" << std::endl;
		return ;
	}
	print(s, type);
}

static int	trimWhitespace(std::string &str)
{
	const std::string	whiteSpaceChars = " \t\n\r\f\v";

	if (str.length() <= 1)
		return (0);
	size_t	start = str.find_first_not_of(whiteSpaceChars);
	if (start == str.npos)
		return (1);
	size_t	end = str.find_last_not_of(whiteSpaceChars);
	str = str.substr(start, end - start + 1);
	return (0);
}

static unsigned int	detectType(std::string &str)
{
	const std::string	digits = "0123456789";
	
	if (str.length() == 1 && isprint(str[0]) && !isdigit(str[0]))
		return CHAR;
	if (str.find_first_not_of(digits) == str.npos || 
	((str[0] == '-' || str[0] == '+') && str.find_first_not_of(digits, 1) == str.npos))
		return INT;
	if ((str.find_first_not_of(digits) == str.find('.') && str.find_last_not_of(digits) == str.find('.')) ||
	((str[0] == '-' || str[0] == '+') && str.find_first_not_of(digits, 1) == str.find('.') && 
	str.find_last_not_of(digits) == str.find('.')) || 
	!str.compare("inf") || !str.compare("+inf") || !str.compare("-inf") || !str.compare("nan"))
		return DOUBLE;
	if ((str.find_first_not_of(digits) == str.find('.') && str.find_last_not_of(digits, str.length() - 2) == str.find('.') && 
	str[str.length() - 1] == 'f') || ((str[0] == '-' || str[0] == '+') && str.find_first_not_of(digits, 1) == str.find('.') && 
	str.find_last_not_of(digits, str.length() - 2) == str.find('.') && str[str.length() - 1] == 'f') || 
	!str.compare("inff") || !str.compare("+inff") || !str.compare("-inff") || !str.compare("nanf"))
		return FLOAT;
	return (9);
}

static void	print(const std::string &str, const unsigned int &type)
{
	double value = strtod(str.c_str(), NULL);
	
	switch (type)
	{
	
	case CHAR:
		{
			std::cout << "Type    : " << "CHAR" << std::endl;
			char	c = str[0];
			printChar(c, value);
			printInt(static_cast<int>(c), value);
			printFloat(static_cast<float>(c));
			printDouble(static_cast<double>(c));
			break;
		}

	case INT:
		{
			std::cout << "Type    : " << "INT" << std::endl;
			int	i = static_cast<int>(value);
			printChar(static_cast<char>(i), i);
			printInt(i, value);
			if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
			{
				printFloat(static_cast<float>(value));
				printDouble(value);
				break;
			}
			printFloat(static_cast<float>(i));
			printDouble(static_cast<double>(i));
			break;
		}

	case FLOAT:
		{
			std::cout << "Type    : " << "FLOAT" << std::endl;
			float	f = static_cast<float>(value);
			printChar(static_cast<char>(f), value);
			printInt(static_cast<int>(f), value);
			printFloat(f);
			if (value < std::numeric_limits<float>::min() || value > std::numeric_limits<float>::max())
				printDouble(value);
			else
				printDouble(static_cast<double>(f));
			break;
		}

	case DOUBLE:
		{
			std::cout << "Type    : " << "DOUBLE" << std::endl;
			printChar(static_cast<char>(value), value);
			printInt(static_cast<int>(value), value);
			printFloat(static_cast<float>(value));
			printDouble(value);
			break;
		}
		
	default:
		{
			std::cout << "Error: no corresponding type" << std::endl;
			break;
		}
	}
}

static void	printChar(const char &c, const double &value)
{
	std::cout << "char    : ";
	if (value < CHAR_MIN || value > CHAR_MAX || std::isinf(value) || std::isnan(value))
	{
		std::cout << "Impossible" << std::endl;
		return ;
	}
	if (isprint(c))
		std::cout << "'" << c << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
}

static void	printInt(const int &i, const double &value)
{
	std::cout << "int     : ";
	if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max() 
	|| std::isinf(value) || std::isnan(value))
	{
		std::cout << "Impossible" << std::endl;
		return ;
	}
	std::cout << i << std::endl;
}

static void	printFloat(const float &f)
{
	std::cout << "float   : ";

	if (static_cast<int>(f) == f)
	{
		std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;
		return ;
	}
	std::cout << f << "f" << std::endl;
}

static void	printDouble(const double &d)
{
	std::cout << "double  : ";

	if (static_cast<int>(d) == d)
	{
		std::cout << std::fixed << std::setprecision(1) << d << std::endl;
		return ;
	}
	std::cout << d << std::endl;
}
